#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(Point center, Velocity velocity, double radius, Color color, bool collidable);    
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getCollidable() const;
private:
    Point m_center;
    Velocity m_velocity;
    double m_radius;
    Color m_color;
    bool m_collidable;
};
