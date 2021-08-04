#include <iostream>
#include <limits>
#include <vector>
/*Task1.Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк:*/
void Task1_test() {
  int a  = 1;
  
  do {
    std::cin>>a;
    if (std::cin.fail()) {
      std::cout<<"Error, please enter integer number"<<std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
      std::cout<<a<<std::endl;
      break;
      }
  } while(1);
  
}
/*Task2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.*/

std::ostream& endll (std::ostream& out){
  out << "\n";
  out << std::endl;
  return out;
}

void Task2_test() {
  std::cout<<"Hellow"<<endll;
  std::cout<<"World"<<endll;
}
/*Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false. 
void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.*/
typedef enum {CROSS, DIAMONDS, SPADES, HEARTS} Suits;
typedef enum {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace} Quality;
class Card {
  Suits m_suit;
  Quality m_quality;
  bool m_view;
  public:
  Card () {}
  void Set_Card (Suits suit, Quality quality, bool view){
    m_suit = suit;
    m_quality = quality;
    m_view = view;
  }
  Card (Suits suit, Quality quality, bool view) {
    Set_Card (suit, quality, view);
  }
  
  void Flip (){
     m_view = !m_view;
  }
  int GetValue () const {
    if (m_quality <= 10) return (int) m_quality;
    if (m_quality <= 13) return 10;
    if (m_quality == 14) return 1;
    return 0;
  }
  friend std::ostream& operator<< (std::ostream& os, const Card& card);
};
std::ostream& operator<< (std::ostream& os, const Card& card) {

     if (!card.m_view) os <<"XX"<<std::endl;
     else {
       std::string S[4] = {"CROSS", "DIAMONDS", "SPADES", "HEARTS"};
       std::string Q[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
       os<<S[card.m_suit]<<" "<<Q[card.m_quality - 2]<<std::endl;
     }
     return os;
  }
class Hand {
  std::vector<Card*>m_Cards;
  public:
 // Hand () {}
  void Add (Card *pCard) {
    m_Cards.push_back (pCard);
  }
  void Clear() {
    m_Cards.clear();
  }
  int GetTotal() const {
    std::vector<Card*>::const_iterator it_card; // объявляем итератор только для чтения
    it_card = m_Cards.begin(); // присваиваем ему начало вектора
    int Total = 0;
    int quality = 0;
    int aces = 0;
    while (it_card != m_Cards.end()) // пока итератор не достигнет конца
    {
      quality = (*it_card)->GetValue();
      if (quality != 1) Total+= quality; 
      else aces++;
      it_card++; 
    }
    while (((Total + aces*11) > 21)&&(aces > 0)){
      aces--;
      Total += 1;
    }
    Total += aces*11;
    return Total;
    }
    int Number_of_cards() const {return m_Cards.capacity();}
    Card* operator[] (int i) const{
       return m_Cards[i]; // 
    }
    
    virtual ~Hand(){}
    
};
class GenericPlayer: public Hand {
   std::string m_name;
   public:
   virtual bool IsHitting () = 0;
   bool IsBoosted () {
     return (GetTotal() > 21) ? true:false;
   } 
   void Bust() {
     std::cout<<"In hand of player "<<m_name<<std::endl;
   }
   std::string GetName () const {
     return m_name;
   }
   void SetName(std::string name) {
     m_name = name;
   }
   friend std::ostream& operator << (std::ostream& os, const GenericPlayer& GP);
   virtual ~GenericPlayer(){}
};
std::ostream& operator << (std::ostream& os, const GenericPlayer& GP) {
  os<<GP.m_name<<" "<<std::endl;
  for (int i = 0; i < GP.Number_of_cards(); i++)
    os << *(GP[i])<<std::endl;
  os<<GP.GetTotal()<<std::endl;
  return os;
}
class Player: public GenericPlayer {
  public:
  Player(std::string name){
    SetName(name);
  }
  virtual bool IsHitting () override {
    char answer = 0;
    do {
       std::cout<<"Please, enter Y, if you want another card. Enter N, if another card is not wanted."<<std::endl;
       std::cin>>answer;
       if (std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         continue;
       }
    } while((answer != 'Y')&&(answer != 'N'));
    if (answer == 'Y') return true;
    else return false;
  }
  void Win() const {
    std::string name = GetName();
    std::cout<<name<<"Is Win!"<<std::endl;
  } 
  void Lose() const {
    std::string name = GetName();
    std::cout<<name<<"Is lose!"<<std::endl;
  }
  void Push () const {  
    std::string name = GetName();
    std::cout<<name<<"Is Push!"<<std::endl;
    } 
};

void Task3_test () {
  Player Eugene("Eugene");
  std::cout<<std::boolalpha<<Eugene.IsHitting()<<std::endl;
  Eugene.Win();
  Eugene.Lose();
  Eugene.Push();
}
/*Task4*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class House: public GenericPlayer {
  public:
  House() {
    SetName("Dealer");
  }
   bool IsHitting() {
    if (GetTotal()<=16) return true;
    else return false;
  }
  void FlipFirstCard (GenericPlayer& GP) {
    GP[0] -> Flip();
  }
};
/*Task5*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Task4_5_test(){
  Card D[5];
  D[0].Set_Card (CROSS, King, true);
  D[1].Set_Card (SPADES, Queen, true);
  D[2].Set_Card (HEARTS, Ace, true);
  D[3].Set_Card (DIAMONDS, Ace, true);
//  D[4].Set_Card (SPADES, Ace, true);
  std::cout<<(D[0]);
  House house;
  for (int i = 0; i < 4; i++)
    house.Add(&D[i]);
  std::cout << house.GetTotal()<<std::endl;
  house.FlipFirstCard(house);
  std::cout<<(D[0])<<std::endl;
  std::cout<<house<<std::endl;
}




int main (void) {
  Task4_5_test();
  return 0;
}
