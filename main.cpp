#include <iostream>
#include <vector>

/*Task 1*/
template <typename T>
class Pair1 {
  T m_first;
  T m_second;
public:
  Pair1 (T first, T second) {
  m_first = first;
  m_second = second;
  }
  T first () const {return m_first;}
  T second () const {return m_second;}
};
void Task1_test () {
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
/*Task 2*/
template <typename T, typename S>
class Pair {
  T m_first;
  S m_second;
public:
  Pair (T first, S second) {
  m_first = first;
  m_second = second;
  }
  T first () const {return m_first;}
  S second () const {return m_second;}
};
void Task2_test () {
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}


/*Task3*/
template <typename S> class Pair <std::string, S> {
  std::string m_first;
  S m_second; 
public:
  Pair (std::string first, S second) {
  m_first = first;
  m_second = second;
  }
  std::string first () const {return m_first;}
  S second () const {return m_second;}
};
template <typename S> 
class StringValuePair : public Pair<std::string, S> {
  public:
  StringValuePair(std::string first, S second)
  : Pair<std::string, S>(first, second) {}

};
void Task3_test() {
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}
/*Task 4*/

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
    if (m_view) m_view = false;
    else m_view = true;
  }
  int GetValue () const {
    if (m_quality <= 10) return (int) m_quality;
    if (m_quality <= 13) return 10;
    if (m_quality == 14) return 1;
    return 0;
  }
};
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
  int GetTotal() {
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
   virtual ~GenericPlayer(){}
};

int main (void) {
  Task1_test();
  Task2_test();
  Task3_test();
  return 0;
}
