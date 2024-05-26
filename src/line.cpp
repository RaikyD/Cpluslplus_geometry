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
  bool ans = false;
  if (p2.GetValueX() - p1.GetValueX() != 0 && p2.GetValueY() - p1.GetValueY() != 0) {
    ans = (p.GetValueX() - p1.GetValueX()) / (p2.GetValueX() - p1.GetValueX()) ==
          (p.GetValueY() - p1.GetValueY()) / (p2.GetValueY() - p1.GetValueY());
  } else {
    ans = p.GetValueX() == p1.GetValueX() && p.GetValueY() == p1.GetValueY();
  }
  return ans;
}

bool Line::CrossesSegment(const Segment& Segment) const {
  int x11 = p1_.GetValueX();
  int y11 = p1_.GetValueY();
  int x12 = p2_.GetValueX();
  int y12 = p2_.GetValueY();

  int x21 = Segment.GetValuep1().GetValueX();
  int y21 = Segment.GetValuep1().GetValueY();
  int x22 = Segment.GetValuep2().GetValueX();
  int y22 = Segment.GetValuep2().GetValueY();

  int maxx1 = std::max(x11, x12), maxy1 = std::max(y11, y12);
  int minx1 = std::min(x11, x12), miny1 = std::min(y11, y12);
  int maxx2 = std::max(x21, x22), maxy2 = std::max(y21, y22);
  int minx2 = std::min(x21, x22), miny2 = std::min(y21, y22);

  if (minx1 > maxx2 || maxx1 < minx2 || miny1 > maxy2 || maxy1 < miny2) {
    return false;
  }

  int dx1 = x12 - x11, dy1 = y12 - y11;
  int dx2 = x22 - x21, dy2 = y22 - y21;
  int dxx = x11 - x21, dyy = y11 - y21;
  int div, mul;

  if ((div = (int)((double)dy2 * dx1 - (double)dx2 * dy1)) == 0) {
    return false;
  }
  if (div > 0) {
    if ((mul = (int)((double)dx1 * dyy - (double)dy1 * dxx)) < 0 || mul > div) {
      return false;
    }
    if ((mul = (int)((double)dx2 * dyy - (double)dy2 * dxx)) < 0 || mul > div) {
      return false;
    }
  } else {
    if ((mul = -(int)((double)dx1 * dyy - (double)dy1 * dxx)) < 0 || mul > -div) {
      return false;
    }
    if ((mul = -(int)((double)dx2 * dyy - (double)dy2 * dxx)) < 0 || mul > -div) {
      return false;
    }
  }

  return true;
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