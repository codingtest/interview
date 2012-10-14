#include <stdio.h>
#include <vector>
using namespace std;


//题目：输入两个整数序列。其中一个序列表示栈的push顺序，判断另一个序列有没有可能是对应的pop顺序。
//为了简单起见，我们假设push序列的任意两个整数都是不相等的。
//http://blog.csdn.net/yysdsyl/article/details/1841968

bool valid(int* a, int* b, int N)
{
    if ( a == NULL || b == NULL )
        return false;

    vector<int> stack;
    int start = 0;
    int i = 0;
    int j = 0;
    while( j < N )
    {
        if ( stack.size() != 0 && stack.back() == b[j] )
        {
            stack.pop_back();
            j++;
            continue;
        }
        for ( i = 0;i < N;i++)
        {
            if( a[i] == b[j] )
                break;
        }
        if ( i == N )
            return false;
        for ( int k = start ; k < i;k++)
        {
            stack.push_back(a[k]);
        }
        j++;
        i++;
        start = i;
    }
    if ( i == N && j == N )
        return true;
    else
        return false;
}


//和为n连续正数序列
void findsequence(int n)
{
	if ( n < 3)
		return;
	int small = 1;
	int big = 2;
	int mid = (1+n)/2;
	int sum = small+big;

	while( small < mid && big < n )
	{
		if ( sum == n )
		{
			printf("answer: ");
			for( int i = small ; i<= big;i++)
				printf("%d\n",i);
			printf("\n");
			sum -= small;
			small++;
		}
		if ( sum > n){
			sum -= small;
			small++;
					
		}
		if ( sum < n){
			big++;
			sum += big;
		}
	}
}

//  调整数组顺序使奇数位于偶数前面
void change(int* a, int n)
{	
    if ( a == NULL || n < 2 )
        return;
	int start = 0;
	int end = n - 1;
	while ( start < end )
	{
		if ( a[start] % 2 == 1 ){
			start++;
            continue;
        }
		if( a[end] % 2 == 0 ) {
			end--;
            continue;
        }

      /*  if ( start >= end )
            break;*/
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
        start++;
        end--;
	}
}
#include <vector> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <queue> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <string> 
#include <cassert> 

using namespace std; 

//有两个长度均为n的整数数组A和B，现在要从这两个数组中各抽出s个数字，分别构成两个新的数组C和D，要求数组C和D的内积最大。
int findmax(int* a, int* b , int n, int total)
{
	if ( a == NULL || b == NULL || n < total )
		return 0;
	sort(a, a+n, less<int>());
	sort(b, b+n, less<int>());
	vector<int> c;
	vector<int> d;

	int start = 0;
	int end = n - 1;
	int need = 0;
	int sum = 0;
	while(start<end)
	{
		int val1 = a[start]* b[start];
		int val2 = a[end] * b[end];
		if ( val1 < 0 && val2 < 0 )
             break;
		if ( val1 >= val2 )
		{
			c.push_back(a[start]);
			d.push_back(b[start]);
			sum += val1;
            start++;
		}
		else
		{
			c.push_back(a[end]);
			d.push_back(b[end]);
			sum += val2;
            end--;
		}
		need++;
		if ( total == need )
			return sum;
	}
    int i = 0;
    while ( need < total )
    {
          c.push_back(a[start + i]);
          d.push_back(b[end - i]);
          sum += a[start + i] + b[end - i];
          i++;
          need++;
    }
    return sum;
}

//打印可能的出栈序列
void printstack(int* a,int n ,int cur, vector<int>& in , vector<int>& out)
{
	if( out.size() == n)
	{
		//end solution
		for ( int i = 0 ; i < n; i++)
		{
			printf("%d", out[i]);
		}
		printf("\n");
	}
	if ( cur < n  )
	{
		//in stack
		in.push_back(a[cur]);
		printstack(a, n, cur+1, in,out);
		in.pop_back();
	}
	if ( in.size() > 0 )
	{
		int temp = in.back();
		in.pop_back();
		out.push_back(temp);
		printstack(a, n, cur, in, out);
		out.pop_back();
		in.push_back(temp);
	}
}

int sumMax[10][10];
void presum(int (*p)[10],int n)
{
	for ( int i = 0; i< n ; i++ )
	{
		for ( int j = 0 ; j < n; j++)
		{
			if ( i == 0 && j == 0 )
				sumMax[i][j] = p[0][0];
			else if ( i == 0 )
			{
				sumMax[i][j] = sumMax[i][j-1] + p[i][j];
			}
			else if ( j == 0 )
			{
				sumMax[i][j] = sumMax[i-1][j] + p[i][j];
			}
			else 
			{
				sumMax[i][j] = sumMax[i-1][j] + sumMax[i][j-1] - sumMax[i-1][j-1] + p[i][j];
			}
		}
	}
}

