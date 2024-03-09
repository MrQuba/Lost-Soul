#include <SFML/Graphics.hpp>
#include <iostream>
#include "ExitCodes.hpp"
#pragma once

class Shaders {
protected:
	EXIT_CODE loadShader(const std::string filename, sf::Shader& type) const {
		if (!shader.loadFromFile(filename, type)) return EXIT_CODE::FILE_OPENED_SUCCESFULLY;
		return EXIT_CODE::FILE_NOT_DECLARED;
	}
public:
	sf::Shader shader;
	Shaders(std::string filename, sf::Shader type) {
		if (!sf::Shader::isAvailable()) std::cout << "Shaders are not available" << std::endl;
		else {
			loadShader(filename, type);
		}
	}
};