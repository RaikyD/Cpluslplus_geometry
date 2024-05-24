#pragma once
#include "IShape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Circle : public IShape {
 private:
  Point CenterPoint;
  int Radius;
 public:
  Circle(const Point& p, int r);
  IShape& Move(const Vector& v) override;
  bool ContainsPoint(const Point& p) const override;
  bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
};
}
