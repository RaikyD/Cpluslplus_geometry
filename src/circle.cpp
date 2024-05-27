#include "../circle.h"
#include <string>
#include <cmath>

namespace geometry {
Circle::Circle(const Point& p, int r) : center_point_(p), radius_(r) {
}

IShape& Circle::Move(const Vector& vector) {
  center_point_.Move(vector);
  return *this;
}
bool Circle::ContainsPoint(const Point& p) const {
  int dx = p.GetValueX() - center_point_.GetValueX();
  int dy = p.GetValueY() - center_point_.GetValueY();
  return (dx * dx + dy * dy) <= radius_ * radius_;
}

bool Circle::CrossesSegment(const Segment& segment) const {
  Circle circle = Circle(center_point_, radius_);
  Point p1 = segment.GetValuep1();
  Point p2 = segment.GetValuep2();
  double a = p2.GetValueY() - p1.GetValueY();
  double b = p1.GetValueX() - p2.GetValueX();
  double c = a * p1.GetValueX() + b * p1.GetValueY();
  // Берем 4 точки на окружности, самые крайние каждой стороны
  Point p_top = Point(center_point_.GetValueX(), center_point_.GetValueY() + radius_);
  Point p_bottom = Point(center_point_.GetValueX(), center_point_.GetValueY() - radius_);
  Point p_left = Point(center_point_.GetValueX() - radius_, center_point_.GetValueY());
  Point p_right = Point(center_point_.GetValueX() + radius_, center_point_.GetValueY());
  if (p1 == p_top || p1 == p_bottom || p1 == p_left || p1 == p_right) {
    return true;
  }
  if (p2 == p_top || p2 == p_bottom || p2 == p_left || p2 == p_right) {
    return true;
  }
  double distance =
      std::abs(a * center_point_.GetValueX() + b * center_point_.GetValueY() + c) / std::sqrt(a * a + b * b);

  if (distance <= radius_ && p1.GetValueX() != p2.GetValueX()) {
    bool p1_inside = ContainsPoint(p1);
    bool p2_inside = ContainsPoint(p2);
    return !(p1_inside && p2_inside);
  }

  return false;
}

std::unique_ptr<IShape> Circle::Clone() const {
  return std::make_unique<Circle>(center_point_, radius_);
}

std::string Circle::ToString() const {
  return "Circle(Point(" + std::to_string(center_point_.GetValueX()) + ", " +
         std::to_string(center_point_.GetValueY()) + "), " + std::to_string(radius_) + ")";
}
int Circle::Distance(const Point& point) {
  return std::sqrt((point.GetValueX() - center_point_.GetValueX()) * (point.GetValueX() - center_point_.GetValueX()) +
                   (point.GetValueY() - center_point_.GetValueY()) * (point.GetValueY() - center_point_.GetValueY()));
}
}  // namespace geometry