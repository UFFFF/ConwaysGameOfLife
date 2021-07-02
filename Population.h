#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field.h"

class Population
{
public:
	Population();
	void draw(sf::RenderWindow& window);
	void update(int pop_s);
private:
	sf::Font m_font;
	sf::Text m_pop;
};

