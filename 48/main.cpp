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
  uint128_t modulos [bin.length()];
  if (b >= 1) modulos[0] = (uint128_t)bigPow(a, 1) % mod;
  if (b >= 2) modulos[1] = (uint128_t)bigPow(a, 2) % mod; 
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
    modulos[i] = bigPow(modulos[i - 1], 2) % mod;
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
  uint128_t ret;
  if (pow == 0) return 1;
  if (pow == 1) ret = base;
  for (int i = 2; i <= pow; i++) {
    ret *= base;
  }
  return ret;
}
