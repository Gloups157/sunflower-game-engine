#ifndef I_COMPONENT_SPARSE_SET_H
#define I_COMPONENT_SPARSE_SET_H

#include "ECSTypes.h"

class IComponentSparseSet {
public:
    virtual ~IComponentSparseSet() = default;
    virtual void removeComponent(Entity entity) = 0;
};

#endif //I_COMPONENT_SPARSE_SET_H