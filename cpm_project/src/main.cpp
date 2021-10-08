#include <fmt/format.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
    fmt::print("Hello {}", "CPM");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello CPM");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return EXIT_SUCCESS;
}