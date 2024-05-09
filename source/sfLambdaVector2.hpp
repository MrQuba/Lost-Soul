#include <SFML/Graphics.hpp>
#include <functional>
#pragma once
template <typename T>
class LambdaVector2 : public sf::Vector2<T> {
public:
	/// <summary>
	/// Adds support for creating sf::Vector2 using lambdas
	/// </summary>
	
	//LambdaVector2<T>(std::function<T()> X, std::function<T()> Y): sf::Vector2(X(), Y()) {}
	LambdaVector2<T>(T X, std::function<T()> Y) : sf::Vector2<T>(X, Y()) {}
	LambdaVector2<T>(std::function<T()> X, T Y) : sf::Vector2<T>(X(), Y) {}
	 sf::Vector2<T> return_sfVector2() {
		return sf::Vector2<T>(this->x, this->y);
	}
};