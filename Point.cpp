//
// Created by Даниил Гуршумов on 22.05.2024.
//

#include "Point.h"

namespace geometry {
Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}
Point::Point(const Point& other) {
  x_ = other.x_;
  y_ = other.y_;
}
IShape& Point::Move(const Vector& v) {
  x_ += v.GetValueOf_X();
  y_ += v.GetValueOf_Y();
  return *this;
}

bool Point::ContainsPoint(const Point& p) const {
  return p.x_ == x_ && p.y_ == y_;
}

bool Point::CrossesSegment(const Segment& s) const {
  return s.Contains(*this);
}

[[nodiscard]] std::unique_ptr<IShape> Point::Clone() const {
  return std::make_unique<Point>(x_, y_);
}

[[nodiscard]] std::string Point::ToString() const {
  return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}
}