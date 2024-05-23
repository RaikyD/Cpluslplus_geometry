#include "Segment.h"
Segment::Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

IShape& Segment::Move(const Vector& v) {
  p1.Move(v);
  p2.Move(v);
  return *this;
}

[[nodiscard]] bool Segment::ContainsPoint(const Point& p) const {
  Vector v1 = p2 - p1;
  Vector v2 = p - p1;
  double cross = v1.GetValueOf_X() * v2.GetValueOf_Y() - v1.GetValueOf_Y() * v2.GetValueOf_X();
  if (std::abs(cross) > 1e-6)
    return false;
  double dot = v1.GetValueOf_X() * v2.GetValueOf_X() + v1.GetValueOf_Y() * v2.GetValueOf_Y();
  return dot >= 0 && dot <= v1.GetValueOf_X() * v1.GetValueOf_X() + v1.GetValueOf_Y() * v1.GetValueOf_Y();
}

[[nodiscard]] bool Segment::CrossesSegment(const Segment& s) const {
  Vector v1 = p2 - p1;
  Vector v2 = s.p2 - s.p1;
  double det = v1.GetValueOf_X() * v2.GetValueOf_Y() - v1.GetValueOf_Y() * v2.GetValueOf_X();
  if (std::abs(det) < 1e-6)
    return (ContainsPoint(s.p1) || ContainsPoint(s.p2) || s.ContainsPoint(p1) || s.ContainsPoint(p2));

  double t = ((s.p1.GetValueOf_X() - p1.GetValueOf_X()) * v2.GetValueOf_Y() -
              (s.p1.GetValueOf_Y() - p1.GetValueOf_Y()) * v2.GetValueOf_X()) /
             det;
  double u = ((p1.GetValueOf_X() - s.p1.GetValueOf_X()) * v1.GetValueOf_Y() -
              (p1.GetValueOf_Y() - s.p1.GetValueOf_Y()) * v1.GetValueOf_X()) /
             det;
  return t >= 0 && t <= 1 && u >= 0 && u <= 1;
}

[[nodiscard]] std::unique_ptr<IShape> Segment::Clone() const {
  return std::make_unique<Segment>(p1, p2);
}

[[nodiscard]] std::string Segment::ToString() const {
  return "Segment[(" + std::to_string(p1.GetValueOf_X()) + ", " + std::to_string(p1.GetValueOf_Y()) +
         "), (" + std::to_string(p2.GetValueOf_X()) + ", " + std::to_string(p2.GetValueOf_Y()) + ")]";
}

bool Segment::Contains(const Point& p) const {
  Vector v1 = p2 - p1;
  Vector v2 = p - p1;
  double cross = v1.GetValueOf_X() * v2.GetValueOf_Y() - v1.GetValueOf_Y() * v2.GetValueOf_X();
  if (std::abs(cross) > 1e-6)
    return false;
  double dot = v1.GetValueOf_X() * v2.GetValueOf_X() + v1.GetValueOf_Y() * v2.GetValueOf_Y();
  return dot >= 0 && dot <= v1.GetValueOf_X() * v1.GetValueOf_X() + v1.GetValueOf_Y() * v1.GetValueOf_Y();
}


