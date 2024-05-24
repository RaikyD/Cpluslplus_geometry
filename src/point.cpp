#include "../point.h"
#include "../segment.h"
namespace geometry {
Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}
Point::Point(const Point& other) {
  x_ = other.x_;
  y_ = other.y_;
}
int Point::GetValueX() const {
  return x_;
}
int Point::GetValueY() const {
  return y_;
}
IShape& Point::Move(const Vector& v) {
  x_ += v.GetValueOfX();
  y_ += v.GetValueOfY();
  return *this;
}

bool Point::ContainsPoint(const Point& p) const {
  return p.x_ == x_ && p.y_ == y_;
}

bool Point::CrossesSegment(const Segment& s) const {
  Point a = s.GetValuep1();
  Point b = s.GetValuep2();
  int cross = (y_ - a.y_) * (b.x_ - a.x_) - (x_ - a.x_) * (b.y_ - a.y_);

  if (std::abs(cross) > 1e-6) {
    return false;
  }

  int dotprod = (x_ - a.x_) * (b.x_ - a.x_) + (y_ - a.y_ * (b.y_ - a.y_));
  if (dotprod < 0) {
    return false;
  }
  int squaredlengthba = (b.x_ - a.x_) * (b.x_ - a.x_) + (b.y_ - a.y_) * (b.y_ - a.y_);
  if (dotprod > squaredlengthba) {
    return false;
  }
  return true;
}

[[nodiscard]] std::unique_ptr<IShape> Point::Clone() const {
  return std::make_unique<Point>(x_, y_);
}

[[nodiscard]] std::string Point::ToString() const {
  return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}
}  // namespace geometry