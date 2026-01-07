#include "engine/core/Engine.h"

int main() {
    Engine engine(1920, 1080, "Visuel");
    engine.run();
    engine.quit();
    return 0;
}
