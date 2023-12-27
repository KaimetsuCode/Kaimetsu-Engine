#pragma once

// std libs
#include <set>
#include <random>
#include <limits>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>

// SDL2 Libries
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

#include <GL/glew.h>

// Export API
#ifdef KAIM_EXPORT
    #ifdef _MSC_VER
        #define KAIM_API __declspec(dllexport)
    #else
        #define KAIM_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define KAIM_API __declspec(dllimport)
    #else
        #define KAIM_API
    #endif
#endif
