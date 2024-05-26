#include "../circle.h"
#include "../point.h"
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

bool Circle::CrossesSegment(const Segment& s) const {
  // Вычисляем расстояние от центра окружности до ближайшей точки на отрезке
  int x1 = s.GetValuep1().GetValueX();
  int y1 = s.GetValuep1().GetValueY();
  int x2 = s.GetValuep2().GetValueX();
  int y2 = s.GetValuep2().GetValueY();
  int xc = center_point_.GetValueX();
  int yc = center_point_.GetValueY();

  int dx = x2 - x1;
  int dy = y2 - y1;
  int dr = static_cast<int>(std::sqrt(dx * dx + dy * dy));

  if (dr == 0) {
    // Отрезок вырожден в точку
    return ContainsPoint(s.GetValuep1());
  }

  int t = ((xc - x1) * dx + (yc - y1) * dy) / (dr * dr);
  if (t < 0) {
    t = 0;
  } else if (t > 1) {
    t = 1;
  }

  int closest_x = x1 + t * dx;
  int closest_y = y1 + t * dy;

  int dx_c = closest_x - xc;
  int dy_c = closest_y - yc;
  int dist = dx_c * dx_c + dy_c * dy_c;
  return dist <= radius_ * radius_;
}

std::unique_ptr<IShape> Circle::Clone() const {
  return std::make_unique<Circle>(center_point_, radius_);
}

std::string Circle::ToString() const {
  return "Circle(Point(" + std::to_string(center_point_.GetValueX()) + ", " +
         std::to_string(center_point_.GetValueY()) + "), " + std::to_string(radius_) + ")";
}
}  // namespace geometry