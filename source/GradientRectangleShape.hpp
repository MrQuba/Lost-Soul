#include <SFML/Graphics.hpp>
#pragma once

class GradientRectangleShape : public sf::RectangleShape {
	void setFillColor(const sf::Color& color, const sf::Color& color2) {

		m_fillColor = color;
		updateFillColors();
	}
	void updateFillColors()
	{
		for (std::size_t i = 0; i < m_vertices.getVertexCount(); ++i)
			m_vertices[i].color = m_fillColor;
	}
};
