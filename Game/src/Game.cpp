#include <iostream>
#include <Window/Window.hpp>
#include <RenderEngine/Loader.hpp>
#include <RenderEngine/Renderer.hpp>
#include <Models/RawModel.hpp>
#include <Shader/StaticShader.hpp>
#include <Textures/ModelTexture.hpp>
#include <Models/TexturedModel.hpp>
#include <Entity/Entity.hpp>
#include <Entity/Camera.hpp>

std::vector<float> vertices = {
    -0.5f,0.5f,-0.5f,	
				-0.5f,-0.5f,-0.5f,	
				0.5f,-0.5f,-0.5f,	
				0.5f,0.5f,-0.5f,		
				
				-0.5f,0.5f,0.5f,	
				-0.5f,-0.5f,0.5f,	
				0.5f,-0.5f,0.5f,	
				0.5f,0.5f,0.5f,
				
				0.5f,0.5f,-0.5f,	
				0.5f,-0.5f,-0.5f,	
				0.5f,-0.5f,0.5f,	
				0.5f,0.5f,0.5f,
				
				-0.5f,0.5f,-0.5f,	
				-0.5f,-0.5f,-0.5f,	
				-0.5f,-0.5f,0.5f,	
				-0.5f,0.5f,0.5f,
				
				-0.5f,0.5f,0.5f,
				-0.5f,0.5f,-0.5f,
				0.5f,0.5f,-0.5f,
				0.5f,0.5f,0.5f,
				
				-0.5f,-0.5f,0.5f,
				-0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,0.5f
};


std::vector<unsigned int> indices = {
    0,1,3,	
				3,1,2,	
				4,5,7,
				7,5,6,
				8,9,11,
				11,9,10,
				12,13,15,
				15,13,14,	
				16,17,19,
				19,17,18,
				20,21,23,
				23,21,22
};

std::vector<float> textureCoords = {
    0,0,
				0,1,
				1,1,
				1,0,			
				0,0,
				0,1,
				1,1,
				1,0,			
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0
};

int main(int argc, char** argv) {
    const int WIDTH = 1080;
    const int HEIGHT = 720;
    
    kaim::Window* window = new kaim::Window("OpenGL Engine", WIDTH, HEIGHT);
    Loader* loader = new Loader();
    StaticShader* staticShader = new StaticShader("./Assets/Shaders/Model.vert", "./Assets/Shaders/Model.frag");
    Renderer* renderer = new Renderer(staticShader, WIDTH / HEIGHT);

    RawModel* squareModel = loader->LoadToVAO(vertices, textureCoords, indices);
    ModelTexture* modelTexture = new ModelTexture(loader->LoadTexture("Family.png"));
    TexturedModel* model = new TexturedModel(squareModel, modelTexture);
    Camera* camera = new Camera();

    Entity* entity = new Entity(model, glm::vec3(0.0f,0.0f,-1.0f));

    SDL_Event evt;

    while(window->IsOpen()) {
        while(SDL_PollEvent(&evt)) { 
            if(evt.type == SDL_QUIT) { window->Close(); } 
            if (evt.type == SDL_MOUSEMOTION) {
                float xOffset, yOffset;
                xOffset = evt.motion.xrel;
                yOffset = evt.motion.yrel;

                camera->ProcessMouseMovement(xOffset, -yOffset);
            }
        }
        window->Update(0.1f, 0.7f,1.0f,1.0f);
        camera->ProcessKeyboard(window->DeltaTime());
        entity->IncreaseRotation(SDL_GetTicks64() * 0.0005, glm::vec3(1.0f,1.0f,1.0f));

        staticShader->use();
        staticShader->LoadViewMatrix(camera);

        renderer->Render(entity, staticShader);

        window->Render();
    }

    delete staticShader;
    delete loader;
    delete renderer;
    delete window;
    delete modelTexture;
    delete model;
    delete entity;
    delete camera;

    return 0;
}