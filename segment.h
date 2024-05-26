#pragma once
#include "IShape.h"
#include "point.h"
#include "vector.h"
namespace geometry {
class Segment : public IShape {
 private:
  Point p1_;
  Point p2_;

 public:
  Segment(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] Point GetValuep1() const;
  [[nodiscard]] Point GetValuep2() const;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  [[nodiscard]] int Orientation(const Point& p, const Point& q, const Point& r) const;
  [[nodiscard]] bool OnSegment(Point p, Point q, Point r) const;
  [[nodiscard]] bool DoIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) const;
};
}  // namespace geometry
