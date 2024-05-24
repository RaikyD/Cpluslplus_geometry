#include "../circle.h"
#include "../point.h"

namespace geometry {
Circle::Circle(const Point& p, int r) : CenterPoint(p), Radius(r) {
}

IShape& Circle::Move(const Vector& vector) {
  CenterPoint.Move(vector);
  return *this;
}

bool Circle::ContainsPoint(const Point& p) const {
  int dist = (p.GetValueX() - CenterPoint.GetValueX()) * (p.GetValueX() - CenterPoint.GetValueX()) +
             (p.GetValueY() - CenterPoint.GetValueY()) * (p.GetValueY() - CenterPoint.GetValueY());
  return dist == Radius * Radius;
}

bool Circle::CrossesSegment(const Segment& s) const {
  bool Circle::CrossesSegment(const Segment& s) const {
    int dist1 = (s.GetValuep1().GetValueX() - CenterPoint.GetValueX()) * (s.GetValuep1().GetValueX() - CenterPoint.GetValueX()) +
                (s.GetValuep1().GetValueY() - CenterPoint.GetValueY()) * (s.GetValuep1().GetValueY() - CenterPoint.GetValueY());
    int dist2 = (s.GetValuep2().GetValueX() - CenterPoint.GetValueX()) * (s.GetValuep2().GetValueX() - CenterPoint.GetValueX()) +
                (s.GetValuep2().GetValueY() - CenterPoint.GetValueY()) * (s.GetValuep2().GetValueY() - CenterPoint.GetValueY());
    if (dist1 > Radius * Radius && dist2 > Radius * Radius)
      return false;
    Vector v(s.GetValuep2().GetValueX() - s.GetValuep1().GetValueX(), s.GetValuep2().GetValueY() - s.GetValuep1().GetValueY());
    int proj = v.GetValueX() * (CenterPoint.GetValueX() - s.GetValuep1().GetValueX()) + v.GetValueY() * (CenterPoint.GetValueY() - s.GetValuep1().GetValueY());

    return proj >= 0 && proj <= v.GetValueX() * v.GetValueX() + v.GetValueY() * v.GetValueY() && dist1 + dist2 - 2 * proj <= Radius * Radius;
  }

}
}