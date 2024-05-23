//
// Created by Даниил Гуршумов on 22.05.2024.
//

#ifndef CONTEST5_ISHAPE_H
#define CONTEST5_ISHAPE_H

#include <memory>
#include <string>
#include "Vector.h"

namespace geometry {
class Point;
class Segment;

class IShape {
 public:
  virtual IShape& Move(const Vector&) = 0;
  virtual bool ContainsPoint(const Point&) const = 0;
  virtual bool CrossesSegment(const Segment&) const = 0;
  [[nodiscard]] virtual std::unique_ptr<IShape> Clone() const = 0;
  [[nodiscard]] virtual std::string ToString() const = 0;

  virtual ~IShape() = default;
};
}





#endif  // CONTEST5_ISHAPE_H
