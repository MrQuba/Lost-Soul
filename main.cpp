#include <SFML/Graphics.hpp>
#include "source/Window.hpp"
#include "source/Entity.hpp"
#include "source/Event.hpp"
#include "source/ExitCodes.hpp"
#include "source/Colors.hpp"
#include "source/Constants.hpp"
#include "source/Global.hpp"
#include "source/CollisionEntity.hpp"
#include "source/Minimap.hpp"
#include "source/Draw.hpp"
#include "source/Debug.hpp"
#include "source/Update.hpp"
#include "source/Ground.hpp"
#include "source/Scythe.hpp"
#include "source/Weapon.hpp"
#include "source/Operator.hpp"
#include "source/Player.hpp"
#include "source/TargetDummy.hpp"
#include <list>
#include <set>



int main() {
    //GLOBAL::game.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Lost Soul");
    // Entities declarations
    Player player("assets/entites.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1, 1));
    TargetDummy dummy("assets/entites.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1, 1));
    GLOBAL::PLAYER_PTR = &player;
    Scythe scythe("assets/items.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1.5, 3.75));
    // Declaration & initialization of set containing every entity currently visible
    std::set<Entity*> SET_OF_ENTITIES;
    GLOBAL::ENTITIES_SET_POINTER = &SET_OF_ENTITIES;
    std::set<CollisionEntity*> SET_OF_COLLISION_ENTITIES;
    SET_OF_ENTITIES.insert(&player);
    SET_OF_ENTITIES.insert(&scythe);
    SET_OF_ENTITIES.insert(&dummy);
    // Closing not needed windows
    GLOBAL::debug.window.close();
    GLOBAL::op.window.close();
    // Ground initialization
    Ground::init();
  
    GLOBAL::debug.window.setActive(true);
    GLOBAL::op.window.setActive(true);
    GLOBAL::game.window.setActive(true);
    while (GLOBAL::game.window.isOpen()) {
      //  if (!GLOBAL::game.window.hasFocus()) continue;
        // IF DOES NOT HAVE FOCUS SKIP
        GLOBAL::game.window.clear(Colour::getColour(COLOUR::BASE_SKY));

        // UPDATE
        GLOBAL::EVENT.Loop(GLOBAL::game.window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && !GLOBAL::debug.window.isOpen()) GLOBAL::debug.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Debug Mode");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !GLOBAL::op.window.isOpen()) GLOBAL::op.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Operator Mode"); 

        if (GLOBAL::op.window.isOpen())
        Operator::Update();
        if(GLOBAL::debug.window.isOpen())
        Debug::Update();

        GLOBAL::PLAYER_POSITION = player.position();
        player.Update(GLOBAL::game.window);

        Update::Entities(SET_OF_ENTITIES);

        // DRAW
        Ground::draw(GLOBAL::game.window);
        Draw::Entities(SET_OF_ENTITIES);
        player.drawHUDElements(GLOBAL::game.window);
        GLOBAL::game.window.display();
    }
    GLOBAL::debug.window.close();
    GLOBAL::op.window.close();
    return 1;
}