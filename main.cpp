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
  double get_first_side () const {
    return m_first_side;
  }
  double get_second_side () const {
    return m_second_side;
  }
  double get_corner () const {
    return m_corner;
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
  public:
  Rhombus (double first_side,  double corner)
  : Parallelogram (first_side, corner, first_side) {}
  double area() override {
    return std::pow(get_first_side(), 2)*std::sin(get_corner());
  }
};

class Rectangle: public Parallelogram {
  public:
  Rectangle (double first_side, double second_side) 
  : Parallelogram (first_side, M_PI/2, second_side){}
  double area() override {
    return get_first_side()*get_second_side();
  }
};

class Square: public Parallelogram {
  public:
  Square(double first_side) 
  : Parallelogram (first_side, M_PI/2, first_side){}
  double area() override {
    return std::pow(get_first_side(), 2);
  }
};

/*Task 2*/
class Car {
  std::string m_company;
  std::string m_model;
  public:
  
  Car() {
    m_company = "default";
    m_model = "default";
    std::cout<<m_company<<" "<<m_model<<std::endl;
  }
  void set_company (std::string company){
    m_company = company;
  }
  void set_model (std::string model){
    m_model = model;
  }
  std::string get_company () const{
    return m_company;
  }
  std::string get_model () const{
    return m_model;
  }
};
class PassengerCar : virtual public Car {
  public:
  PassengerCar () {
  set_company("Lada");
  set_model("Granta");
  std::cout<<"Passenger car "<<get_company()<<" "<<get_model()<<std::endl;
  }
};
class Bus : virtual  public Car {
  public:
  Bus () {
  set_company("LIAZ");
  set_model("Скотовоз");
  std::cout<<"Bus "<<get_company()<<" "<<get_model()<<std::endl;
  }
};
class Minivan: public Bus, public PassengerCar {
  public:
  Minivan () {
    set_company("Ford");
    set_model("Torneo");
    std::cout <<"Minivan "<<get_company()<<" "<<get_model()<<std::endl;
  } 
};
/*Task 3 Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
*/
class Fraction {
  int m_numerator;
  int m_denominator;

  public:
  Fraction(){
    m_numerator = 1;
    m_denominator = 0;
  }
  void set_fraction(int, int);
  Fraction (int numerator,int denominator){
      set_Fraction(numerator, denominator);
  }
  void set_Fraction (int numerator, int denominator) {
      if (denominator == 0){ 
      std::cout<<"Divider by zero!"<<std::endl;
      m_denominator = 1;
      m_numerator = 0;
    }
    else {
      m_numerator = numerator;
      m_denominator = denominator;
    }
  }
  int get_numerator () const{
    return m_numerator;
  }
  int get_denominator () const{
    return m_denominator;
  }
  void print_fraction () const {
  
  std::cout<<get_numerator()<<"/"<<get_denominator()<<std::endl;
  
  }
  Fraction operator- () const {
    return Fraction (m_numerator, -m_denominator);
  }
  
  ~Fraction(){}
};
Fraction* operator+ (const Fraction &fraction1, const Fraction &fraction2){
 int numerator, denominator;
 denominator = fraction1.get_denominator()*fraction2.get_denominator();
 numerator = fraction1.get_numerator()*fraction2.get_denominator() + fraction2.get_numerator()*fraction1.get_denominator();
 Fraction* sum = new Fraction;
 sum->set_Fraction(numerator, denominator);
 return sum;
}
Fraction* operator- (const Fraction &fraction1, const Fraction &fraction2){
  int numerator, denominator;
  denominator = fraction1.get_denominator()*fraction2.get_denominator();
  numerator = fraction1.get_numerator()*fraction2.get_denominator() - fraction2.get_numerator()*fraction1.get_denominator();
 Fraction* sub = new Fraction;
 sub->set_Fraction(numerator, denominator);
 return sub;
}
Fraction* operator/ (const Fraction &fraction1, const Fraction &fraction2){
  int numerator, denominator;
  denominator = fraction1.get_denominator()*fraction2.get_numerator();
  numerator  = fraction1.get_numerator()*fraction2.get_denominator();
  Fraction* div = new Fraction;
  div->set_Fraction(numerator, denominator);
  return div;
}
Fraction* operator* (const Fraction &fraction1, const Fraction &fraction2){
  int numerator, denominator;
  denominator = fraction1.get_denominator()*fraction2.get_denominator();
  numerator  = fraction1.get_numerator()*fraction2.get_numerator();
  Fraction* mul = new Fraction;
  mul->set_Fraction(numerator, denominator);
  return mul;
}
bool operator> (const Fraction &fraction1, const Fraction &fraction2) {
    Fraction* res = fraction1 - fraction2;
    if (((res->get_numerator() > 0)&&(res->get_denominator() > 0))||((res->get_numerator() < 0)&&(res->get_denominator() < 0))) return true; 
    else return false;
  }
bool operator== (const Fraction &fraction1, const Fraction &fraction2){
  Fraction* res = fraction1 - fraction2;
  if (res->get_numerator() == 0) return true;
  else return false;
}
bool operator!= (const Fraction &fraction1, const Fraction &fraction2) {
  if (fraction1 == fraction2) return false;
  else return true;
}
bool operator< (const Fraction &fraction1, const Fraction &fraction2) {
  if (fraction1 == fraction2) return false;
  if (fraction1 > fraction2) return false;
  return true;
}
bool operator>= (const Fraction &fraction1, const Fraction &fraction2) {
  if (fraction1 == fraction2) return true;
  if (fraction1 > fraction2) return true;
  return false;
}
bool operator <= (const Fraction &fraction1, const Fraction &fraction2){
  if (fraction1 == fraction2) return true;
  if (fraction1 < fraction2) return true;
  return false;
}
//Fraction
int main (void) {
 {//Task 1 test
  Square square (6);
  std::cout<<square.area()<<std::endl;
  Rectangle rectangle (2, 3);
  std::cout<<rectangle.area()<<std::endl;
  }
  {
  //Task 2 test
  Car car;
  PassengerCar sedan;
  Bus bus ;
  Minivan minivan;
  }
  Fraction fraction1 (1, 3);
  Fraction fraction2 (2, 5);
  Fraction* sum = fraction1 + fraction2;
  sum->print_fraction();
  delete sum;
  Fraction* sub = fraction1 - fraction2;
  sub->print_fraction();
  delete sub;
  Fraction* div = fraction1/fraction2;
  div->print_fraction();
  delete div;
  Fraction* mul = fraction1*fraction2;
  mul->print_fraction();
  Fraction rev = -fraction1;
  rev.print_fraction();
  if (fraction2 < fraction1) {
    fraction2.print_fraction();
    std::cout<<"<";
    fraction1.print_fraction();
  }
  else {
    fraction2.print_fraction();
    std::cout<<">";
    fraction1.print_fraction();
  }
  Fraction fraction3(2, 5);
  if (!(fraction2 != fraction3)) std::cout<<"This fractions are equal"<<std::endl;
  else std::cout<<"This fractions are not equal"<<std::endl;
  if (fraction2 <= fraction3) std::cout<<fraction2.get_numerator()<<"/"<<fraction2.get_denominator()<<"<="<<fraction3.get_numerator()<<"/"<<fraction3.get_denominator()<<std::endl;
  

  return 0;
}
