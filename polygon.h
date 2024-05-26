#pragma once

#include "IShape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"
#include <vector>

namespace geometry {
class Polygon : public IShape {
 private:
  std::vector<Point> points_;

 public:
  explicit Polygon(const std::vector<Point>& points);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
};
}  // namespace geometry
