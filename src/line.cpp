#include "../line.h"
namespace geometry {
Line::Line(const Point& p1, const Point& p2) : p1_(p1), p2_(p2) {
}
IShape& Line::Move(const Vector& v) {
  p1_.Move(v);
  p2_.Move(v);
  return *this;
}
bool Line::ContainsPoint(const Point& p) const {
  Segment seg = Segment(p1_, p2_);
  int orientation = seg.Orientation(p1_, p2_, p);
  return orientation == 0;
}
bool Line::CrossesSegment(const Segment& segment) const {
  Point p1 = segment.GetValuep1();
  Point p2 = segment.GetValuep2();
  int o1 = segment.Orientation(p1_, p2_, p1);
  int o2 = segment.Orientation(p1_, p2_, p2);
  if (o1 * o2 < 0) {
    return true;
  }
  if (o1 == 0 || o2 == 0) {
    return true;
  }
  return false;
}

std::unique_ptr<IShape> Line::Clone() const {
  return std::make_unique<Line>(p1_, p2_);
}
std::string Line::ToString() const {
  return "Line(" + std::to_string(p2_.GetValueY() - p1_.GetValueY()) + ", " +
         std::to_string(p1_.GetValueX() - p2_.GetValueX()) + ", " +
         std::to_string(p2_.GetValueX() * p1_.GetValueY() - p1_.GetValueX() * p2_.GetValueY()) + ")";
}
Point Line::GetValueOfP1() const {
  return p1_;
}
Point Line::GetValueOfP2() const {
  return p2_;
}
}  // namespace geometry