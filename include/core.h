#include "precision.h"

namespace Engine2D
{

    class Vector2 // 2D Vector class
    {

    public:
        real x; // X component
        real y; // Y component

    private:
        real pad; // Padding to have a 4th float for better performance

    public:
        Vector2() : x(0), y(0) {} // Default constructor setting the x and y vectors to zero

        Vector2(real x, real y) // Parameterized constructor
            : x(x), y(y)
        {
        }

        void invert() // Inverts the vector
        {
            x = -x;
            y = -y;
        }

        real magnitude() const // Returns the magnitude of the vector from the origin
        {
            return real_sqrt(x * x + y * y);
        }

        real squaredMagnitude() const // Returns the squared magnitude of the vector from the origin
        {
            return x * x + y * y;
        }

        void normalize() // Normalizes the vector, therefore can get the direction from the origin
        {
            real mag = magnitude();
            if (mag > 0)
            {
                x /= mag;
                y /= mag;
            }
        }

        void operator*=(const real scaleValue) // Allows for scaling of the vector by a real value, therefore can go (v *= constant)
        {
            x *= scaleValue;
            y *= scaleValue;
        }

        Vector2 operator*(const real scaleValue) const // Returns a new scaled vector, therefore can go (v2 = v1 * constant)
        {
            return Vector2(x * scaleValue, y * scaleValue);
        }

        void operator+=(const Vector2 &other) // Allows for addition of another vector to this one, therefore can go (v1 += v2)
        {
            x += other.x;
            y += other.y;
        }

        Vector2 operator+(const Vector2 &other) const // Returns a new vector that is the sum of this and another vector, therefore can go (v3 = v1 + v2)
        {
            return Vector2(x + other.x, y + other.y);
        }

        void operator-=(const Vector2 &other) // Allows for subtraction of another vector from this one, therefore can go (v1 -= v2)
        {
            x -= other.x;
            y -= other.y;
        }

        Vector2 operator-(const Vector2 &other) const // Returns a new vector that is the difference of this and another vector, therefore can go (v3 = v1 - v2)
        {
            return Vector2(x - other.x, y - other.y);
        }

        void addScaledValue(const Vector2 &other, real scaleValue) // Allows for addition of another vector scaled by a real value to this one, therefore can go (v1 += v2 * constant)
        {
            x += other.x * scaleValue;
            y += other.y * scaleValue;
        }

        Vector2 componentProduct(const Vector2 &other) const // Returns a new vector that is the component-wise product of this and another vector
        {
            return Vector2(x * other.x, y * other.y);
        }

        void componentProductUpdate(const Vector2 &other) // Updates this vector to be the component-wise product of this and another vector
        {
            x *= other.x;
            y *= other.y;
        }

        real scalarProduct(const Vector2 &other) const // Returns the scalar (dot) product of this and another vector
        {
            return x * other.x + y * other.y;
        }

        real operator*(const Vector2 &other) const // Returns the scalar (dot) product of this and another vector
        {
            return x * other.x + y * other.y;
        }

        real crossProd(const Vector2 &other) const // Returns the cross product of this and another vector
        {
            return x * other.y - y * other.x;
        }
    };

} // namespace Engine2D