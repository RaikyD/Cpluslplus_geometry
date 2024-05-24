#include "../vector.h"

namespace geometry {
Vector::Vector(int x, int y) : x_(x), y_(y) {
}

[[nodiscard]] int Vector::GetValueOfX() const {
  return x_;
}

[[nodiscard]] int Vector::GetValueOfY() const {
  return y_;
}

Vector Vector::operator-() const {
  return {-x_, -y_};
}

Vector Vector::operator+(const Vector& other) const {
  return {x_ + other.x_, y_ + other.y_};
}

Vector Vector::operator-(const Vector& other) const {
  return {x_ - other.x_, y_ - other.y_};
}

Vector Vector::operator*(int scalar) const {
  return {x_ * scalar, y_ * scalar};
}

Vector Vector::operator/(int scalar) const {
  return {x_ / scalar, y_ / scalar};
}

Vector& Vector::operator+=(const Vector& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

Vector& Vector::operator-=(const Vector& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

Vector& Vector::operator*=(int scalar) {
  x_ *= scalar;
  y_ *= scalar;
  return *this;
}

Vector& Vector::operator/=(int scalar) {
  x_ /= scalar;
  y_ /= scalar;
  return *this;
}

bool Vector::operator==(const Vector& other) const {
  return x_ == other.x_ && y_ == other.y_;
}
}  // namespace geometry
