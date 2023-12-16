#pragma once
#include <fstream>

class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    Color& setR(double red);
    Color& setG(double green);
    Color& setB(double blue);
    double red() const;
    double green() const;
    double blue() const;

  private:
    double r{};
    double g{};
    double b{};
};

inline std::istream& operator>>(std::istream& is, Color& color) {
    double r, g, b;
    is >> r >> g >> b;
    color.setR(r).setG(g).setB(b);
    return is;
}