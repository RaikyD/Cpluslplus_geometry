#ifndef CONTEST5_SEGMENT_H
#define CONTEST5_SEGMENT_H
#include "IShape.h"
#include "Point.h"
#include "Vector.h"
namespace geometry {
class Segment : public IShape {
 private:
  Point p1_;
  Point p2_;

 public:
  Segment(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] Point GetValue_p1() const;
  Point GetValue_p2() const;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  //Дополнительные методы для CrossesSegment
  int orientation(const Point& p, const Point& q, const Point& r) const;
  bool onSegment(Point p, Point q, Point r) const;
  bool doIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) const;
};
}  // namespace geometry

#endif  // CONTEST5_SEGMENT_H
