#include <SFML/Graphics.hpp>
#include <iterator>
#include <algorithm>
#include <vector>

using value_type = const unsigned int;

int main(){

    value_type height {600};
    value_type width {800};

    sf::RenderWindow window(sf::VideoMode({width,height}), "Title");

    while (1){
        while (window.pollEvent()){
            
        }
    }

    return EXIT_SUCCESS;
}