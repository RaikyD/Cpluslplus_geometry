#include "../ray.h"

namespace geometry {
Ray::Ray(const Point& p1, const Point& p2): p1_(p1), p2_(p2) {
}
IShape& Ray::Move(const geometry::Vector& v) {
  p1_.Move(v);
  p2_.Move(v);
  return *this;
}
bool Ray::ContainsPoint(const geometry::Point& p) const {
  Point p1 = this->GetValueOfP1();
  Point p2 = this->GetValueOfP2();
  bool ans = (p.GetValueX() - p1.GetValueX()) / (p2.GetValueX() - p1.GetValueX()) ==
             (p.GetValueY() - p1.GetValueY()) / (p2.GetValueY() - p1.GetValueY());
  return ans;
}

bool Ray::CrossesSegment(const Segment& Segment) const {
  Point p1 = Segment.GetValuep1();
  Point p2 = Segment.GetValuep2();
  int k = (p2.GetValueY() - p1.GetValueX()) / (p2.GetValueX() - p1.GetValueX());
  int b = (p1.GetValueX() * (p2.GetValueY() - p1.GetValueY()) / (p2.GetValueX() - p1.GetValueX())) + p1.GetValueY();
  if (p2.GetValueY() >= k * p2.GetValueX() + b && p1.GetValueY() <= k * p1.GetValueX() + b) {
    return true;
  } else if (p2.GetValueY() <= k * p2.GetValueX() + b && p1.GetValueY() >= k * p1.GetValueX() + b) {
    return true;
  }
  return false;
}
[[nodiscard]] std::unique_ptr<IShape> Ray::Clone() const {
  return std::make_unique<Ray>(p1_, p2_);
}

[[nodiscard]] std::string Ray::ToString() const {
  return "Rot ebal blyat";
}
Point Ray::GetValueOfP1() const {
  return p1_;
}
Point Ray::GetValueOfP2() const {
  return p2_;
}

}