#include "../include/action.h"
#include "../include/game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

int main() {
  // Game game;
  // game.run(6000);
  Action action(sf::Keyboard::Key::Up);
  bool check = true;
  while (true) {
    if (action == sf::Event::KeyPressed()) {
      std::cout << "Working" << std::endl;
    }
  }
  return 0;
}
