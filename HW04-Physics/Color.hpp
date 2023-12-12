#pragma once
#include <fstream>

class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;

  private:
    double r{};
    double g{};
    double b{};
  
  public:
  friend std::istream& operator>>(std::istream& is, Color& color);

};

inline std::istream& operator>>(std::istream& is, Color& color) {
    is >> color.r >> color.g >> color.b;
    return is;
}