#include "Cells.h"

void Cells::draw(sf::RenderWindow& window, int x, int y)
{
	m_cell.setSize(sf::Vector2f(m_s, m_s));
	m_cell.setPosition(sf::Vector2f(x, y));
	window.draw(m_cell);
}

void Cells::change_color(sf::RenderWindow& window, sf::Color color)
{
	m_cell.setFillColor(color);
	window.draw(m_cell);
}
