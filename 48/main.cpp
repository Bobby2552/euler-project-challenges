#include <iostream>
#include <math.h>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

void convertToBinary(int);
string NumberToString(long);
long powerMod(int, int, long);
uint128_t bigPow(uint128_t, int);

string bin = "";

int main() {
  long tenTen = pow(10, 10);
  unsigned long long sum = 0;

  powerMod(999, 999, (long)pow(10, 10));
}

void convertToBinary(int n)
{
  if (n / 2 != 0) {
    convertToBinary(n / 2);
  }
  bin += NumberToString(n % 2);
}

string NumberToString (long Number)
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

long powerMod(int a, int b, long mod) {
  convertToBinary(b);
  long long modulos [bin.length()];
  if (b >= 1) modulos[0] = (long long)pow(a, 1) % mod;
  if (b >= 2) modulos[1] = (long long)pow(a, 2) % mod; 
  int exps [bin.length()];
  exps[0] = 1;
  //if (b == 2) exps[1] = 2;
  
  for (int i = 1; i < bin.length(); i++) {
    if (bin.length() > 1) {
      exps[i] = exps[i - 1] * 2;
    }
    else break;
  }

  if (bin.length() > 2) {
  for (int i = 2; i < bin.length(); i++) {
    modulos[i] = (uint128_t)pow(modulos[i - 1], 2) % mod;
  }
  }

  for (int i = 0; i < bin.length(); i++) {
    cout << modulos[i] << "\t";
  }
  
  int binArr [bin.length()];
  cout << bin << "\n";
  for (int i = 0; i < bin.length(); i++) {
    binArr[i] = 49 - bin.c_str()[i];
    //    cout << binArr[i] << ", ";
    if (binArr[i] == 0) binArr[i] = 1;
    else binArr[i] = 0;
    cout << binArr[i] << "\t";
  }

  uint128_t premod = 1;
  for (int i = 0; i < bin.length(); i++) {
    if (binArr[i] == 1) {
      premod *= modulos[i];
    }
  }

  cout << premod % mod;
  
}

uint128_t bigPow(uint128_t base, int pow) {
  if (pow == 0) {
    return 1;
  }
  else if (pow == 1) {
    return base;
  }
  else if (pow == 2) {
    return base * base;
  }
  else {
    reutrn bigPow(base * base, pow - 1);
  }
}
