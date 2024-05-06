#include <SFML/Graphics.hpp>
#include "ExitCodes.hpp"
#include "Global.hpp"
#include "Button.hpp"
#pragma once
class Debug {
public:
  //static std::set<Entity*> SET_OF_ENTITIES;
    static EXIT_CODE Update() {
        if (!GLOBAL::debug.window.isOpen()) return EXIT_CODE::WINDOW_IS_NOT_OPEN;
        if (GLOBAL::debug.window.isOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && GLOBAL::debug.window.isOpen()) GLOBAL::debug.window.close();
            if (!GLOBAL::debug.window.hasFocus()) return EXIT_CODE::TERMINATED;

            GLOBAL::debug.window.clear(sf::Color::Black);
            //Draw::Entities(SET_OF_ENTITIES);
            GLOBAL::debug.window.display();
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
    static EXIT_CODE Close() {
        GLOBAL::debug.window.close();
        return EXIT_CODE::TERMINATED;
    }
};