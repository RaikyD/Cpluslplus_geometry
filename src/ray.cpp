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

bool Ray::CrossesSegment(const Segment& s) const {
  Point p1 = s.GetValuep1();
  Point p2 = s.GetValuep2();

  int o1 = s.Orientation(p1, p2, p1_);
  int o2 = s.Orientation(p1, p2, p2_);
  int o3 = s.Orientation(p1_, p2_, p1);
  int o4 = s.Orientation(p1_, p2_, p2);

  if (o1 != o2 && o3 != o4) {
    return true;
  }

  if (o1 == 0 && s.OnSegment(p1, p1_, p2)) {
    return true;
  }
  if (o2 == 0 && s.OnSegment(p2, p1_, p2)) {
    return true;
  }
  if (o3 == 0 && s.OnSegment(p1_, p1, p2)) {
    return true;
  }
  if (o4 == 0 && s.OnSegment(p2_, p1, p2)) {
    return true;
  }

  return false;
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