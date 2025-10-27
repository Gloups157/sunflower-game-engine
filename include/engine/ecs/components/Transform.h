#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Position.h"
#include "Rotation.h"
#include "Scale.h"

struct Transform {
    Position position;
    Rotation rotation;
    Scale scale;
};

#endif //TRANSFORM_H