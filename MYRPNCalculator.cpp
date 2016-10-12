//Programmer: Ethan Chiang
//Programmer ID: 1538719

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "Stack.h"

void RPNCal(Stack<double>& num, const string& math);
void output(const Stack<double>& num);
int toMath(const string&);

int main()
{
  cout << "Programmer: Ethan Yi Chiang\n"
       << "Programmer ID: 1538719\n"
       << "File: " << __FILE__ << endl;

  string buf;
  Stack<double> num;

  do
  {
    cout << "Enter: ";
    if(num.size() != 0) output(num);
    cin >> buf;

    if(buf == "Q" || buf == "q") break;
    else if(buf == "+" || buf == "-" || buf == "*" || buf == "/")
    {
      RPNCal(num, buf);
    }
    else
      num.push(atof(buf.c_str()));
  }while(buf != "Q" || buf != "q");

  return 0;
}

//output function
void output(const Stack<double>& num)
{
  Stack<double> copy = num;

  while(copy.size() != 0)
  {
    cout << copy.peek() << " ";
    copy.pop();
  }
}

//RPN
void RPNCal(Stack<double>& num,const string& math)
{
  if(num.size() >= 2)
  {
    switch(toMath(math))
    {
      case 1:
      {
        double a = num.peek();
        num.pop();

        double b = num.peek();
        num.pop();

        num.push(a+b);
        break;
      }
      case 2:
      {
        double a = num.peek();
        num.pop();

        double b = num.peek();
        num.pop();

        num.push(b-a);
        break;
      }
      case 3:
      {
        double a = num.peek();
        num.pop();

        double b = num.peek();
        num.pop();

        num.push(b*a);
        break;
      }
      case 4:
      {
        double a = num.peek();
        num.pop();

        double b = num.peek();
        num.pop();

        num.push(b/a);
        break;
      }
    }
  }
}

int toMath(const string& math)
{
  if(math == "+") return 1;
  else if(math == "-") return 2;
  else if(math == "*") return 3;
  else if(math == "/") return 4;
  else return 0;
}
