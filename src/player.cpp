#include "../include/player.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

Player::Player() : _shape(sf::Vector2f(32, 32)) {
  _shape.setFillColor(sf::Color::Blue);
  _shape.setOrigin(sf::Vector2f(300, 300));
}

void Player::update(sf::Time deltaTime) {
  float seconds = deltaTime.asSeconds();
  if (rotation != 0) {
    sf::Angle angle = sf::radians((rotation > 0 ? 1 : -1) * 180 * seconds);
    _shape.rotate(angle);
  }
  if (isMoving) {
    float angle = (_shape.getRotation().asRadians()/180 * M_PI) - (M_PI / 2);
    _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
  }
  _shape.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(_shape, states);
}
