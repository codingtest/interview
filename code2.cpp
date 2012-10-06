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

//��һ��������ر����ֳ� N��M ��������С�飬ÿ����һƽ���ס���ЩС��ߵͲ�ƽ��
//ÿһС��ض����Լ��ĸ߶�H(i, j)�ס�ˮ����������һ���������Χ�ĸ�������Ŀ���У�
//������ֱ������Խ�������С���С�һ������������ݵط��������˲��ٽ�ˮ�����������ܻ�����������׵Ľ�ˮô?
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
