#pragma once
#include "Ball.hpp"
// #include "Point.hpp"
// #include "Velocity.hpp"

class Dust : public Ball {
  public:
    Dust(Point center, Velocity velocity, double leavetime) : Ball(center, velocity, 5, Color(255,0,0), false), m_leavetime(50) {}
    
    double getleavetime() const {
      return m_leavetime;
    }
    
    void setleavetime(){
      m_leavetime--;
    }
  private:
    double m_leavetime;
};
