#include <SFML/Graphics.hpp>
#include "source/Window.hpp"
#include "source/Player.hpp"
#include "source/Entity.hpp"
#include "source/Event.hpp"
#include "source/ExitCodes.hpp"
#include "source/Colors.hpp"
#include "source/Constants.hpp"
#include "source/Global.hpp"
#include "source/CollisionEntity.hpp"
#include "source/Minimap.hpp"
#include <list>
#include <set>
// UPDATE FUNCTION FOR DEBUG WINDOW
EXIT_CODE static debugUpdate() {
    if (!GLOBAL::debug.window.isOpen()) return EXIT_CODE::WINDOW_IS_NOT_OPEN;
    if (GLOBAL::debug.window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && GLOBAL::debug.window.isOpen()) GLOBAL::debug.window.close();
        if (!GLOBAL::debug.window.hasFocus()) return EXIT_CODE::TERMINATED;
        GLOBAL::debug.window.clear(sf::Color::Black);
        GLOBAL::debug.window.display();
    }
    return EXIT_CODE::OPERATION_SUCCESFUL;
}
// if SET_OF_ENTITIES (SOF) is not empty
// iterates over it and draws entities using polymorphic pointer
static EXIT_CODE draw(std::set<Entity*> SOE) {
    if (SOE.empty()) return EXIT_CODE::SET_IS_EMPTY;
    for (Entity* ent_ptr : SOE) {
        ent_ptr->draw(GLOBAL::game.window);
    }
    return EXIT_CODE::OPERATION_SUCCESFUL;
}
int main() {
    // Entities declarations
    Player player("assets/entites.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1, 1));
    // Declaration & initialization of set containing every entity currently visible
    std::set<Entity*> SET_OF_ENTITIES;
    SET_OF_ENTITIES.insert(&player);
    // Closing not needed windows
    GLOBAL::debug.window.close();  
    GLOBAL::op.window.close();
    while (GLOBAL::game.window.isOpen()) {
        GLOBAL::game.window.clear(Colour::getColour(COLOUR::BASE_SKY));

        GLOBAL::EVENT.Loop(GLOBAL::game.window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && !GLOBAL::debug.window.isOpen()) GLOBAL::debug.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Debug Mode");
        debugUpdate();
        player.Update(GLOBAL::game.window);


        draw(SET_OF_ENTITIES);
        GLOBAL::game.window.display();
    }
    GLOBAL::debug.window.close();
    GLOBAL::op.window.close();
    return 0;
}