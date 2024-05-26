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
  auto ap = Vector(*this - a);
  auto pb = Vector(b - *this);
  return ((ap.GetValueOfX() * pb.GetValueOfY() - ap.GetValueOfY() * pb.GetValueOfX()) == 0) &&
         ((ap.GetValueOfX() * pb.GetValueOfX() + ap.GetValueOfY() * pb.GetValueOfY()) >= 0);
}

[[nodiscard]] std::unique_ptr<IShape> Point::Clone() const {
  return std::make_unique<Point>(x_, y_);
}

[[nodiscard]] std::string Point::ToString() const {
  return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}

Vector Point::operator-(const geometry::Point& p) const {
  return {this->x_ - p.x_, this->y_ - p.y_};
}
}  // namespace geometry