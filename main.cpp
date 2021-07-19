#include <iostream>
#include <cstdlib>
/*Task_1*/
#define Number_students  10
class Person {
   int m_Age{};
   std::string m_Name{};
   int m_weight{};
   std::string m_sex{}; 
  public:
  Person ()
  : m_Age{18}
  , m_Name{"Vasiliy"}
  , m_weight{65}
  , m_sex{"Male"} {}
  void set_Person (std::string name, double weight, std::string sex, int age){
    m_Name = name;
    m_weight = weight;
    m_sex = sex;
    m_Age = age;
  }
  void print_Person () {
    std::cout << m_Name<<" "<<m_Age<<" "<<m_weight<<" "<<m_sex<<std::endl;
  }
};
class Student : public  Person {
 
  int m_year_of_study{};
  int m_order_number{};
  public:
  Student ()
  : m_year_of_study{1} 
  , m_order_number {1} {}
  void new_student(int year, int number) {
    m_year_of_study = year;
    m_order_number = number;
  }
  void go_next_year () {
    m_year_of_study++; 
  }
};
class Group {
  Student student[Number_students];
  public:
  Group (){};
  void set_student (int i, int year, int age, std::string sex, std::string name) {
    student[i].new_student (year, i);
    student[i].set_Person(name, 65, sex, age);
  }
  void print_student (int i){
      student[i].print_Person();
  }
};
void Task_1 () {
  Group group;
  group.set_student (0, 1, 18, "female", "Paraskeva");
  group.print_student(0);
  group.print_student(1);



}

/*Task 2*/
class Fruit {
  std::string m_name;
  std::string m_color;
  public:
  Fruit(){}
  void set_Fruit (std::string name, std::string color){
    m_name = name;
    m_color = color;
  }
  std::string getName () const {
    return m_name;
  }
  std::string getColor () const {
    return m_color;
  }
};
class Apple : public Fruit {
  public:
  Apple (){}
  Apple (std::string color){
  set_Fruit ("Apple", "red");
  }
};
class Banana : public Fruit {
   public:
   Banana (){
   set_Fruit("banana", "yellow");
   }
}; 
class GrannySmyth : public Apple {
  public:
  GrannySmyth () {
    set_Fruit ("GrannySmith", "green"); 
   }
};
void Task_2 () {
  Apple a("red");
  Banana b;
  GrannySmyth c;
  std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
  std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}
/*Task3*/
typedef enum {CROSS, DIAMONDS, SPADES, HEARTS} Suits;
typedef enum {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace} Quality;
typedef struct {
  Suits suit;
  Quality quality;

} Card;

class Deck {
  Card card;//все карты 
  public:
  Deck () {}
  friend class Player;//чтобы была возможность обращаться к колоде
  friend class Dealer;
};
class Play : public  Deck {
  public:
  Play (){}

};
class Player: public Deck {

  public:
  Player(){}

};

class Dealer : public Player{
  public:
  Dealer(){}


};
int main (void) {
  Task_1 ();
  Task_2 ();



  return 0;
}
