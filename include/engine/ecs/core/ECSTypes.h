#ifndef ECS_TYPES_H
#define ECS_TYPES_H

#pragma once

#include <bitset>

const unsigned int MAX_ENTITIES = 100000;
const unsigned short MAX_COMPONENTS = 1024;

using Entity = unsigned int;
using Component = unsigned short;
using Index = size_t;
using Signature = std::bitset<MAX_COMPONENTS>;
using VoidCallback = std::function<void()>;

#endif //ECS_TYPES_H