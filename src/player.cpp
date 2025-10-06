#include "../include/player.h"

int TURNING_ANGLE = 180;

Player::Player() : _shape(sf::Vector2f(32, 32)) {
  _shape.setFillColor(sf::Color::Blue);
  _shape.setOrigin(sf::Vector2f(0, 0));
}

void Player::update(sf::Time deltaTime) {
  float seconds = deltaTime.asSeconds();
  if (rotation != 0) {
    sf::Angle angle =
        sf::degrees((rotation > 0 ? 1 : -1) * TURNING_ANGLE * seconds);
    _shape.rotate(angle);
  }
  if (isMoving) {
    float angle =
        (_shape.getRotation().asDegrees() / TURNING_ANGLE * M_PI) - (M_PI / 2);
    _velocity +=
        sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
  } else {
    _velocity = sf::Vector2f(0, 0);
  }
  _shape.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(_shape, states);
}
