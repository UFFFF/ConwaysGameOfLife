#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Generation
{
public:
	Generation();
	void draw(sf::RenderWindow& window);
	void update(int gen);
private:
	sf::Font m_font;
	sf::Text m_gen;
};

