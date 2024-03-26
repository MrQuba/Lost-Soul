#include <SFML/Graphics.hpp>
#include <set>
#include "ExitCodes.hpp"
#include "Entity.hpp"
#include "CollisionEntity.hpp"
#include "Global.hpp"
#include "Constants.hpp"
#pragma once
class Update {
public:
    // if SET_OF_ENTITIES (SOF) is not empty
    // iterates over it and draws entities using polymorphic pointer
    static EXIT_CODE Entities(std::set<Entity*> SOE) {
        if (SOE.empty()) return EXIT_CODE::SET_IS_EMPTY;
        for (Entity* ent_ptr : SOE) {
            if (ent_ptr->affectedByGravity()) {
                ent_ptr->setPosition(sf::Vector2f(ent_ptr->position().x, ent_ptr->position().y + CONSTANTS::GRAVITY));
            }
            ent_ptr->Update(GLOBAL::game.window);
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
    static EXIT_CODE CollisionEntities(std::set<CollisionEntity*> SOCE, sf::Sprite player) {
        if (SOCE.empty()) return EXIT_CODE::SET_IS_EMPTY;
        for (CollisionEntity* ent_ptr : SOCE) {
            ent_ptr->Update(GLOBAL::game.window, player);
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
};
