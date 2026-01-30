#ifndef APPLICATION_LAYER_H
#define APPLICATION_LAYER_H

class ApplicationLayer {
public:
    virtual ~ApplicationLayer() = default;
    virtual void run() = 0;
    virtual void quit() = 0;
    void enable();
    void disable();
    bool isActive() const;

protected:
    bool active = true;
};

#endif //APPLICATION_LAYER_H