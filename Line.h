#ifndef CONTEST5_LINE_H
#define CONTEST5_LINE_H
#include "IShape.h"
#include "Point.h"
#include "Vector.h"
#include "Segment.h"

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
  Point GetValueOf_P1();
  Point GetValueOf_P2();

};
}

#endif  // CONTEST5_LINE_H
