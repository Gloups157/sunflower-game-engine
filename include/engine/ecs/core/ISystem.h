#ifndef I_SYSTEM_H
#define I_SYSTEM_H

class ISystem {
public:
    virtual ~ISystem() = 0;
    virtual void initialize() = 0;
    virtual void start() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual void update() = 0;
    virtual void fixedUpdate() = 0;
    virtual void lateUpdate() = 0;
};

#endif //I_SYSTEM_H