#include <iostream>
#include <Window/Window.hpp>
#include <RenderEngine/Loader.hpp>
#include <RenderEngine/Renderer.hpp>
#include <RenderEngine/RawModel.hpp>
#include <Shader/StaticShader.hpp>

std::vector<float> vertices = {
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f
};

std::vector<unsigned int> indices = {
    0,1,3,
    3,2,1
};
void checkGLError(const char* file, int line) {
    GLenum error = glGetError();
    while (error != GL_NO_ERROR) {
        const char* errorString = reinterpret_cast<const char*>(glewGetErrorString(error));
        std::cerr << "OpenGL error in file '" << file << "' at line " << line << ": " << errorString << std::endl;
        error = glGetError();
    }
}

#define CHECK_GL_ERROR() checkGLError(__FILE__, __LINE__)
int main(int argc, char** argv) {
    const int WIDTH = 1080;
    const int HEIGHT = 720;
    
    kaim::Window* window = new kaim::Window("OpenGL Engine", WIDTH, HEIGHT);
    Loader* loader = new Loader();
    Renderer* renderer = new Renderer();

    RawModel* squareModel = loader->LoadToVAO(vertices, indices);

    StaticShader* staticShader = new StaticShader("./Assets/Shaders/Model.vert", "./Assets/Shaders/Model.frag");
    
    SDL_Event evt;

    while(window->IsOpen()) {
        while(SDL_PollEvent(&evt)) { if(evt.type == SDL_QUIT) { window->Close(); } }
        window->Update(0.1f, 0.7f,1.0f,1.0f);

        staticShader->use();

        renderer->Render(squareModel);

        window->Render();
    }

    delete staticShader;
    delete loader;
    delete renderer;
    delete window;

    return 0;
}