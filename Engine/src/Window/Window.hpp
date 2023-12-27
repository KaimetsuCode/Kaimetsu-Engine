#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
namespace kaim {
    class Window
    {
    private:
        int width, height;
        std::string title;
        SDL_Window* window;
        SDL_GLContext context;
        bool isRunning = false;
        float deltaTime = 0;
        float lastFrame = 0;
    public:
        Window(std::string title, int width, int height);
        void Update(float r, float g, float b, float a);
        void Render();
        void Close();
        bool IsOpen();
        float DeltaTime() { return deltaTime; }
        ~Window();
    };
}