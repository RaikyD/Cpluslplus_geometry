#pragma once
#include "IShape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"
namespace geometry {
class Line : IShape {
 private:
  Point p1_;
  Point p2_;

 public:
  Line(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  bool ContainsPoint(const Point& point) override;
  bool CrossesSegment(const Segment& segment) override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  point GetValueOfP1();
  point GetValueOfP2();
};
}  // namespace geometry
