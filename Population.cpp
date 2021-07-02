#include "Population.h"

Population::Population() {
	if (!m_font.loadFromFile("Font/OpenSans-Regular.ttf")) {
		std::cout << "ERROR" << std::endl;
	}
	m_pop.setFont(m_font);
	m_pop.setFillColor(sf::Color::Green);
	m_pop.setCharacterSize(24);
	m_pop.setPosition(sf::Vector2f(5, 30));
	m_pop.setString("Population: ");
}

void Population::draw(sf::RenderWindow& window) {
	window.draw(m_pop);
}

void Population::update(int pop_s) {
	m_pop.setString("Population: " + std::string(std::to_string(pop_s)));
}