int Max = 0;
void find(int (*p)[10],int n)
{
	presum(p, n);
	for ( int i = 0; i < n; i++)
		for (int j = 0 ; j < n;j++)
			for ( int k = 0 ; k < i; k++)
				for ( int q = 0 ; q < j ; q++)
				{
					int value = 0;
					if ( i == 0 && j == 0 )
						value = sumMax[i][j];
					else if ( i == 0 )
					{
						value = sumMax[i][j] + sumMax[i][q];
					}
					else if ( j == 0 )
					{
						value = sumMax[i][j] + sumMax[k][j];
					}else
					{
						value = sumMax[i][j] - sumMax[k][j] - sumMax[i][q] + sumMax[k][q];
					}
					Max = value > Max?value:Max;
				}
}

//迷宫最优解的宽度优先解法
typedef pair<int, int> Position;
 typedef unsigned char MoveType;
const MoveType UNVISITED = 'N';       // 未访问
const MoveType START = 'S';           // 起点
const MoveType UP = 'U';              // 向上
const MoveType RIGHT = 'R';           // 向右
const MoveType DOWN = 'D';            // 向下
const MoveType LEFT = 'L';            // 向左

int SearchMaze(int* A, int m , int n , vector<char>& path)
{
     
     Position start(0,0);
     Position end(m-1, n-1);
     //for make the level is all parsed
     Position tag(-1, -1);

     
     vector<MoveType> state(m * n, UNVISITED);

     queue<Position> que;
     que.push(start);
     que.push(tag);

     bool success = false;
     int level = 1;
     state[0] = START;

     while(!que.empty())
     {
         Position cur = que.front();
         que.pop();
          if( cur == end )
          {
                success = true;
                break;
          }

          if ( cur == tag )
          {
              if ( !que.empty() )
              {
                  level++;
                  que.push(tag);
                  continue;
              }
          }

          int i = cur.first;
          int j = cur.second;

          int index;

          //rigth
          index = i*n + j + 1;
          if (  j < n - 1 && A[index] == 0 && state[index] == UNVISITED )
          {
               que.push(make_pair(i, j+1));
               state[index] = RIGHT;
          }

          //left
          index = i*n + j - 1;
          if (  j > 0 && A[index] == 0 && state[index] == UNVISITED )
          {
               que.push(make_pair(i, j-1));
               state[index] = LEFT;
          }
          //down
          index = (i + 1)*n + j;
          if (  i < m - 1 && A[index] == 0 && state[index] == UNVISITED )
          {
               que.push(make_pair(i+1, j));
               state[index] = DOWN;
          }

          //up
          index = (i - 1)*n + j;
          if (  i > 0 && A[index] == 0 && state[index] == UNVISITED )
          {
               que.push(make_pair(i-1, j));
               state[index] = DOWN;
          }

     }

     if ( success )
     {
            int i = m-1;
            int j = n-1;
            int index = i*n + j;
            for ( ; state[index] != START; index = i*n + j)
            {
                    path.push_back(state[index]);
                    switch(state[index])
                    {
                    case RIGHT:
                        j--;
                        break;
                    case LEFT:
                        j++;
                        break;
                    case UP:
                        i++;
                        break;
                    case DOWN:
                        i--;
                        break;
                    }

            }
            path.reserve(path.size());
            return level;
     }
     return -1;
}

void DFS(int* a, int m , int n )
{

}

int main()
{
     const int m = 8;
    const int n = 8;
    int A[m * n] = {
        0, 0, 0, 0, 1, 0, 0, 0,
        1, 0, 1, 0, 0, 0, 1, 0,
        0, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 1, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 1, 1, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 1, 0, 1, 1,
        1, 0, 0, 0, 1, 0, 0, 0,
    };

    vector<char> path;

    int length = SearchMaze(A, 8, 8, path);

   /* vector<int> in, out;
    int a[5] = {1,2,3,4,5};
    printstack(a, 5, 0, in, out);*/

 /*   int A[10] = {2,4,12,-4,6,12,9,-1, -20, -10};  
    int B[10] = {2,3,7,9,-10,-12,-3, -9, -10, -100};  
    int n = 10, m = 1;  

   int result =  fndmax( A, B, n, 9);*/
     /*int b[18] = {4,3,5,1,2,34,21,543,7,2,23,5,1,2,6,4,3,2};
     change(b, 18);*/
    ///findsequence(15);
    /*int a[5] = {1,2,3,4,5};
    int b[5] = {4,3,5,1,2};
    bool result = valid(a,b,5);*/
       return 0;
}