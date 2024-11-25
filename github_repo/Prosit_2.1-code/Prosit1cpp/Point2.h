#pragma once

#include "Vector2.h"
#include <iostream>


class Point2 {
private:
  /*A COMPLETER*/
  Point2 Point2_add(const Point2 *p, const Vector2 *r);
  Point2 Point2_sub(Point2 *r, const Point2 *p);
public:
  /*A COMPLETER*/
  void Point2_init(Point2 *p);
  void Point2_init_with_xy(Point2 *p, float x, float y);
  float Point2_getX(const Point2 *p);
  float Point2_getY(const Point2 *p);
  void Point2_setX(Point2 *p, float x);
  void Point2_setY(Point2 *p, float y);
  void Point2_print(const Point2 *p);
};
