#include "Vector3d.h"
#include <cmath>
#include <limits>  // for INFINITY

// Constant for PI
const double PI = std::acos(-1);

// Default constructor initializing to zero
Vector3d::Vector3d() : mX(0), mY(0), mZ(0) {}

// Parameterized constructor
Vector3d::Vector3d(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

// Getters
double Vector3d::GetX() const { return mX; }
double Vector3d::GetY() const { return mY; }
double Vector3d::GetZ() const { return mZ; }

// Setters
void Vector3d::SetX(double x) { mX = x; }
void Vector3d::SetY(double y) { mY = y; }
void Vector3d::SetZ(double z) { mZ = z; }

// Add a constant to each element of the vector
Vector3d Vector3d::Add(double c) const {
    return Vector3d(mX + c, mY + c, mZ + c);
}

// Add corresponding elements of two vectors
Vector3d Vector3d::Add(const Vector3d& v2) const {
    return Vector3d(mX + v2.mX, mY + v2.mY, mZ + v2.mZ);
}

// Subtract a constant from each element of the vector
Vector3d Vector3d::Sub(double c) const {
    return Vector3d(mX - c, mY - c, mZ - c);
}

// Subtract corresponding elements of two vectors
Vector3d Vector3d::Sub(const Vector3d& v2) const {
    return Vector3d(mX - v2.mX, mY - v2.mY, mZ - v2.mZ);
}

// Multiply each element of the vector by a constant
Vector3d Vector3d::Mul(double c) const {
    return Vector3d(mX * c, mY * c, mZ * c);
}

// Multiply corresponding elements of two vectors
Vector3d Vector3d::Mul(const Vector3d& v2) const {
    return Vector3d(mX * v2.mX, mY * v2.mY, mZ * v2.mZ);
}

// Divide each element of the vector by a constant
Vector3d Vector3d::Div(double c) const {
    if (c == 0) {
        return Vector3d(INFINITY, INFINITY, INFINITY);  // or throw an exception
    }
    return Vector3d(mX / c, mY / c, mZ / c);
}

// Divide corresponding elements of two vectors
Vector3d Vector3d::Div(const Vector3d& v2) const {
    if (v2.mX == 0 || v2.mY == 0 || v2.mZ == 0) {
        return Vector3d(INFINITY, INFINITY, INFINITY);  // or throw an exception
    }
    return Vector3d(mX / v2.mX, mY / v2.mY, mZ / v2.mZ);
}

// Sum of elements (x + y + z)
double Vector3d::Sum() const {
    return mX + mY + mZ;
}

// Length (magnitude) of the vector
double Vector3d::Length() const {
    return std::sqrt(mX * mX + mY * mY + mZ * mZ);
}

// Distance between two vectors
double Vector3d::Distance(const Vector3d& v2) const {
    return std::sqrt(std::pow(mX - v2.mX, 2) + std::pow(mY - v2.mY, 2) + std::pow(mZ - v2.mZ, 2));
}

// Dot product (inner product) of two vectors
double Vector3d::Inner(const Vector3d& v2) const {
    return mX * v2.mX + mY * v2.mY + mZ * v2.mZ;
}

// Cross product of two vectors
Vector3d Vector3d::Cross(const Vector3d& v2) const {
    return Vector3d(
        mY * v2.mZ - mZ * v2.mY,
        mZ * v2.mX - mX * v2.mZ,
        mX * v2.mY - mY * v2.mX
    );
}

// Angle between two vectors in radians (default) or degrees
double Vector3d::Angle(const Vector3d& v2, bool radian) const {
    double dotProduct = Inner(v2);
    double lengthsProduct = Length() * v2.Length();
    double cosTheta = dotProduct / lengthsProduct;
    double angle = std::acos(cosTheta);  // angle in radians
    if (!radian) {
        angle = angle * 180 / PI;  // Convert to degrees if requested
    }
    return angle;
}
