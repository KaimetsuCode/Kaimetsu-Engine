#include "Window.hpp"

namespace kaim {
    Window::Window(std::string title, int width, int height) {
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        this->title = title;
        this->width = width;
        this->height = height;

        std::cout << title << std::endl;

        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        if(window == NULL) {
            std::cout << SDL_GetError() << std::endl;
            std::cout << "? \n"; 
        }
        context = SDL_GL_CreateContext(window);
        if (context == NULL) {
            std::cout << "SDL could not create GL Context" << std::endl;
        }

        glewExperimental = true;
        if (GLEW_OK != glewInit()) std::cout << "Glew could not initalize" << std::endl;

        glViewport(0, 0, width, height);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);

        std::cout << glGetError() << std::endl;

        isRunning = true;
    }

    void Window::Update(float r, float g, float b, float a) {
        Uint64 currentFrame = SDL_GetTicks64();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(r, g, b, a);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cout << "OpenGL Error: " << error << std::endl;
        }
    }

    void Window::Render() {
        SDL_GL_SwapWindow(window);
        GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (status != GL_FRAMEBUFFER_COMPLETE) {
            std::cout << "Framebuffer not complete: " << status << std::endl;
        }
    }

    bool Window::IsOpen() { return isRunning; }
    void Window::Close() {
        isRunning = false;
    }

    Window::~Window() {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }
}