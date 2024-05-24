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
  Point p1 = this->GetValueOfP1();
  Point p2 = this->GetValueOfP2();
  bool ans = (p.GetValueX() - p1.GetValueX()) / (p2.GetValueX() - p1.GetValueX()) ==
             (p.GetValueY() - p1.GetValueY()) / (p2.GetValueY() - p1.GetValueY());
  return ans;
}

bool Line::CrossesSegment(const Segment& Segment) const {
  Point p1 = Segment.GetValuep1();
  Point p2 = Segment.GetValuep2();
  int k = (p2.GetValueY() - p1.GetValueY()) / (p2.GetValueX() - p1.GetValueX());
  int b = p1.GetValueY() - k * p1.GetValueX();
  bool side1 = (p1.GetValueY() - (k * p1.GetValueX() + b)) * (p2.GetValueY() - (k * p2.GetValueX() + b)) <= 0;
  return side1;
}

[[nodiscard]] std::unique_ptr<IShape> Line::Clone() const {
  return std::make_unique<Line>(p1_, p2_);
}
[[nodiscard]] std::string Line::ToString() const {
  return "Line[(" + std::to_string(p1_.GetValueX()) + ", " + std::to_string(p1_.GetValueY()) + "), (" +
         std::to_string(p2_.GetValueX()) + ", " + std::to_string(p2_.GetValueY()) + ")]";
}
Point Line::GetValueOfP1() const {
  return p1_;
}
Point Line::GetValueOfP2() const {
  return p2_;
}
}  // namespace geometry