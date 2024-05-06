#include <SFML/Graphics.hpp>
#pragma once
class Event {
private:
    sf::Event event;
public:
    sf::Event getEvent() {
        return event;
    }
    void Loop(sf::RenderWindow& window) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    }

};