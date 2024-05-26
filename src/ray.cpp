#include "../ray.h"
#include "../line.h"
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

bool Ray::CrossesSegment(const Segment& s) const {
  Point p1 = s.GetValuep1();
  Point p2 = s.GetValuep2();
  Vector v(p2_ - p1_);
  Vector u(p2 - p1);

  int cross = v.CrossProduct(u);
  if (cross == 0) {
    if (p1.GetValueX() == p1_.GetValueX() && p1.GetValueY() == p1_.GetValueY()) {
      return true;
    }
    return false;
  }

  Vector w(p1 - p1_);
  int t = w.CrossProduct(u) / cross;
  int alpha = v.CrossProduct(w) / cross;

  return t >= 0 && alpha >= 0 && alpha <= 1;
}

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