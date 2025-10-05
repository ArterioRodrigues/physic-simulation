#include "../include/game.h"
#include <SFML/Window/Keyboard.hpp>

Game::Game()
    : _window(sf::VideoMode(sf::Vector2u(800, 600)), "02_Game_Archi"),
      _player() {
  sf::Vector2f position(10, 20);
  _player.setPosition(position);
}

void Game::run(int frame_per_seconds) {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time TIME_PER_FRAME = sf::seconds(1.f / frame_per_seconds);

  while (_window.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();

    while (timeSinceLastUpdate > TIME_PER_FRAME) {
      timeSinceLastUpdate -= TIME_PER_FRAME;
      update(TIME_PER_FRAME);
    }

    update(timeSinceLastUpdate);
    render();
  }
}

void Game::processEvents() {
  std::optional<sf::Event> event = _window.pollEvent();
  while (event.has_value()) {
    if (event.value().is<sf::Event::Closed>()) {
      _window.close();
    } else if (event.value().is<sf::Event::KeyPressed>()) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        _window.close();
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        _player.isMoving = true;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        _player.rotation = -1;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        _player.rotation = 1;
    } else if (event.value().is<sf::Event::KeyReleased>()) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        _player.isMoving = false;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        _player.rotation = 0;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        _player.rotation = 0;
    }
    event = _window.pollEvent();
  }
}

void Game::update(sf::Time deltaTime) {
  _player.update(deltaTime);
}

void Game::render() {
  _window.clear();
  _window.draw(_player);
  _window.display();
}
