#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include "Field.h"
#include "Generation.h"
#include "Population.h"

int input() {
    int p;
    std::cout << "############################################" << std::endl;
    std::cout << "###        Conways Game of Life          ###" << std::endl;
    std::cout << "############################################" << std::endl;
    std::cout << "###   probabilities: 1 == 1/2%           ###" << std::endl;
    std::cout << "###                  2 == 1/3%           ###" << std::endl;
    std::cout << "###                  3 == 1/4%           ###" << std::endl;
    std::cout << "###                  4 == 1/5%           ###" << std::endl;
    std::cout << "###                  n == 1/n+1%         ###" << std::endl;
    std::cout << "############################################" << std::endl;
    std::cout << "set probability: ";
    std::cin >> p;
    return p;
}

bool q() {
    std::string a;
    std::cout << "############################################" << std::endl;
    std::cout << "### Do you want to set a max Generation? ###" << std::endl;
    std::cout << "############################################" << std::endl;
    std::cout << "###      Yes(Y)      ###      No(N)      ###" << std::endl;
    std::cout << "############################################" << std::endl;
    std::cout << ": ";
    std::cin >> a;
    if (a == "Y") {
        return true;
    }
    else {
        return false;
    }
}

int max_gen() {
    int g;
    std::cout << "set max generation: ";
    std::cin >> g;
    return g;
}

int stats(int c_gen, int prob, int c_pop, int s_pop, int l_pop, int h_pop) {
    float f_prob = 1/(prob+1); //???
    float a_pop = s_pop / c_gen;
    std::cout << "############################################" << std::endl;
    std::cout << "###              Some Stats              ###" << std::endl;
    std::cout << "############################################" << std::endl;
    //std::setprecision(3);
    std::cout << "###     probability: " << f_prob <<  "%                  ###" << std::endl;
    std::cout << "###     current generation: " << c_gen << "           ###" << std::endl;
    std::cout << "###     current population: " << c_pop << "         ###" << std::endl;
    std::cout << "###     average population: " << a_pop << "         ###" << std::endl;
    std::cout << "###     highest population: " << h_pop << "         ###" << std::endl;
    std::cout << "###     lowest population: " << l_pop << "           ###" << std::endl;
    std::cout << "############################################" << std::endl;
    return 0;
}

int main()
{
    int h_pop = 0;
    int l_pop = 100000;
    int s_pop = 0;
    int m = -1;
    int i = input();
    bool m_g = q();
    if (m_g) {
        m = max_gen();
    }
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "ConwaysGameOfLife");
    window.setFramerateLimit(8);
    int gen = 0;
    Generation g;
    Population p;
    Field f;
    f.cell_start(window, i);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (gen != m) {
            window.clear(sf::Color::Black);
            f.update(window);
            f.draw(window);
            gen++;
            g.update(gen);
            g.draw(window);
            int pop = f.pop_update();
            p.update(pop);
            p.draw(window);
            s_pop += pop;
            if (pop > h_pop) {
                h_pop = pop;
            }
            if (pop < l_pop) {
                l_pop = pop;
            }
            window.display();
        }
        else {
            static int k = 0;
            if (k != 1) {
                int pop = f.pop_update();
                stats(gen, i, pop, s_pop, l_pop, h_pop);
                k++;
            }
        }
    }
    return 0;
}