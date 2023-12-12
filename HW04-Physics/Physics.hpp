#pragma once
#include "Ball.hpp"
#include "Dust.hpp"
#include <vector>

class Physics {
  public:
    Physics(double timePerTick = 0.001);
    void setWorldBox(const Point& topLeft, const Point& bottomRight);
    void update(std::vector<Dust>& dusts, std::vector<Ball>& balls, size_t ticks) const;
    void setdust(std::vector<Dust>& dusts, Ball& a) const;

  private:
    void collideBalls(std::vector<Dust>& dusts, std::vector<Ball>& balls) const;
    void collideWithBox(std::vector<Ball>& balls) const;
    void move(std::vector<Ball>& balls) const;
    void move(std::vector<Dust>& dusts) const;
    void processCollision(std::vector<Dust>& dusts, Ball& a, Ball& b,
                          double distanceBetweenCenters2) const;

  private:
    Point topLeft;
    Point bottomRight;
    double timePerTick;
};
