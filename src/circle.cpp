#include "../circle.h"
#include "../point.h"

namespace geometry {
Circle::Circle(const Point& p, int r) : center_point_(p), radius_(r) {
}

IShape& Circle::Move(const Vector& vector) {
  center_point_.Move(vector);
  return *this;
}

bool Circle::ContainsPoint(const Point& p) const {
  int dist = (p.GetValueX() - center_point_.GetValueX()) * (p.GetValueX() - center_point_.GetValueX()) +
             (p.GetValueY() - center_point_.GetValueY()) * (p.GetValueY() - center_point_.GetValueY());
  return dist == radius_ * radius_;
}

bool Circle::CrossesSegment(const Segment& s) const {
  int dist1 = (s.GetValuep1().GetValueX() - center_point_.GetValueX()) *
                  (s.GetValuep1().GetValueX() - center_point_.GetValueX()) +
              (s.GetValuep1().GetValueY() - center_point_.GetValueY()) *
                  (s.GetValuep1().GetValueY() - center_point_.GetValueY());
  int dist2 = (s.GetValuep2().GetValueX() - center_point_.GetValueX()) *
                  (s.GetValuep2().GetValueX() - center_point_.GetValueX()) +
              (s.GetValuep2().GetValueY() - center_point_.GetValueY()) *
                  (s.GetValuep2().GetValueY() - center_point_.GetValueY());
  if (dist1 > radius_ * radius_ && dist2 > radius_ * radius_)
    return false;
  Vector v(s.GetValuep2().GetValueX() - s.GetValuep1().GetValueX(),
           s.GetValuep2().GetValueY() - s.GetValuep1().GetValueY());
  int proj = v.GetValueOfX() * (center_point_.GetValueX() - s.GetValuep1().GetValueX()) +
             v.GetValueOfY() * (center_point_.GetValueY() - s.GetValuep1().GetValueY());

  return proj >= 0 && proj <= v.GetValueOfX() * v.GetValueOfX() + v.GetValueOfY() * v.GetValueOfY() &&
         dist1 + dist2 - 2 * proj <= radius_ * radius_;
}

std::unique_ptr<IShape> Circle::Clone() const {
  return std::make_unique<Circle>(center_point_, radius_);
}

std::string Circle::ToString() const {
  return "Pizdec";
}
}  // namespace geometry