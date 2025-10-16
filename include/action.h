#pragma once
#include "pch.h"

class Action {
public:
  enum Type {
    RealTime = 1,
    Pressed = 1 << 1,
    Released = 1 << 2,
  };
  Action(const Action &other);

  Action(const sf::Keyboard::Key &key);
  Action(const sf::Mouse::Button &button);

  bool test() const;

  bool operator==(const sf::Event &event) const;
  bool operator==(const Action &other) const;

  Action &operator=(const Action &other);

private:
  friend class ActionTarget;
  sf::Event _event;
};
