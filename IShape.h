#ifndef CONTEST5_ISHAPE_H
#define CONTEST5_ISHAPE_H

#include <memory>
#include <string>
#include "Vector.h"

namespace geometry {
class Point;
class Segment;
class Line;
class Ray;
class Polygon;
class Circle;

class IShape {
 public:
  virtual IShape& Move(const Vector&) = 0;
  virtual bool ContainsPoint(const Point&) const = 0;
  virtual bool CrossesSegment(const Segment&) const = 0;
  [[nodiscard]] virtual std::unique_ptr<IShape> Clone() const = 0;
  [[nodiscard]] virtual std::string ToString() const = 0;

  virtual ~IShape() = default;
};
}  // namespace geometry

#endif  // CONTEST5_ISHAPE_H
