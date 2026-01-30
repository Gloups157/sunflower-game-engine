#include "../include/application/core/Application.h"
#include "application/layers/engine/core/Engine.h"

int main() {
    Application application;
    application.addLayer<Engine>();
    application.run();
    application.quit();
    return 0;
}
