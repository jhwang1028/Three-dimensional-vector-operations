#pragma once

class Vector3d
{
private:
    double mX;
    double mY;
    double mZ;

public:
    // Constructors
    Vector3d();  // Default constructor
    Vector3d(double x, double y, double z);  // Parameterized constructor

    // Getters
    double GetX() const;
    double GetY() const;
    double GetZ() const;

    // Setters
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);

    // Element-wise operations
    Vector3d Add(double c) const;
    Vector3d Add(const Vector3d& v2) const;
    Vector3d Sub(double c) const;
    Vector3d Sub(const Vector3d& v2) const;
    Vector3d Mul(double c) const;
    Vector3d Mul(const Vector3d& v2) const;
    Vector3d Div(double c) const;
    Vector3d Div(const Vector3d& v2) const;

    // Vector operations
    double Sum() const;
    double Length() const;  // Vector magnitude
    double Distance(const Vector3d& v2) const;  // Distance between two vectors
    double Inner(const Vector3d& v2) const;  // Dot product (inner product)
    Vector3d Cross(const Vector3d& v2) const;  // Cross product
    double Angle(const Vector3d& v2, bool radian = true) const;  // Angle between two vectors
};
