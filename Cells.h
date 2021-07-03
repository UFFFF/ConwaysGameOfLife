#pragma once
#include <SFML/Graphics.hpp>

class Cells
{
public:
	void draw(sf::RenderWindow& window, int x, int y);
	void change_color(sf::RenderWindow& window, sf::Color color);
	int m_row, m_column;
	bool live;
	int status;

private:
	int m_s = 10;
	sf::Color color = sf::Color::Black;
	sf::RectangleShape m_cell;

};

