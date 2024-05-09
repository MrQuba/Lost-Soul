#include "Global.hpp"
#include "Items.hpp"
#include "Slots.hpp"
#pragma once

class Inventory {
public:
	void equipItem(ITEMS item, SLOTS slot) {
		switch (slot) {
		case SLOTS::HAND:
			this->hand = item;
			this->Inventory.insert(item);
			break;
		}
	}
	void updateEquipped(sf::RenderWindow& window, bool& facesRight, bool changedDir) {
		for (auto item : this->Inventory) {
			std::map<ITEMS, Item*>::iterator it = GLOBAL::ItemID.begin();
			while (it != GLOBAL::ItemID.end()) {
				if (it->first != item) continue;
				it->second->isEquipped = true;
				it->second->changeDirection(facesRight, changedDir);
				it->second->Update(window);
				break;
			}
		}
	}
private:
	std::set<ITEMS> Inventory;
	ITEMS hand;
};