#pragma once

#include "IShape.h"
#include "vector.h"
namespace geometry {
class Point : public IShape {
 private:
  int x_;
  int y_;

 public:
  Point(int x, int y);
  Point(const Point& other);
  [[nodiscard]] int GetValueX() const;
  [[nodiscard]] int GetValueY() const;
  IShape& Move(const Vector& v) override;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
};
}  // namespace geometry
