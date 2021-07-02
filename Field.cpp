#include "Field.h"

Field::Field() {
	m_field.resize(100);
	for (auto& e : m_field) {
		e.resize(100);
	}
}

void Field::draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < m_field.size(); i++) {
		for (unsigned int j = 0; j < m_field.at(i).size(); j++) {
			m_field.at(i).at(j).draw(window, i * 10, j * 10);
		}
	}
}

void Field::cell_start(sf::RenderWindow& window, int p)
{
	for (unsigned int i = 0; i < m_field.size(); i++) {
		for (unsigned int j = 0; j < m_field.at(i).size(); j++) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, p);
			if (dis(gen) == 1) {
				m_field.at(i).at(j).live = true;
				m_field.at(i).at(j).change_color(window, sf::Color::White);
				m_field.at(i).at(j).status = 1;
			}
			else {
				m_field.at(i).at(j).live = false;
				m_field.at(i).at(j).change_color(window, sf::Color::Black);
				m_field.at(i).at(j).status = 0;
			}
			m_field.at(i).at(j).m_row = i;
			m_field.at(i).at(j).m_column = j;
		}
	}
}

void Field::update(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < m_field.size(); i++) {
		for (unsigned int j = 0; j < m_field.at(i).size(); j++) {
			if (i != 0 && i != 99 && j != 0 && j != 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(i - 1).at(j + 1).status + m_field.at(i - 1).at(j - 1).status
					+ m_field.at(i + 1).at(j + 1).status + m_field.at(i + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i == 0 && i != 99 && j == 0 && j != 99) {
				int nn = m_field.at(100 - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(100 - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(100 - 1).at(j + 1).status + m_field.at(100 - 1).at(100 - 1).status
					+ m_field.at(i + 1).at(j + 1).status + m_field.at(i + 1).at(100 - 1).status;
				cell_update(nn, i, j);
			}
			else if (i == 0 && i != 99 && j != 0 && j != 99) {
				int nn = m_field.at(100 - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(100 - 1).at(j + 1).status + m_field.at(100 - 1).at(j - 1).status
					+ m_field.at(i + 1).at(j + 1).status + m_field.at(i + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i == 0 && i != 99 && j != 0 && j == 99) {
				int nn = m_field.at(100 - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(-1 + 1).status
					+ m_field.at(100 - 1).at(-1 + 1).status + m_field.at(100 - 1).at(j - 1).status
					+ m_field.at(i + 1).at(-1 + 1).status + m_field.at(i + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i != 0 && i != 99 && j != 0 && j == 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(-1 + 1).status
					+ m_field.at(i - 1).at(-1 + 1).status + m_field.at(i - 1).at(j - 1).status
					+ m_field.at(i + 1).at(-1 + 1).status + m_field.at(i + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i != 0 && i == 99 && j != 0 && j == 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(-1 + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(-1 + 1).status
					+ m_field.at(i - 1).at(-1 + 1).status + m_field.at(i - 1).at(j - 1).status
					+ m_field.at(-1 + 1).at(-1 + 1).status + m_field.at(-1 + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i != 0 && i == 99 && j != 0 && j != 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(-1 + 1).at(j).status
					+ m_field.at(i).at(j - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(i - 1).at(j + 1).status + m_field.at(i - 1).at(j - 1).status
					+ m_field.at(-1 + 1).at(j + 1).status + m_field.at(-1 + 1).at(j - 1).status;
				cell_update(nn, i, j);
			}
			else if (i != 0 && i == 99 && j == 0 && j != 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(-1 + 1).at(j).status
					+ m_field.at(i).at(100 - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(i - 1).at(j + 1).status + m_field.at(i - 1).at(100 - 1).status
					+ m_field.at(-1 + 1).at(j + 1).status + m_field.at(-1 + 1).at(100 - 1).status;
				cell_update(nn, i, j);
			}
			else if (i != 0 && i != 99 && j == 0 && j != 99) {
				int nn = m_field.at(i - 1).at(j).status + m_field.at(i + 1).at(j).status
					+ m_field.at(i).at(100 - 1).status + m_field.at(i).at(j + 1).status
					+ m_field.at(i - 1).at(j + 1).status + m_field.at(i - 1).at(100 - 1).status
					+ m_field.at(i + 1).at(j + 1).status + m_field.at(i + 1).at(100 - 1).status;
				cell_update(nn, i, j);
			}
		}
	}
	for (unsigned int i = 0; i < m_field.size(); i++) {
		for (unsigned int j = 0; j < m_field.at(i).size(); j++) {
			if (m_field.at(i).at(j).live) {
				m_field.at(i).at(j).status = 1;
				m_field.at(i).at(j).change_color(window, sf::Color::White);
			}
			else {
				m_field.at(i).at(j).status = 0;
				m_field.at(i).at(j).change_color(window, sf::Color::Black);
			}
		}
	}
	
}

int Field::pop_update() {
	int pop = 0;
	for (unsigned int i = 0; i < m_field.size(); i++) {
		for (unsigned int j = 0; j < m_field.at(i).size(); j++) {
			if (m_field.at(i).at(j).live) {
				pop++;
			}
		}
	}
	return pop;
}

void Field::cell_update(int nn, int i, int j)
{
	if (nn == 3 && !m_field.at(i).at(j).live) {
		m_field.at(i).at(j).live = true;
	}
	else if (nn < 2 && m_field.at(i).at(j).live) {
		m_field.at(i).at(j).live = false;
	}
	else if (nn > 3 && m_field.at(i).at(j).live) {
		m_field.at(i).at(j).live = false;
	}
	else if (nn == 2 && m_field.at(i).at(j).live) {
		m_field.at(i).at(j).live = true;
	}
	else if (nn == 3 && m_field.at(i).at(j).live) {
		m_field.at(i).at(j).live = true;
	}
}
