#include <iostream>
/*Task1*/
template <typename S>
S div (S a, S b){
  if (b == 0) throw "Division by zero";
  else return a/b;
}
template <typename S>
void Task1_test (S a, S b){
  try {
    double result = div<double>(a, b);
    std::cout<<result<<std::endl; }
  catch (const char* t){
    std::cout<<t<<std::endl;
  }
}
/*Task2*/
class Ex {
  double m_x;
public:
  Ex (double x) : m_x(x) {}
};
class Bar {
  double m_y;
public:
  Bar(): m_y(0){}
  void set (double a){
    if (m_y+a>100) throw Ex(a*m_y);
    else m_y = a;
  }
 double get() {return m_y;}
};
void Task2_test () {
  Bar bar;
  int32_t n = 1;
  while (1){
try {
    std::cin>>n;
    if (n != 0) bar.set(n);
    else break;
  }
  
  catch (Ex) {
    std::cout<<bar.get()<<" + "<<n<<" > 100"<<std::endl;
  }
  }
  
}
/*Task3*/
/*Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.*/
class OffTheField {
  std::string m_direction;  
public:
  OffTheField (std::string direction) : m_direction (direction){}
  void GetOffDirection () const {
    std::cout<<"The robot is in edge "<<m_direction<<std::endl;
  }
};
class IllegalCommand {
  std::string m_command;
public:
  IllegalCommand (std::string command) : m_command (command) {}
  void IllegalEnt () {
    std::cout<<"This word "<<m_command<<" is not a command"<<std::endl;
  }
};
 struct Position {
    int x; int y;
  };
class Robot {
  Position m_Position {}; 
public:
  Robot() {
    m_Position.x = 0;
    m_Position.y = 0;
  }
  Robot (int x, int y) {
    if (x < 0) throw OffTheField("left");
    if (x > 9) throw OffTheField("right");
    if (y < 0) throw OffTheField("back");
    if (y > 9) throw OffTheField ("straight");
    m_Position.x = x;
    m_Position.y = y;
  }
  const Position& GetPosition() const{
    return m_Position;
  }
  void StandPos (std::string direction) {
    if (direction.compare("left") == 0){
      if (m_Position.x == 0) throw OffTheField("left");
      else { 
      --m_Position.x;
      return;
      }
    }
    if (direction.compare("right") == 0){
      if (m_Position.x == 9) throw OffTheField("right");
      else { 
      ++m_Position.x;
      return;
      }    
    }
    if (direction.compare("straight") == 0){
      if (m_Position.y == 9) throw OffTheField ("straight");
      else { 
      ++m_Position.y;
      return;
      }
    }      
    if (direction.compare("back") == 0){
      if (m_Position.y == 0) throw OffTheField("back");
      else {
      --m_Position.y;
      return;
      } 
    }
    if (1) throw IllegalCommand (direction);
    }
};
void Task3_test () {
    Robot robot(4, 4);
  std::string command;
  while (1) {
    std::cin>>command;
    if (command == "out") break;
    try {
    robot.StandPos(command);
    Position position = robot.GetPosition();
    std::cout<<position.x<<" "<<position.y<<std::endl;
  }
  catch (OffTheField& border){
    border.GetOffDirection();
  }
  catch (IllegalCommand& command){
    command.IllegalEnt();
  }
  }
}
int main () {
  double a, b;
  a = 0; b = 0;
  Task1_test (a, b);
  Task2_test ();
  Task3_test ();
  return 0;
}
