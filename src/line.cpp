#include "../line.h"
namespace geometry {
Line::Line(const Point& p1, const Point& p2) : p1_(p1), p2_(p2) {
}
IShape& Line::Move(const Vector& v) {
  p1_.Move(v);
  p2_.Move(v);
  return *this;
}
bool Line::ContainsPoint(const Point& p) {
  Point p1 = this->GetValueOfP1();
  Point p2 = this->GetValueOfP2();
  bool ans = (p.GetValueX() - p1.GetValueX()) / (p2.GetValueX() - p1.GetValueX()) ==
             (p.GetValueY() - p1.GetValueY()) / (p2.GetValueY() - p1.GetValueY());
  return ans;
}

bool Line::CrossesSegment(const Segment& Segment) {
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

[[nodiscard]] std::unique_ptr<IShape> Line::Clone() const {
  return std::make_unique<Line>(p1_, p2_);
}

[[nodiscard]] std::string Line::ToString() const {
  return "Line[(" + std::to_string(p1_.GetValueX()) + ", " + std::to_string(p1_.GetValueY()) + "), (" +
         std::to_string(p2_.GetValueX()) + ", " + std::to_string(p2_.GetValueY()) + ")]";
}
Point Line::GetValueOfP1() {
  return p1_;
}
Point Line::GetValueOfP2() {
  return p2_;
}
}  // namespace geometry