#include <SFML/Graphics.hpp>
#include "source/Effects.hpp"
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
#include "source/TownGuard.hpp"
#include "source/EntityManager.hpp"
#include <list>
#include <set>
void kill(Entity* ent, std::set<Entity*> S) {
    if (ent->isDead()) {
        S.erase(ent);
        //delete ent;
    }
}


int main() {
    // Main window initialization
    GLOBAL::game.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Lost Soul");
    GLOBAL::game.window.setFramerateLimit(CONSTANTS::FRAMERATE);
    //GLOBAL::game.window.create(, "Lost Soul");
    // Entities declarations
    Entity* player = new Player("assets/entites.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1, 1));
    player->addEffect(&Effects::insanity);
    Entity* guard = new TownGuard("assets/entites.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(1, 1.5f), 100);
    GLOBAL::PLAYER_PTR = player;
    Scythe scythe("assets/items.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(2, 2));
    // Declaration & initialization of set containing every entity currently visible
    std::set<Entity*> SET_OF_ENTITIES;
    GLOBAL::ENTITIES_SET_POINTER = &SET_OF_ENTITIES;
    SET_OF_ENTITIES.insert(player);
    SET_OF_ENTITIES.insert(&scythe);
    //SET_OF_ENTITIES.insert(&dummy);
    SET_OF_ENTITIES.insert(guard);
    // Ground initialization
    Ground::init(GLOBAL::game.window);
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

        GLOBAL::PLAYER_POSITION = player->position();
        Update::Entities();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))player->addEffect(&Effects::heal_insanity);
        // DRAW
        Ground::draw(GLOBAL::game.window);
        Draw::Entities(SET_OF_ENTITIES);
        GLOBAL::game.window.display();
    }
    for (auto entity : SET_OF_ENTITIES) {
        delete entity;
    }
    GLOBAL::debug.window.close();
    GLOBAL::op.window.close();
    return 1;
}