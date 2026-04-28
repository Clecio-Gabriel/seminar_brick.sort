#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    // 1. Configurações da Janela
    // SFML 3 exige que VideoMode use unsigned int
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;
    
    // SFML 3: VideoMode agora recebe um sf::Vector2u, por isso o uso de chaves {}
    sf::RenderWindow window(sf::VideoMode({screenWidth, screenHeight}), "Visualizador de Algoritmo - Bubble Sort (SFML 3)");
    window.setFramerateLimit(60); 

    // 2. Configuração dos Dados
    const int numElements = 100;
    const float barWidth = static_cast<float>(screenWidth) / numElements;
    std::vector<int> values(numElements);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(10, screenHeight - 20);

    for (int k = 0; k < numElements; k++) {
        values[k] = distrib(gen);
    }

    int i = 0;
    int j = 0;
    bool isSorting = true;

    // 3. Loop Principal da Aplicação
    while (window.isOpen()) {
        
        // SFML 3: pollEvent agora retorna um std::optional
        // E os eventos são verificados usando a função .is<TipoDoEvento>()
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // --- ATUALIZAÇÃO DA LÓGICA ---
        if (isSorting) {
            if (i < numElements - 1) {
                if (j < numElements - i - 1) {
                    if (values[j] > values[j + 1]) {
                        std::swap(values[j], values[j + 1]);
                    }
                    j++;
                } else {
                    j = 0;
                    i++;
                }
            } else {
                isSorting = false;
            }
        }

        // --- RENDERIZAÇÃO ---
        window.clear(sf::Color::Black); 

        for (int k = 0; k < numElements; k++) {
            // SFML 3: Construtores e posições exigem explicitamente vetores usando {}
            sf::RectangleShape bar({barWidth - 1.0f, static_cast<float>(values[k])});
            
            // setPosition agora exige um Vector2f, envolto em {}
            bar.setPosition({k * barWidth, static_cast<float>(screenHeight - values[k])});

            if (isSorting && (k == j || k == j + 1)) {
                bar.setFillColor(sf::Color::Red);
            } else if (!isSorting) {
                bar.setFillColor(sf::Color::Green);
            } else {
                bar.setFillColor(sf::Color::White);
            }

            window.draw(bar);
        }

        window.display();
    }

    return 0;
}