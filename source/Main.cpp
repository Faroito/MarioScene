//
// Created by Timothée Couble on 17/10/2019.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "MarioScene.hpp"

/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF);

_CrtDumpMemoryLeaks();
*/

int main(int argc, const char ** argv) {
    stbi_set_flip_vertically_on_load(true);
    scene::MarioScene app;

    app.start();
    return 0;
}
