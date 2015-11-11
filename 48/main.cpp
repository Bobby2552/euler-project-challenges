#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

void convertToBinary(int);
string NumberToString(long);

string bin = "";

int main() {
  long tenTen = pow(10, 10);
  unsigned long long sum = 0;

  
  
  
}

string convertToBinary(int n)
{
  if (n / 2 != 0) {
    convertToBinary(n / 2);
  }
  return NumberToString(n % 2);
}

string NumberToString (long Number)
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

long powerMod(int a, int b, long mod) {
  
}

string compileString(int n) {
  string ret = "";

  //TODO use ret's pointer
}
