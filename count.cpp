#include <stdio.h>
#include <vector>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//一个整数数组，长度为n，将其分为m份，使各份的和相等，求m的最大值。
//比如{3，2，4，3，6} 可以分成{3，2，4，3，6} m=1；{3,6}{2,4,3} m=2；{3,3}{2,4}{6} m=3；
//所以m的最大值为3。这道题有些难，除了brute force的算法，你能想出比较优化的时间、空间复杂度的算法吗？

bool help2(int* a, int n, int s, int c, int* temp, int cur)
{
    int complete = true;
    for ( int i = 0 ; i < c; i++)
    {
        if ( temp[i] < s){
            complete = false;
            break;
        }
    }
    if ( complete == true)
        return true;

    for ( int i = 0 ; i < c; i++)
    {
        if ( a[cur] + temp[i] <= s)
        {
            temp[i] += a[cur];
            bool ret = help2(a, n ,s, c, temp, cur+1);
            if ( ret == true)
                return true;
            temp[i] -= a[cur];
        }
    }
    return false;
}
bool help(int* a, int n, int s, int c)
{
   int* temp = new int[c];
   if ( temp == NULL )
       return false;
   memset(temp, 0, c);

   help2(a, n, s, c, temp,0);
    return true;
}
int count(int* a, int n)
{
    if ( a == NULL || n == 0 )
        return 0;
    sort(a, a+n);
    int sum =0;
    for ( int i = 0 ; i < n ;i++)
    {
        sum += a[i];
    }
    int min = a[n-1];
    for ( int i = min; i< sum -1;i++)
    {
        if ( sum%i == 0)
          {
              if ( help(a, n,i,sum/i))
              {
                  return sum/i;
              }
        }
    }
    return 1;
}

int main()
{
    int input[10] = { 1,5,7,8,9,6,3,11,20,17};
    int re = count(input,10);

    return 0;
}