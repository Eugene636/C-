#include <iostream>
#include <cstdint>
#include <cmath>
/*1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate,*/ class Power  {
    double basement{};
    double pow{};
  public:
   Power () 
 : basement {5}
 , pow {2} {} 
  
   void set (double bas, double power){ 
     basement = bas;
     pow = power;
   }
   
  void calculate () {
    double out = std::pow (basement, pow);
    std::cout <<out<<std::endl;
  }


};
void Test_1 (void) {
  Power power;
//  power.set (4, 2);
  power.calculate ();
  power.set (4, 2);
  power.calculate ();
} 
/*2.Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.*/
class RGBA {
  std::uint8_t m_red{};
  std::uint8_t m_green{};
  std::uint8_t m_blue{};
  std::uint8_t m_alpha{};
  public:
  RGBA () 
    : m_red {0}
    , m_green {0}
    , m_blue {0}
    , m_alpha {255}{}
  RGBA  (std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
    : m_red{red}
    , m_green{green}
    , m_blue{blue}
    , m_alpha{alpha}{}
  void print (void) {
  
    std::cout <<m_red<<" "<<m_green<<" "<<m_blue<<" "<<m_alpha<<std::endl;
  }



};
void Test_2 (void) {
 RGBA color;
 color.print();
 RGBA second_color (48, 49, 50, 51);
 second_color.print ();

}
/*3.Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;
public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
public-метод с именем print(), который будет выводить все значения стека.
Код main():
int main()
{
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    
    return 0;
}*/

class Stack {
    std::uint16_t Memory[10] {};
    std::uint16_t tale{};
  public:
    Stack () 
    : tale{0}
    , Memory{0}{}
    void reset(){
    tale = 0;
    for (int i = 0; i < 10; i++)
      Memory[i] = 0;
  }
   bool push (int ins) {
     if (tale == 10) return false;
     else {
       Memory[tale++] = ins;
       return true;
   }
   }
   std::uint16_t pop (void) {
     if (tale == 0) {
       std::cout <<std::endl<<"No values in this stack!"<<std::endl;
       return 0;
       }
     else return Memory[tale--];
   }
   void print (void) {
     std::cout<<"( ";
     for (int i = 0; i < tale; i++)
       std::cout<<Memory[i]<<" ";
     std::cout<<")"<<std::endl;
   
   } 
   
};
void Test_3 (void) {
  Stack stack;
  stack.reset();
  stack.print();
    
  stack.push(3);
  stack.push(7);
  stack.push(5);
  stack.print();
    
  stack.pop();
  stack.print();
    
  stack.pop();
  stack.pop();
  stack.print();

}

int main (void) {
  Test_1 ();
  Test_2 ();
  Test_3 ();

  return 0;
}
