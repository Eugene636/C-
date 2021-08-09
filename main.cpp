#include <iostream>
#include <memory>
#include <limits>
#include <vector>
#include <algorithm>
#include <random>
#include "BlackJack.cpp"
/*Task1*/
class Date {
  int m_day {};
  int m_month {};
  int m_year {};
  public:
  Date (int day, int month, int year) 
  : m_day {day}, m_month {month}, m_year{year} {}
  void SetDay (int);
  void SetMonth (int);
  void SetYear (int);
  const int& GetDay() const;
  const int& GetMonth() const;
  const int& GetYear() const;
  friend std::ostream& operator << (std::ostream& os, const Date& date);
};
void Date::SetDay(int day){
  if ((day > 31)||(day < 1)) {
    m_day = 1;
    std::cout<<"Error day value"<<std::endl;
  }
  m_day = day;
}
void Date::SetMonth(int month){
  if ((month > 12)||(month < 1)) {
    m_month = 1;
    std::cout<<"Error month value"<<std::endl;
  }
  m_month = month;
}
void Date::SetYear(int year){
  if (year < 1) {
    m_year = 1;
    std::cout<<"Error month value"<<std::endl;
  }
  m_year = year;
}
const int& Date::GetDay() const {return m_day;}
const int& Date::GetMonth() const {return m_month;}
const int& Date::GetYear() const {return m_year;}
std::ostream& operator << (std::ostream& os, const Date& date) {
  os<<"Date is "<<date.m_day<<"/"<<date.m_month<<"/"<<date.m_year<<std::endl;
  return os;
}
void Task1_test (){
    std::unique_ptr<Date> today (new Date(5, 8, 2021));
    if (today) std::cout<<"today is not nullptr"<<std::endl;
    std::cout<<today->GetDay()<<today->GetMonth()<<today->GetYear()<<std::endl;
    std::cout<<*today<<std::endl;
    std::unique_ptr<Date>pdate(std::move(today));
    std::cout<<*pdate<<std::endl;
    if (pdate) std::cout<<"pdate is not nullptr"<<std::endl;
    if (today == nullptr) std::cout<<"Today is a nullptr"<<std::endl;
}

/*Task2*/ 

Date Date_consider (const std::unique_ptr <Date>& date1, const std::unique_ptr <Date>& date2){
  if (date1 -> GetYear() > date2 -> GetYear()) return *date1;
    else if(date1 ->GetMonth() > date2 -> GetMonth()) return *date1;
         else if (date1 -> GetDay() > date2 -> GetDay()) return *date1;
  return *date2;
}
void swap_date (std::unique_ptr <Date>& date1, std::unique_ptr <Date>& date2) {
  std::unique_ptr <Date> temp (std::move(date1));
  date1 = std::move(date2);
  date2 = std::move(temp);
}
void Task2_test () {
  std::unique_ptr <Date> date1 (new Date(7, 8, 2021));
  std::unique_ptr <Date> date2 (new Date(6, 8, 2021));
  Date date = Date_consider(date1, date2); 
  std::cout<<date<<std::endl;
  std::cout<<*date1<<std::endl;
  std::cout<<*date2<<std::endl;
  swap_date (date1, date2);
  std::cout<<*date1<<std::endl;
  std::cout<<*date2<<std::endl;
}
/*Task3*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Deck: public Hand {
  std::vector <Card*> m_pCard;
  void Shuffle () {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_pCard.begin(), m_pCard.end(), g);
  }
  void Populate () {
    for (int i = static_cast<int>(CROSS); i <= static_cast<int>(HEARTS); ++i)
      for (int j = static_cast<int>(Two); j <= static_cast<int>(Ace); ++j)  {
        m_pCard.push_back(new Card (static_cast<Suits> (i), static_cast<Quality> (j), true)); 
    }
    Shuffle();
  }
public:
  Deck () {
    Populate();
  }
  void Deal (Hand& aHand) {
    int Cd = m_pCard.size();
    --Cd;
    aHand.Add (m_pCard[Cd]);
    m_pCard.pop_back();
}
void AdditionalCards (Player& player) {
  while (player.IsHitting() == true)
    Deal(player);
}
void AdditionalCards(House& house){
  while (house.IsHitting() == true)
    Deal(house);
}
};
/*Task4*/
class Game {
  Deck  m_deck {};
  House m_house {};
  std::vector<Player>m_players {};
  public:
  Game () {
    std::string name;
    do {
    std::cout<<"Enter a new name of player and push enter. If you want begin game, enter word RUN and press enter"<<std::endl;
    std::cin>>name;
    if (name != "RUN"){
      Player player(name);
      m_players.push_back(player);
     }
    } while (name != "RUN");
  }
void  play () {
    m_deck.Deal(m_house);
    m_deck.Deal(m_house);
    std::cout<<m_house<<std::endl;
    m_house.FlipFirstCard(m_house);
    std::cout<<m_players.size()<<std::endl;
    for (int i = 0; i < m_players.size(); i++){
      m_deck.Deal(m_players[i]);
      std::cout<<"First card"<<std::endl;
      m_deck.Deal(m_players[i]);
      std::cout<<"Second card"<<std::endl;
    }
    std::cout<<m_house<<std::endl;
    for (int i = 0; i < m_players.size(); i++)
      std::cout<<m_players[i]<<std::endl;
    for (int i = 0; i < m_players.size(); i++)
      m_deck.AdditionalCards(m_players[i]);
    m_house.FlipFirstCard(m_house);
    m_deck.AdditionalCards(m_house);
    if (m_house.IsBoosted()) std::cout<<"House is lost"<<std::endl;
    std::vector <Player>::iterator it;
    for(it = m_players.begin(); it != m_players.end();){
      if (it->IsBoosted()) {
        it->Lose();
        m_players.erase(it);
        continue;
      }
      else if(it->GetTotal() == 21){
        it->Win();
        m_players.erase(it);
        continue;
      }     
        else it++;
      }
    Player* pPlayer = &m_players[0];
    for (int i = 0; i < m_players.size(); i++){
       if (pPlayer->GetTotal() < m_players[i + 1].GetTotal()) pPlayer = &m_players[i + 1];
    }
    pPlayer->Win();
  }
};
/*Task5*/
int main (){

  char answer = 'y';
  while (answer == 'y'){
  Game game; 
  std::cout<<"Construct"<<std::endl;   
  game.play();
  std::cin>>answer;
  }
    
  return 0;
}
