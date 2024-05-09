#include <SFML/Graphics.hpp>
#include <set>
#include "ExitCodes.hpp"
#include "Entity.hpp"
#include "Global.hpp"
#pragma once
class Draw {
public:
    // if SET_OF_ENTITIES (SOF) is not empty
    // iterates over it and draws entities using polymorphic pointer
    static EXIT_CODE Entities(std::set<Entity*> SOE) {
        if (SOE.empty()) return EXIT_CODE::SET_IS_EMPTY;
        for (Entity* ent_ptr : SOE) {
            ent_ptr->draw(GLOBAL::game.window);
        }
        return EXIT_CODE::OPERATION_SUCCESFUL;
    }
};
