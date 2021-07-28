
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

int main (void) {
   ArrayInt array;
   for (int i = 5; i > 0; i--)
     array.push_back(i);
   for (int i = 0; i < 5; i++)
     array.print_ArrayInt(i);
   std::cout<<std::endl;
   array.sort();
/*   for (int i = 0; i < 5; i++)
     std::cout<<array.pop_front()<<" ";
   std::cout<<std::endl;*/
   for (int i = 0; i < 5; i++)
      array.print_ArrayInt(i);
   std::cout<<std::endl;
   Task2();
  return 0;
}
=======
>>>>>>> parent of 2a2819e (lesson4)
