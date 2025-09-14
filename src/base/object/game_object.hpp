#pragma once
#include "../base.hpp"

class GameObject {
public:
  const char* name;
  int id;
  bool isShown;

  GameObject(const char* name);

  virtual void awake() {};
  virtual void init() {};
  virtual void update() {};
  virtual void render() {};
  virtual void end() {};
  virtual void dispose() {};
  virtual void test() {};
};
