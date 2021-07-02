#include "Generation.h"

Generation::Generation() {
	if (!m_font.loadFromFile("Font/OpenSans-Regular.ttf")) {
		std::cout << "ERROR" << std::endl;
	}
	m_gen.setFont(m_font);
	m_gen.setFillColor(sf::Color::Green);
	m_gen.setCharacterSize(24);
	m_gen.setPosition(sf::Vector2f(5, 5));
	m_gen.setString("Generation: ");
}

void Generation::draw(sf::RenderWindow& window)
{
	window.draw(m_gen);
}

void Generation::update(int gen)
{
	m_gen.setString("Generation: " + std::string(std::to_string(gen)));
}
