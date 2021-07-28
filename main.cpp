
<<<<<<< HEAD
class ArrayInt
{
private:
    int m_length;
    int *m_data;
    void swap_int(int &a, int &b){
     int temp;
     temp = a;
     a = b;
     b = temp;
   }
public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
    m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    int& operator[](int index);

    
    void push_back(int);
    int pop_back ();
    int pop_front ();
    void insertBefore (int value, int index);
    void sort();
    void print_ArrayInt (int index);
    
    ~ArrayInt()
    {
        delete[] m_data;
    }
};
    int& ArrayInt::operator[](int index)
    {
       assert(index >= 0 && index < m_length);
       return m_data[index];
    }
    
   void ArrayInt::push_back(int value) { insertBefore(value, m_length); }
   void ArrayInt::insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы до index-а
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }


   int ArrayInt::pop_back() {
   if (m_length > 0) {
     int popped = m_data[m_length - 1];
     m_length--;
     int* data = new int[m_length];
     for (int i = 0; i < m_length; i++)
       data[i] = m_data[i];
     delete[] m_data;
     m_data = data;
     return popped;
   }
     return 0;
   }
   int ArrayInt::pop_front() {
   if (m_length > 0) {
     int popped = m_data[0];
     int* data = new int[m_length - 1];
     for (int i = 1; i < m_length; i++)
       data[i - 1] = m_data[i];
     delete[] m_data;
     m_data = data;
     m_length--;
     return popped;
   }
     return 0;
   }

   void ArrayInt::sort() {
     for (int j = 0; j < m_length; j++)
        for (int i = 0; i < m_length - 1; i++){
          if (m_data[i] > m_data[i + 1]) swap_int(m_data[i], m_data[i + 1]);
        }
   }
   void ArrayInt::print_ArrayInt(int index){
     std::cout<<m_data[index]<<" "; 
   }
void Task1_test(void){

}
/*Task2 Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм*/
void Task2 (void){
    std::vector<int> myVector;
    for (int count = 0; count < 1; count++)
        myVector.push_back(1);
    for (int count = 0; count < 7; count++)
        myVector.push_back(2);
    for (int count = 0; count < 4; count++)
        myVector.push_back(5);    
    std::sort(myVector.begin(), myVector.end());
    for (int i = 0; i < myVector.size(); i++)
       std::cout << myVector[i] << " ";
    std::cout<<std::endl;
    int number = 0;
    for (int i = 0; i < myVector.size() - 1; i++)
      if (myVector[i] == myVector[i + 1]) number++;
    std::cout << (myVector.size() - number);
}

//
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

class Hand: private Card {

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
};

void Task3_test(){
  Card D[5];
  D[0].Set_Card (CROSS, King, true);
  D[1].Set_Card (SPADES, Queen, true);
  D[2].Set_Card (HEARTS, Ace, true);
  D[3].Set_Card (DIAMONDS, Ace, true);
//  D[4].Set_Card (SPADES, Ace, true);
  
  Hand hand;
  for (int i = 0; i < 4; i++)
    hand.Add(&D[i]);
  std::cout << hand.GetTotal()<<std::endl;
}
int main (void) {
 //  Task1_test();
      ArrayInt array;
   for (int i = 5; i > 0; i--)
     array.push_back(i);
   for (int i = 0; i < 5; i++)
     array.print_ArrayInt(i);
   std::cout<<std::endl;
   array.sort();
   for (int i = 0; i < 5; i++)
     std::cout<<array.pop_front()<<" ";
   std::cout<<std::endl;
   for (int i = 0; i < 5; i++)
      array.print_ArrayInt(i);
   std::cout<<std::endl;
   Task2();
   Task3_test();
  return 0;
}
=======
>>>>>>> parent of 2a2819e (lesson4)
