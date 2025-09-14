#include "game_object.hpp"
#include "object_registry.hpp"

// void GameObject::awake() {}
// void GameObject::init() {}
// void GameObject::update() {}
// void GameObject::render() {}
// void GameObject::end() {}
// void GameObject::dispose() {}
// void GameObject::test() {}
GameObject::GameObject(const char* name) {
  this->name = name;
}
