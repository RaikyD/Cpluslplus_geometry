#ifndef CONTEST5_VECTOR_H
#define CONTEST5_VECTOR_H

namespace geometry {
class Vector {
 private:
  int x_;
  int y_;

 public:
  Vector(int x, int y);
  [[nodiscard]] int GetValueOf_X() const;
  [[nodiscard]] int GetValueOf_Y() const;
  Vector operator-() const;
  Vector operator+(const Vector& other) const;
  Vector operator-(const Vector& other) const;
  Vector operator*(int scalar) const;
  Vector operator/(int scalar) const;
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*=(int scalar);
  Vector& operator/=(int scalar);
  bool operator==(const Vector& other) const;
};
}  // namespace geometry
#endif  // CONTEST5_VECTOR_H
