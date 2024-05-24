#include "../polygon.h"
#include <cmath>
#include <algorithm>

namespace geometry {

Polygon::Polygon(const std::vector<Point>& points_) : points_(points_) {
}

IShape& Polygon::Move(const Vector& vector) {
  for (auto& point : points_) {
    point.Move(vector);
  }
  return *this;
}

bool Polygon::ContainsPoint(const Point& point) const {
  bool inside = false;
  for (size_t i = 0, j = points_.size() - 1; i < points_.size(); j = i++) {
    if ((points_[i].GetValueY() > point.GetValueY()) != (points_[j].GetValueY() > point.GetValueY()) &&
        (point.GetValueX() < (points_[j].GetValueX() - points_[i].GetValueX()) *
                                     (point.GetValueY() - points_[i].GetValueY()) /
                                     (points_[j].GetValueY() - points_[i].GetValueY()) +
                                 points_[i].GetValueX()))
      inside = !inside;
  }
  return inside;
}

bool Polygon::CrossesSegment(const Segment& segment) const {
  for (size_t i = 0, j = points_.size() - 1; i < points_.size(); j = i++) {
    Segment edge(points_[i], points_[j]);
    if (edge.CrossesSegment(segment))
      return true;
  }
  return false;
}

std::unique_ptr<IShape> Polygon::Clone() const {
  return std::make_unique<Polygon>(points_);
}

std::string Polygon::ToString() const {
  std::string result = "Polygon[";
  for (const auto& point : points_) {
    result += point.ToString() + ", ";
  }
  result.pop_back();
  result.pop_back();
  result += "]";
  return result;
}
}  // namespace geometry
