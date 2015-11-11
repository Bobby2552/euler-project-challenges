#include <iostream>
#include <math.h>

using namespace std;

long sum = 0;
long nums [32];

int main() {
  nums[0] = 1;
  nums[1] = 2;
  for (int i = 2; i < 32; i++) {
    nums[i] = nums[i - 1] + nums[i - 2];
    cout << nums[i] << ", ";
    if (nums[i] % 2 == 0) {
      sum += nums[i];
    }
  }
  sum += 2; //accounting for missed two in index 1.
  cout << sum;
}
