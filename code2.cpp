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

//有一块矩形土地被划分成 N×M 个正方形小块，每块是一平方米。这些小块高低不平，
//每一小块地都有自己的高度H(i, j)米。水可以由任意一块地流向周围四个方向的四块地中，
//但不能直接流入对角相连的小块中。一场大雨后，许多低洼地方都积存了不少降水，求出它最多能积存多少立方米的降水么?
int trap(int* a, int n)
{
    if ( a == NULL || n == 0 )
        return 0;
    int* left = new int[n];
    if ( left == NULL )
           return 0;
     int* right = new int[n];
    if ( right == NULL )
           return 0;

    int maxL = 0;
    for ( int i = 0 ; i < n-1; i++ )
    {
        left[i] = maxL;
        maxL = max(maxL, a[i]);
    }

    int maxR = 0;
    for ( int i = n-1; i >= 0; i-- )
    {
        right[i] = maxR;
        maxR = max(maxR, a[i]);
    }

    int res = 0;
    for ( int i = 0 ; i < n-1 ;i++)
    {
        int v = min(left[i], right[i]) - a[i];
        if ( v > 0 )
            res += v;
    }
    delete[] left;
    delete[] right;
    return res;
}
