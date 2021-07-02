#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include "Cells.h"

class Field
{
public:
	Field();
	void draw(sf::RenderWindow& window);
	void cell_start(sf::RenderWindow& window, int p);
	void update(sf::RenderWindow& window);
	int pop_update();
private:
	std::vector<std::vector<Cells>> m_field;
	void cell_update(int nn, int i, int j);
};

