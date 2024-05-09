#include <SFML/Graphics.hpp>
#include <set>
#include "ExitCodes.hpp"
#include "Entity.hpp"
#include "Global.hpp"
#include "Constants.hpp"
#include "EntityManager.hpp"
#pragma once
class Update {
public:
    // if SET_OF_ENTITIES (SOF) is not empty
    // iterates over it and draws entities using polymorphic pointer
    static EXIT_CODE Entities() {
        if (GLOBAL::ENTITIES_SET_POINTER->empty()) return EXIT_CODE::SET_IS_EMPTY;
        std::set<Entity*> entitiesToRemove;
        for (Entity* ent_ptr : *GLOBAL::ENTITIES_SET_POINTER) {
            if (ent_ptr->affectedByGravity()) {
                ent_ptr->setPosition(sf::Vector2f(ent_ptr->position().x, ent_ptr->position().y + (10 * CONSTANTS::GRAVITY)));
            }
            ent_ptr->Update(GLOBAL::game.window);
            if (ent_ptr->isDead() && ent_ptr->isMortal()) {
                entitiesToRemove.insert(ent_ptr);
                
            }
        }
        for (Entity* entity : entitiesToRemove) {
            GLOBAL::ENTITIES_SET_POINTER->erase(entity);
            delete entity; 
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
};
