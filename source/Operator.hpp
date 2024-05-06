#include <SFML/Graphics.hpp>
#include <set>
#include "ExitCodes.hpp"
#include "Global.hpp"
#include "ButtonChangingValue.hpp"
#include "Draw.hpp"
#include "Pointers.hpp"
#pragma once
class Operator {
public:
        static void init() {
    }
    // UPDATE FUNCTION FOR OPERATOR WINDOW
        static EXIT_CODE Update() {
            std::cout << POINTER::PLAYER_SPEED_X << std::endl;
            ButtonChangingValue<float> speedIncrement(&POINTER::PLAYER_SPEED_X, 0.3f, "assets/ui.png", sf::IntRect(0,0,48,16), sf::Vector2f(1,1));
            if (!GLOBAL::op.window.isOpen()) return EXIT_CODE::WINDOW_IS_NOT_OPEN;
            while (GLOBAL::op.window.isOpen() && GLOBAL::op.window.hasFocus()) {
                GLOBAL::EVENT.Loop(GLOBAL::op.window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && GLOBAL::op.window.isOpen()) GLOBAL::op.window.close();

                speedIncrement.Update(GLOBAL::op.window);


                GLOBAL::op.window.clear(sf::Color::Black);
                speedIncrement.draw(GLOBAL::op.window);
                GLOBAL::op.window.display();
            }
            return EXIT_CODE::OPERATION_SUCCESFUL;
        }

    static void Close() {
        GLOBAL::op.window.close();
    }
    private:
};