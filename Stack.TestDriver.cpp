//Programmer: Ethan Chiang
//Programmer ID: 1538719

#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h" // ifndef test

struct testType
{
  double num;
};

int main()
{
  cout << "Programmer: Ethan Yi Chiang\n"
       << "Programmer ID: 1538719\n"
       << "File: " << __FILE__ << endl;

  //Double Test
  Stack<testType> da;

  //Stack::size
  cout << "Stack test: \n"
       << "-----------------"
       << "\nTesting Stack::size\n"
       << "EXPECTED: 0\n"
       << "ACTUAL: " << da.size() << endl;
  assert(0 == da.size());
  cout << "Pass!\n\n";

  //Stack::push & peek
  cout << "Tesing Stack::peek & Stack::push \n";
  testType a; a.num = 1.1;
  da.push(a);
  cout << "EXPECTED: 1.1\n"
       << "ACTUAL: " << da.peek().num << endl;
  assert(1.1 == da.peek().num);
  cout << "Pass!\n\n";

  //Stack::pop
  cout << "Testing Stack::pop\n";
  testType b; b.num = 2.2;
  da.push(b);
  cout << "Before pop: " << da.peek().num << endl;
  da.pop();
  cout << "After pop: " << da.peek().num << endl;
  assert(1.1 == da.peek().num);
  cout << "Pass!\n\n";

  //copy constructor
  cout << "Testing assignment opetrator\n";
  da.push(b);
  Stack<testType> db = da;
  assert(da.size() == db.size());
  while(da.size() != 0)
  {
    assert(da.peek().num == db.peek().num);
    da.pop(); db.pop();
  }
  cout << "Pass!\n\n";

  //Assignment operator
  cout << "Tesing assignment operator\n";
  da.push(a); da.push(b);
  Stack<testType> dc; dc = da;
  assert(da.size() == dc.size());
  while(dc.size() != 0)
  {
    assert(da.peek().num == dc.peek().num);
    da.pop(); dc.pop();
  }
  cout << "Pass!\n\n";

  //Stack::capacity
  cout << "Testnig Satck::capacity\n"
       << "Default capacity: 2\n";
  Stack<testType> dd;
  testType c, d, e;
  c.num = 3.3; d.num = 4.4; e.num = 5.5;
  dd.push(a); dd.push(b); dd.push(c); dd.push(d); dd.push(e);
  cout << "After pushing 5 now element, size is: " << dd.size() << endl;
  assert(5 == dd.size());
  cout << "Capcity had doubled twice!\n"
       << "Pass!\n\n";

  //Stack::clear & empty
  cout << "Testing Stack::clear & empty\n";
  da.clear();
  assert(da.empty());
  cout << "Pass!\n\n";

  //constant pbject test //test getters (empty & size)
  cout << "Constant object test: \n";
  const Stack<testType> de = dd;
  cout << "size: " << de.size() << endl;
  if(dd.empty()) cout << "Its empty!\n";
  else if(!dd.empty()) cout << "Its NOT empty!\n";
  else cout << "Oops!\n";

  return 0;
}
