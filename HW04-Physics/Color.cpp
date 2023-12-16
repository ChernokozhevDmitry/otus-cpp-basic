#include "Color.hpp"

Color::Color() = default;

Color::Color(double red, double green, double blue)
    : r{red}, g{green}, b{blue} {}

Color& Color::setR(double red) {
      this->r = red;
      return *this;
    }
    
Color& Color::setG(double green) {
      this->g = green;
      return *this;
    }

Color& Color::setB(double blue) {
      this->b = blue;
      return *this;
    }

double Color::red() const {
    return r;
}

double Color::green() const {
    return g;
}

double Color::blue() const {
    return b;
}

