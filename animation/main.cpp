#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <random>
#include <algorithm>

using value_type = const unsigned int;

int main(){

    value_type width = 1600;
    value_type height {600};

    sf::RenderWindow window(sf::VideoMode({width,height}), "Title");

    while (1){
        while (window.pollEvent()){
            
        }
    }

    return EXIT_SUCCESS;
}