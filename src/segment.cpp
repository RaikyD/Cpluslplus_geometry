#include "../segment.h"
#include "../IShape.h"
#include "../vector.h"
#include "../point.h"

namespace geometry {
Segment::Segment(const Point &p1, const Point &p2) : p1_(p1), p2_(p2) {
}

IShape &Segment::Move(const Vector &v) {
  p1_.Move(v);
  p2_.Move(v);
  return *this;
}
Point Segment::GetValuep1() const {
  return p1_;
}
Point Segment::GetValuep2() const {
  return p2_;
}

[[nodiscard]] bool Segment::ContainsPoint(const Point &p) const {
  return p.CrossesSegment(*this);
}
// Функция для нахождения ориентации трех точек (p, q, r).
// Возвращает:
// 0 -> p, q и r коллинеарны
// 1 -> по часовой стрелке
// 2 -> против часовой стрелки
int Segment::Orientation(const Point &p, const Point &q, const Point &r) const {
  double val = (q.GetValueY() - p.GetValueY()) * (r.GetValueX() - q.GetValueX()) -
               (q.GetValueX() - p.GetValueX()) * (r.GetValueY() - q.GetValueY());
  if (val == 0)
    return 0;                // Коллинеарны
  return (val > 0) ? 1 : 2;  // По часовой или против часовой
}

// Функция для проверки, лежит ли точка q на отрезке pr
bool Segment::OnSegment(const Point p, const Point q, const Point r) const {
  if (q.GetValueX() <= std::max(p.GetValueX(), r.GetValueX()) &&
      q.GetValueX() >= std::min(p.GetValueX(), r.GetValueX()) &&
      q.GetValueY() <= std::max(p.GetValueY(), r.GetValueY()) &&
      q.GetValueY() >= std::min(p.GetValueY(), r.GetValueY()))
    return true;
  return false;
}

// Функция для проверки пересечения двух отрезков (p1, q1) и (p2, q2)
bool Segment::DoIntersect(const Point &p1, const Point &q1, const Point &p2, const Point &q2) const {
  // Найти 4 ориентации, необходимые для проверки общего и особых случаев
  int o1 = Orientation(p1, q1, p2);
  int o2 = Orientation(p1, q1, q2);
  int o3 = Orientation(p2, q2, p1);
  int o4 = Orientation(p2, q2, q1);

  // Общий случай
  if (o1 != o2 && o3 != o4)
    return true;

  // Особые случаи
  // p1, q1 и p2 коллинеарны и p2 лежит на отрезке p1q1
  if (o1 == 0 && OnSegment(p1, p2, q1))
    return true;

  // p1, q1 и q2 коллинеарны и q2 лежит на отрезке p1q1
  if (o2 == 0 && OnSegment(p1, q2, q1))
    return true;

  // p2, q2 и p1 коллинеарны и p1 лежит на отрезке p2q2
  if (o3 == 0 && OnSegment(p2, p1, q2))
    return true;

  // p2, q2 и q1 коллинеарны и q1 лежит на отрезке p2q2
  if (o4 == 0 && OnSegment(p2, q1, q2))
    return true;

  return false;  // Не пересекаются
}

[[nodiscard]] bool Segment::CrossesSegment(const Segment &s) const {
  return DoIntersect(p1_, p2_, s.p1_, s.p2_);
}

[[nodiscard]] std::unique_ptr<IShape> Segment::Clone() const {
  return std::make_unique<Segment>(p1_, p2_);
}

[[nodiscard]] std::string Segment::ToString() const {
  return "Segment(Point(" + std::to_string(p1_.GetValueX()) + ", " + std::to_string(p1_.GetValueY()) + "), Point(" +
         std::to_string(p2_.GetValueX()) + ", " + std::to_string(p2_.GetValueY()) + "))";
}
}  // namespace geometry
