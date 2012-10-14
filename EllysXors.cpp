
#include <stdio.h>

typedef long long ll;
 
ll cum_xor(ll n) {
  switch (n % 4) {
  case 0: return n;
  case 1: return 1;
  case 2: return n + 1;
  case 3: return 0;
  }
  return -1;
//  assert(false);
}

void  EllysXors(long long input1, long long  input2)
{
    long long  result  = input1;
   result =  cum_xor(input1 - 1) ^ cum_xor(input2);
    printf("result is %ld\n", result);
}

int main()
{
    EllysXors(1424242424,3666666666);
    return 0;
}