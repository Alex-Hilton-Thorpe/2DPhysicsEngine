#include "precision.h"
#include "core.h"
#include <limits>

namespace Engine2D
{
    class Particle
    {
    private:
        Vector2 position;     // Position of the particle
        Vector2 velocity;     // Velocity of the particle
        Vector2 acceleration; // Acceleration of the particle
        Vector2 gravity;      // Gravity affecting the particle
        Vector2 accumulatedForce; // Accumulated force acting on the particle
        real damping;         // Damping factor to simulate drag or friction
        real inverseMass;     // Inverse mass of the particle, allows for easier calculations (0 means infinite mass)

    public:
        Particle() : position(), velocity(), acceleration(), gravity(), accumulatedForce(), damping(0.99f), inverseMass(1.0f) {} // Default constructor initializing the particle with default values

        void setPosition(const Vector2 &pos) // Sets the position of the particle
        {
            position = pos;
        }

        Vector2 getPosition() const // Returns the position of the particle
        {
            return position;
        }

        void setVelocity(const Vector2 &vel) // Sets the velocity of the particle
        {
            velocity = vel;
        }

        Vector2 getVelocity() const // Returns the velocity of the particle
        {
            return velocity;
        }

        void setAcceleration(const Vector2 &acc) // Sets the acceleration of the particle
        {
            acceleration = acc;
        }

        Vector2 getAcceleration() const // Returns the acceleration of the particle
        {
            return acceleration;
        }

        void setGravity(const Vector2 &grav) // Sets the gravity affecting the particle
        {
            gravity = grav;
        }

        Vector2 getGravity() const // Returns the gravity affecting the particle
        {
            return gravity;
        }

        void addForce(const Vector2 &force) // Adds a force to the particle's accumulated force
        {
            accumulatedForce += force;
        }

        void setDamping(real damp) // Sets the damping factor of the particle
        {
            damping = damp;
        }

        real getDamping() const // Returns the damping factor of the particle
        {
            return damping;
        }

        void setMass(real mass) // Sets the mass of the particle, calculates inverse mass
        {
            if (mass > 0)
            {
                inverseMass = 1.0f / mass;
            }
            else
            {
                inverseMass = 0; // Infinite mass
            }
        }

        real getMass() const // Returns the mass of the particle
        {
            if (inverseMass == 0)
            {
                return std::numeric_limits<real>::infinity(); // Infinite mass
            }
            else
            {
                return 1.0f / inverseMass;
            }
        }

        void integrate(real duration) // Integrates the particle's state over a given duration, updating position, velocity, acceleration etc based on acceleration and gravity
        {
            if (inverseMass == 0.0f)
            {
                return; // Infinite mass objects do not move
            }
            else
            {
                acceleration += accumulatedForce * inverseMass; // Update acceleration based on accumulated force
                velocity += acceleration * duration + velocity * damping; // Update velocity based on acceleration and apply damping
                position += position + velocity * duration + acceleration * duration * duration * 0.5; // Update position based on velocity and acceleration
            }
        }
    };
} // namespace Engine2D