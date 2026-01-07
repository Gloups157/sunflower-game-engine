#ifndef A_WINDOW_H
#define A_WINDOW_H

#include "WindowSettings.h"
#include "../input/EKey.h"

class AWindow {
public:
    virtual ~AWindow() = default;
    virtual void initialize() = 0;
    virtual void clear() = 0;
    virtual void draw() = 0;
    virtual void quit() = 0;
    virtual bool isActive() = 0;
    virtual void closeCallback(EKey key) = 0;
    virtual void polygonModeCallback(EKey key) = 0;
    virtual void* getNative() = 0;
    int getScreenWidth() const {
        return windowSettings->screenWidth;
    }
    int getScreenHeight() const {
        return windowSettings->screenHeight;
    }
    float getRatio() const {
        return static_cast<float>(windowSettings->screenWidth) / static_cast<float>(windowSettings->screenHeight);
    }
    WindowSettings getWindowSettings() const {
        return *windowSettings;
    }
protected:
    WindowSettings* windowSettings = nullptr;
};

#endif //A_WINDOW_H