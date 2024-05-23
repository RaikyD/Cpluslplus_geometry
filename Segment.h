//
// Created by Даниил Гуршумов on 22.05.2024.
//

#ifndef CONTEST5_SEGMENT_H
#define CONTEST5_SEGMENT_H
#include "IShape.h"
#include "Point.h"
#include "Vector.h"

class Segment : public IShape {
 private:
  Point p1;
  Point p2;

 public:
  Segment(const Point& p1, const Point& p2);
  IShape& Move(const Vector& v) override;
  [[nodiscard]] bool ContainsPoint(const Point& p) const override;
  [[nodiscard]] bool CrossesSegment(const Segment& s) const override;
  [[nodiscard]] std::unique_ptr<IShape> Clone() const override;
  [[nodiscard]] std::string ToString() const override;
  bool Contains(const Point& p) const;
};

#endif  // CONTEST5_SEGMENT_H
