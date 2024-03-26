#include "source/Global.hpp"
#include "source/ExitCodes.hpp"
class Debug {
public:
    // UPDATE FUNCTION FOR DEBUG WINDOW
    static EXIT_CODE Update() {
        if (!GLOBAL::debug.window.isOpen()) return EXIT_CODE::WINDOW_IS_NOT_OPEN;
        if (GLOBAL::debug.window.isOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && GLOBAL::debug.window.isOpen()) GLOBAL::debug.window.close();
            if (!GLOBAL::debug.window.hasFocus()) return EXIT_CODE::TERMINATED;
            GLOBAL::debug.window.clear(sf::Color::Black);
            GLOBAL::debug.window.display();
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
};