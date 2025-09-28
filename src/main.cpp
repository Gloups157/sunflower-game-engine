#include "engine/core/Engine.h"

int main() {
    Engine engine(1920, 1080, "XP");
    engine.run();
    engine.quit();
    return 0;
}
