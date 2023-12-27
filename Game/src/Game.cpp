#include <iostream>
#include <Window/Window.hpp>
#include <RenderEngine/Loader.hpp>
#include <RenderEngine/Renderer.hpp>
#include <Models/RawModel.hpp>
#include <Shader/StaticShader.hpp>
#include <Textures/ModelTexture.hpp>
#include <Models/TexturedModel.hpp>

std::vector<float> vertices = {
    0.5f,  0.5f, 0.0f,  
    0.5f, -0.5f, 0.0f,  
    -0.5f, -0.5f, 0.0f, 
    -0.5f,  0.5f, 0.0f
};


std::vector<unsigned int> indices = {
    0, 1, 3, 
    1, 2, 3
};

std::vector<float> textureCoords = {
    0.0f,0.0f,
    0.0f,1.0f,
    1.0f,1.0f,
    1.0f,0.0f
};

int main(int argc, char** argv) {
    const int WIDTH = 1080;
    const int HEIGHT = 720;
    
    kaim::Window* window = new kaim::Window("OpenGL Engine", WIDTH, HEIGHT);
    Loader* loader = new Loader();
    Renderer* renderer = new Renderer();

    RawModel* squareModel = loader->LoadToVAO(vertices, textureCoords, indices);
    ModelTexture* modelTexture = new ModelTexture(loader->LoadTexture("Family.png"));
    TexturedModel* model = new TexturedModel(squareModel, modelTexture);
    StaticShader* staticShader = new StaticShader("./Assets/Shaders/Model.vert", "./Assets/Shaders/Model.frag");
    
    SDL_Event evt;

    while(window->IsOpen()) {
        while(SDL_PollEvent(&evt)) { if(evt.type == SDL_QUIT) { window->Close(); } }
        window->Update(0.1f, 0.7f,1.0f,1.0f);

        staticShader->use();

        renderer->Render(model);

        window->Render();
    }

    delete staticShader;
    delete loader;
    delete renderer;
    delete window;
    delete modelTexture;
    delete model;

    return 0;
}