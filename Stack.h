//Programmer: Ethan Chiang
//Programmer ID: 1538719

#ifndef Stack_h
#define Stack_h

#include <algorithm>
using namespace std;

template <typename V>
class Stack
{
  V* values;
  int cap;
  int siz;
  void capacity(int);
  
  public:
  Stack(int=2); //main consturcot
  Stack(const Stack<V>&); //copy constructor
  ~Stack() {delete [ ] values;}
  Stack<V>& operator=(const Stack<V>&);
  void push(const V&);
  V& peek();
  void pop() {if (siz > 0) --siz;}
  void clear() {siz = 0;}
  int size() const {return siz;}
  bool empty() const {return siz == 0 ? true : false;}
};

//constructor(s)
template <typename V>
Stack<V>::Stack(int cap)
{
  this->cap = cap;
  siz = 0;
  values = new V[cap];

  for(int i = 0; i < cap; i++)
    values[i] = V();
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  cap = original.cap;
  siz = original.siz;
  values = new V[cap];
  for(int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

//push
template <typename V>
void Stack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap); // double the capacity if full
  values[siz] = value;
  ++siz;
}

//peek
template <typename V>
V& Stack<V>::peek()
{
  if(siz-1 < 0) return values[0];
  if(siz-1 >= cap) capacity(2 * cap);
  return values[siz-1];
}

//double capacity
template <typename V>
void Stack<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap); 

  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  for (int i = limit; i < cap; i++)
    temp[i] = V();

  delete [ ] values; 
  values = temp;
  this->cap = cap;
}

//assignment operator
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original) // of it's not a self copy...
  {
    // do what the destructor does
    delete [ ] values;

    // do what the copy constructor does
    cap = original.cap; // still just a copy 
    siz = original.siz;
    values = new V[cap]; // not a copy -- new object gets its own array
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
      values[i] = original.values[i]; // ...to the copy
  }
  return *this; // return a self reference
}

#endif