#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <stb/stb_image.h>
#include "tiers/glad/glad.h"

class Texture {
public:
    Texture(char const* filename);
    void use(GLenum layer);
    unsigned int id;
private:


    unsigned int create(char const* filename);
};

#endif //TEXTURE_H