#ifndef CONTEST5_SEGMENT_H
#define CONTEST5_SEGMENT_H
#include "IShape.h"
#include "Point.h"
#include "Vector.h"
namespace geometry {
class Segment : public IShape {
 private:
  Point p1;
  Point p2;

 public:
  Segment(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  Point GetValue_p1() const;
  Point GetValue_p2() const;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
};
}  // namespace geometry

#endif  // CONTEST5_SEGMENT_H
