#ifndef WINDOW_SETTINGS_H
#define WINDOW_SETTINGS_H

struct WindowSettings {
    bool wireframeMode;
    int screenWidth;
    int screenHeight;
    const char* title;

    WindowSettings(int screenWidth, int screenHeight, const char* title):
    wireframeMode(false),
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    title(title){}
};

#endif //WINDOW_SETTINGS_H