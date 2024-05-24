#pragma once

#include "IShape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"

namespace geometry {
class Ray : public IShape {
 private:
  Point p1_;
  Point p2_;

 public:
  Ray(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  bool ContainsPoint(const Point& p) const override;
  bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  Point GetValueOfP1() const;
  Point GetValueOfP2() const;
};
}  // namespace geometry
