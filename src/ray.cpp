#include "../ray.h"

namespace geometry {
Ray::Ray(const Point& p1, const Point& p2) : p1_(p1), p2_(p2) {
}
IShape& Ray::Move(const geometry::Vector& v) {
  p1_.Move(v);
  p2_.Move(v);
  return *this;
}
bool Ray::ContainsPoint(const geometry::Point& p) const {
  auto vect = Vector(p2_ - p1_);
  auto vect2 = Vector(p - p1_);
  return ((vect.GetValueOfX() * vect2.GetValueOfY() - vect.GetValueOfY() * vect2.GetValueOfX()) == 0) &&
         ((vect.GetValueOfX() * vect2.GetValueOfX() + vect.GetValueOfY() * vect2.GetValueOfY()) >= 0);
}

bool Ray::CrossesSegment(const Segment& s) const { Point a = s.GetValuep1(); Point b = s.GetValuep2(); Vector ab = Vector(b - a); Vector ap = Vector(GetValuep1() - a); Vector n = Vector(-ab.GetValueOfY(), ab.GetValueOfX()); double dotProduct = n.GetValueOfX() * ap.GetValueOfX() + n.GetValueOfY() * ap.GetValueOfY(); double t = (n.GetValueOfX() * ab.GetValueOfX() + n.GetValueOfY() * ab.GetValueOfY()) / (n.GetValueOfX() * n.GetValueOfX() + n.GetValueOfY() * n.GetValueOfY()); if (t < 0) { return false; } Point intersectionPoint = GetValuep1() + t * GetValueDirection(); if (intersectionPoint.GetValueX() < a.GetValueX() || intersectionPoint.GetValueX() > b.GetValueX() || intersectionPoint.GetValueY() < a.GetValueY() || intersectionPoint.GetValueY() > b.GetValueY()) { return false; } return true; }



[[nodiscard]] std::unique_ptr<IShape> Ray::Clone() const {
  return std::make_unique<Ray>(p1_, p2_);
}

[[nodiscard]] std::string Ray::ToString() const {
  return "Ray(Point(" + std::to_string(p1_.GetValueX()) + ", " + std::to_string(p1_.GetValueY()) + "), Vector(" +
         std::to_string(p2_.GetValueX() - p1_.GetValueX()) + ", " + std::to_string(p2_.GetValueY() - p1_.GetValueY()) +
         "))";
}
Point Ray::GetValueOfP1() const {
  return p1_;
}
Point Ray::GetValueOfP2() const {
  return p2_;
}

}  // namespace geometry