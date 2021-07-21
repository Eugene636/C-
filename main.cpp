#include <iostream>
#include <cmath>


/*Task 1*/
class Figure {
  int m_line;
  public:
  Figure () {
    m_line = 1;
  }
  virtual double area() = 0;
  void set_line (int thickness) {
    m_line = thickness;
  }
};

class Parallelogram: public Figure {
  double m_first_side;
  double m_second_side;
  double m_corner;
  public:
  Parallelogram (double first_side,  double corner, double second_side) {
    m_first_side = first_side;
    m_second_side = second_side;
    m_corner = corner;
  }
  double area () override {
    return m_first_side*m_second_side*std::sin(m_corner);
  }


};


class Circle: public Figure {
  double m_radius;
  public:
  Circle (double radius) {
    m_radius = radius;
  }
  double area() override {
    return M_PI*std::pow(m_radius, 2);
  } 
  
};

class Rhombus: public Parallelogram {
  double m_side;
  double m_corner;
  public:
  Rhombus (double side, double corner) {
    m_side = side;
    m_corner = corner;
  }
  double area() override {
    return std::pow(side, 2)*sin(m_corner);
  }
};

class Rectangle: public Parallelogram {
  double m_first_side;
  double m_second_side:
  public:
  Rectangle (double first_side, double second_side) {
    m_first_side = first_side;
    m_second_side = second_side;
  }

};
  Rectangle::double area() override {
    return m_first_side*m_second_side;
  }

class Square: public Parallelogram {
  double m_side;
  public:
  Square() {}


};
int main (void) {






  return 0;
}
