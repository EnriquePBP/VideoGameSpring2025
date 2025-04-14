#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>
using namespace std;
using namespace sf;

int main() {
    RenderWindow window;
    window.create(VideoMode({ 1800, 1200 }), "Box Dodger", Style::Default);
    window.setFramerateLimit(165);
    window.setVerticalSyncEnabled(true);

    Texture texturamain;
    if (!texturamain.loadFromFile("caquita.png")) {
        window.close();
    }
    texturamain.setSmooth(true);

    Sprite spritemain(texturamain);
    spritemain.setPosition({ 900.f, 600.f });
    spritemain.setScale({ 0.25f, 0.25f });


    while (window.isOpen()) {
        while (const optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
            else if (const Event::KeyPressed* keyPressed = event->getIf<Event::KeyPressed>()) {
                if (keyPressed->scancode == Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }        
         
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) {
            spritemain.move({ -10.f, 0.f });
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) {
            spritemain.move({ 10.f, 0.f });
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W)) {
            spritemain.move({ 0.f, -10.f });
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S)) {
            spritemain.move({ 0.f, 10.f });
        }

        window.clear();
        window.draw(spritemain);        
        window.display();
    }
}