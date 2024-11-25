#pragma once

#include <iostream>
#include <math.h>



class Vector2 {
private:
  /*A COMPLETER*/
  Vector2 Vector2_dot_scalar(const Vector2 *v, float u);
  Vector2 Vector2_negate(const Vector2 *v);
public:
  /*A COMPLETER*/
  void Vector2_init(Vector2 *v, float x, float y);
  float Vector2_getX(const Vector2 *v);
  float Vector2_getY(const Vector2 *v);
  float Vector2_norm(const Vector2 *v);
  float Vector2_dot(const Vector2 *v, const Vector2 *r);
  float Vector2_cross(const Vector2 *v, const Vector2 *r);
};
