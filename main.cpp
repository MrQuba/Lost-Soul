#include <SFML/Graphics.hpp>
#include "source/Effects.hpp"
#include "source/Window.hpp"
#include "source/Entity.hpp"
#include "source/Event.hpp"
#include "source/ExitCodes.hpp"
#include "source/Colors.hpp"
#include "source/Constants.hpp"
#include "source/Global.hpp"
#include "source/Draw.hpp"
#include "source/Update.hpp"
#include "source/Ground.hpp"
#include "source/Scythe.hpp"
#include "source/Weapon.hpp"
#include "source/Player.hpp"
#include "source/TargetDummy.hpp"
#include "source/TownGuard.hpp"
#include "source/EntityManager.hpp"
#include <list>
#include <set>

int main() {
    // Game window initialization
    GLOBAL::game.window.create(sf::VideoMode(CONSTANTS::WINDOW_SIZE_X, CONSTANTS::WINDOW_SIZE_Y), "Lost Soul");
    GLOBAL::game.window.setFramerateLimit(CONSTANTS::FRAMERATE);
    // Entities declarations
    Entity* player = new Player("assets/entites.png", sf::IntRect(15, 0, 13, 24), sf::Vector2f(2.5f, 2.5f));
    Entity* guard = new TownGuard("assets/entites.png", sf::IntRect(0, 0, 15, 16), sf::Vector2f(1, 1.5f), 60);
    guard->setPosition(sf::Vector2f(1000, 500));
    GLOBAL::PLAYER_PTR = player;
    Item* scythe = new Scythe("assets/items.png", sf::IntRect(15, 0, 21, 27), sf::Vector2f(-2.f, 2.25f));
    GLOBAL::ItemID[ITEMS::SCYTHE] = scythe;
    // Declaration & initialization of set containing every entity currently visible 
    std::set<Entity*> SET_OF_ENTITIES;
    GLOBAL::ENTITIES_SET_POINTER = &SET_OF_ENTITIES;
    SET_OF_ENTITIES.insert(player);
    SET_OF_ENTITIES.insert(scythe);
    SET_OF_ENTITIES.insert(guard);
    // Ground initialization
    Ground::init(GLOBAL::game.window);
    while (GLOBAL::game.window.isOpen()) {
        GLOBAL::game.window.clear(Colour::getColour(COLOUR::BASE_SKY));

        // UPDATE
        GLOBAL::EVENT.Loop(GLOBAL::game.window);

        GLOBAL::PLAYER_POSITION = player->position();
        Update::Entities();
        // DRAW
        Ground::draw(GLOBAL::game.window);
        Draw::Entities(SET_OF_ENTITIES);
        GLOBAL::game.window.display();
    }
    for (auto entity : SET_OF_ENTITIES) {
        delete entity;
    }
    return 1;
}