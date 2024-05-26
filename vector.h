#pragma once
namespace geometry {
class Vector {
 private:
  int x_;
  int y_;

 public:
  Vector(int x, int y);
  [[nodiscard]] int GetValueOfX() const;
  [[nodiscard]] int GetValueOfY() const;
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
  int CrossProduct(const Vector& other) const;
  int DotProduct(const Vector& other) const;
};
}  // namespace geometry
