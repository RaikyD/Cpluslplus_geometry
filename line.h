#pragma once
#include "IShape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"
namespace geometry {
class Line : public IShape {
 private:
  Point p1_;
  Point p2_;

 public:
  Line(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] bool ContainsPoint(const Point& point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& segment) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  [[nodiscard]] Point GetValueOfP1() const;
  [[nodiscard]] Point GetValueOfP2() const;
};
}  // namespace geometry
