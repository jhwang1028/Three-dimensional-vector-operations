#include <iostream>
#include "Vector3d.h"

int main() {
    // Create two vectors for testing
    Vector3d v1(1.0, 2.0, 3.0);
    Vector3d v2(4.0, 5.0, 6.0);

    // Test getters
    std::cout << "v1: (" << v1.GetX() << ", " << v1.GetY() << ", " << v1.GetZ() << ")\n";
    std::cout << "v2: (" << v2.GetX() << ", " << v2.GetY() << ", " << v2.GetZ() << ")\n";

    // Test Add with a constant
    Vector3d v3 = v1.Add(2.0);
    std::cout << "v1 + 2.0: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Add with another vector
    v3 = v1.Add(v2);
    std::cout << "v1 + v2: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Sub with a constant
    v3 = v1.Sub(1.0);
    std::cout << "v1 - 1.0: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Sub with another vector
    v3 = v1.Sub(v2);
    std::cout << "v1 - v2: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Mul with a constant
    v3 = v1.Mul(3.0);
    std::cout << "v1 * 3.0: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Mul with another vector
    v3 = v1.Mul(v2);
    std::cout << "v1 * v2: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Div with a constant
    v3 = v1.Div(2.0);
    std::cout << "v1 / 2.0: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Div with another vector
    v3 = v1.Div(v2);
    std::cout << "v1 / v2: (" << v3.GetX() << ", " << v3.GetY() << ", " << v3.GetZ() << ")\n";

    // Test Sum function
    double sum = v1.Sum();
    std::cout << "Sum of elements in v1: " << sum << "\n";  // Expected output: 6.0
    
    // Test Length function
    std::cout << "Length of v1: " << v1.Length() << "\n";  // Expected: 3.74166

    // Test Distance function
    std::cout << "Distance between v1 and v2: " << v1.Distance(v2) << "\n";  // Expected: 5.19615

    // Test Inner (Dot) product function
    std::cout << "Dot product of v1 and v2: " << v1.Inner(v2) << "\n";  // Expected: 32

    // Test Cross product function
    Vector3d cross = v1.Cross(v2);
    std::cout << "Cross product of v1 and v2: (" << cross.GetX() << ", " << cross.GetY() << ", " << cross.GetZ() << ")\n";
    // Expected: (-3, 6, -3)

    // Test Angle function in degrees
    double angleDegrees = v1.Angle(v2, false);
    std::cout << "Angle between v1 and v2 in degrees: " << angleDegrees << "\n";  // Expected: ~12.9332

    // Test Angle function in radians
    double angleRadians = v1.Angle(v2);
    std::cout << "Angle between v1 and v2 in radians: " << angleRadians << "\n";  // Expected: ~0.2257

    return 0;
}
