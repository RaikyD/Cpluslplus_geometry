
#ifndef CONTEST5_POINT_H
#define CONTEST5_POINT_H
#include "IShape.h"
#include "Vector.h"
namespace geometry {
class Point : public IShape {
 private:
  int x_;
  int y_;

 public:
  Point(int x, int y);
  Point(const Point& other);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
};
}  // namespace geometry

#endif  // CONTEST5_POINT_H