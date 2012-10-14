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

//����n���������в��ظ��� BSTs������ڵ���������ֵ�������Ϊ 1 �� n��������n�������list of <Node *>��

int count(int n )
{
    if ( n <= 0 )
        return 0;
    if ( n == 1 )
        return 1;
    if ( n == 2 ) 
        return 2;

	int* temp = new int[n];
	if ( temp == NULL )
		return 0;
	
	temp[0] = 1;
	temp[1] = 2;
	for ( int i = 2; i < n ; i++)
	{
		temp[i] = 0;
		for ( int j = 0; j <= i; j++)
		{
			if ( j == 0 || j == i)
				temp[i] += temp[i-1];
			else
				temp[i] += temp[j-1] * temp[i-j - 1];
		}
	}


	int res = temp[n-1];
	delete[] temp;
	return res;
}