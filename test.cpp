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
tring multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }
string multiply(const string &a, const string &b)
{
        if ( a.length() == 0 || b.length() == 0) return "";

        int length1 = a.length();
        int length2 = b.length();
       // int length3 = length1 + length2;
        char* result = new char[length1+length2+1];
        if ( result == NULL )
            return "";
        memset(result, 0, length1+length2+1);

        for  ( int i = 0 ; i < length1; i++)
        {
            for ( int j = 0; j< length2;j++)
            {
                if（a[length1 - i - 1] > '9' ||a[length1 - i - 1] < '0' || b[length2 - j - 1] > '9' || a[ength2 - j - 1] < '0' )
                    return "";
                result[i+j] += (a[length1 - i - 1] - '0') * (  b[length2  - j - 1] - '0');
            }
        }

        for ( int i = 0 ; i < length1+length2;i++)
        {
            if ( result[i] > 9 )
            {
                result[i+1] += result[i]/ 10;
                result[i] = result[i] % 10;
            }
        }

        /*char* result2 = new char[length1+length2+1];
        if ( result2 == NULL )
            return "";
        memset(result2, 0, length1+length2+1);*/
        int i = length1 + length2;
        for (  ; i >= 0 ;i--)
        {
            if ( result[i] != 0 ){
                break;
            } 
        }

         for ( int j = 0 ; j <= i/2 ;j++)
        {
            char ch = result[j];
            result[j] = result[i- j] + '0';
            result[i-j] = ch + '0';
        }

     //   delete[] result;

        return string(result);
}

void reverse(char* input)
{
    int length = strlen(input) + 1;
    for  ( int i = 0 ; i < length/2 ; i++)
    {
        char ch = input[i];
        input[i]= input[length - i - 1];
        input[length - i  - 1] = ch;
    }
}

//void remove(char* input)
//{
//    n
//}


// 已知n个元素，如何不用除法计算任意n-1个元素元素的乘积？
int count(int* array, int num, int target)
{
	if ( array == NULL || num == 0 )
		return 0;
	int* a = new int[num];
	if ( a == NULL )
		return 0;
	int* b = new int[num];
	if ( b == NULL )
		return 0;

	a[0] = array[0];
	b[0] = array[num - 1];

	for ( int i = 1; i <= num ; i++ )
	{
		a[i] = a[i-1]*array[i];
	}

	for ( int i = num - 2; i >= 0; i-- )
	{
		b[num - i - 1] = b[num - i - 2]*array[i];
	}

	return a[target-2]*b[num-target-1];
}


//实现一个可以O(1)获取最小元素的Stack
//
//typedef struct _node
//    {
//        int value;
//        struct _node* next;
//    }Node;
//
//class myStack
//{
//public:
//    myStack():size(0), minStack(NULL){};
//    bool push(int);
//    bool pop(int*);
//    bool min(int *);
//private:
//    int size;
//    
//    Node* minStack;
//    vector<int> _stack;
//};
//
//bool myStack::push(int value)
//{
//    _stack.push_back(value);
//    size++;
//
//    Node*  node = new Node();
//    if ( node == NULL )
//        return false;
//    memset(node, 0, sizeof(Node));
//    node->value = value;
//
//    if ( minStack == NULL ) {
//        minStack = node;
//        return true;
//    }
//    if ( minStack->value >= value )
//    {
//        node->next = minStack;
//        minStack = node;
//        return true;
//    }
//    Node* previous = minStack;
//    Node* temp = previous->next;
//    while( temp )
//    {
//        if ( temp->value < value )
//        {
//            previous = temp;
//            temp = temp->next;
//        }
//        else 
//        {
//            break;
//        }
//    }
//        previous->next = node;
//        node->next = temp;
//
//    return true;
//}
//
//bool myStack::pop(int* value)
//{
//    if ( value == NULL || size == 0 )
//        return false;
//
//    *value = _stack.back();
//    _stack.pop_back();
//    size--;
//
//     if ( minStack == NULL ) {
//        return false;
//    }
//
//    if ( minStack->value ==  *value )
//    {
//        Node* temp = minStack;
//        minStack = minStack->next;
//        delete temp;
//        return true;
//    }
//
//    Node* previous = minStack;
//    Node* temp = previous->next;
//    while( temp )
//    {
//        if ( temp->value != *value )
//        {
//            previous = temp;
//            temp = temp->next;
//        }
//        else 
//        {
//            break;
//        }
//    }
//    if ( temp != NULL ) 
//    {
//        previous->next = temp->next;
//        delete temp;
//    }
//    else
//    {
//        return false;
//    }
//    return true;
//}
//
//bool myStack::min(int* value)
//{
//    if ( value == NULL )
//        return false;
//
//    if ( minStack ) {
//        *value = minStack->value;
//        return true;
//    }
//    return false;
//}
//
//
//一个以Node节点表示的完全二叉树，如何计算它的最下面一层的叶子节点个数？要求复杂度低于O(N)
namespace test1
{
    typedef struct node {

  struct node * left;

  struct node * right;

}Node;

    int count2(Node* node, int max )
    {
        int tc;
        if  ( node == NULL )
            return 0;
        if ( max == 1 )
            return max;
        int temp = count2(node->right, max/2);
        if ( temp != 0 )
        {
            tc = max/2 + temp;
        }
        else 
        {
            tc = count2(node->left , max/2);
        }
        return tc;
    }

    int count(Node* node)
    {
        //find the deep;
        if (node == NULL )
            return 0;
        Node* temp = node;
        int depth = 0;
        while(temp)
        {
            depth++;
            temp = temp->left;
        }

        int max = 1 << (depth- 1);
        count2(node, max);
    }   
};




int count(int k)
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	a.push_back(2);
	b.push_back(3);
	c.push_back(5);
	int select;
	for( int i = 0 ; i < k; i++ )
	{
		int list;
		if ( a.front() < b.front() )
		{
			select = a.front();
			list = 1;
		}
		else
		{
			select = b.front();
			list = 2;
		}

		if ( select > c.front() )
		{
			select = c.front();
			list = 3;
		}
		switch(list)
		{
		case 1:
			a.erase(a.begin());
			a.push_back(select*2);
			b.push_back(select*3);
			c.push_back(select*5);
			break;
		case 2:
			b.erase(b.begin());
			b.push_back(select*3);
			c.push_back(select*5);
			break;
		case 3:
			c.erase(c.begin());
			c.push_back(select*5);
			break;
		default:
			break;
		}
		
	}
	return select;
}
	
typedef struct _node
{
	struct _node* next;
	struct _node* some;
}Node;

//已知一链表，每个节点除了有一个指向下一节点的指针外，还有一随机指针指向链表中的任意节点（可能为空，也有可能为自身），请复制一个链表，
//要求节点的顺序以及节点上的随机指针指向的节点位置和原链表一致（要求O(N)时间复杂度，O(1)空间复杂度）。
Node* build(Node* node)
{
	Node* temp = node;
	while ( temp )
	{
		Node* new_node = new Node();
		if ( new_node == NULL )
			return NULL;
		new_node->next = temp->next;
		temp->next = new_node;
		temp = new_node->next;
	}
	temp = node;
	while( temp )
	{
        if ( temp->some == NULL )
                temp->next->some = NULL;
        else if ( temp->some == temp)
                temp->next->some = temp->next;
		else
            temp->next->some = temp->some->next;
	}
	Node* result = node->next;
	temp = result;
	while( temp->next )
	{
		temp->next = temp->next->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return result;
}


//void mulitpul(int[][] a, int[][] b, int[][] c, int N)
//{
//	if ( a == NULL || b == NULL || c == NULL )
//		return;
//	for ( int i = 0 ; i < N ; i++ )
//	{
//		for (int j = 0; j < N ;j++)
//		{
//			for ( int k = 0; k < N; k++ )
//				c[i][j] += a[i][k] * b[K][j]; 
//		}
//	}
//}
//
//void maxfff()
//{
//    int a[10][10];
//    int b[10][10];
//    int c[10][10];
//    memset(c, 0, sizeof(c));
//     mulitpul(a, b, c, 10);
//}

//计算数组中逆序对的个数（a[1..n], i<j, if(a[i]>a[j]),then (i,j)为一个逆序对），要求复杂度低于O(n^2)
int merge(int* a, int start1, int end1, int start2, int end2)
{
	int* temp = new int[end2 - start1 + 1];
	if ( temp == NULL )
		return 0;
	int result = 0;
	int count1 = start1;
	int count2 = start2;
	int count3 = 0;
	while( count1 <= end1 && count2 <= end2)
	{
		if ( a[count1] <= a[count2] )
		{
			temp[count3] = a[count1];
			count1++;
			count3++;
		}
		else
		{
			temp[count3] = a[count2];
			count2++;
			count3++;
			result += end1 - count1 + 1;
		}
	}
    while( count2 <= end2 )
    {
          temp[count3] = a[count2];
			count2++;
			count3++;
    }
    while( count1 <= end1 )
    {
          temp[count3] = a[count1];
			count1++;
			count3++;
    }
	for ( int i = 0 ; i < count3;i++)
	{
		a[start1 + i] = temp[i];
	}
	return result;

}

int count1(int* a, int  start, int end)
{
	if ( start == end )
		return 0;
	if ( end - start == 1 )
	{
		if ( a[start] > a[end] )
		{
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			return 1;
		}
		else 
			return 0;
	}	
	int mid = (end - start ) / 2 + start;
	return count1(a, start, mid) + count1(a, mid+1, end)
		+ merge(a, start, mid , mid+1, end);
}

int atoi(const char* a)
{
}

int main()
{
    int input[10] = {3,2,1,5,3,2,6,4,2,6};
    int result = count1(input,0,9);
 //   //int input[5] = {1,2,3,4,5};
 //   //int result = count(input, 5, 2);
 //   //printf("result is %d\n", result);
 //   //string result = count(string("2341235"), string("231234"));
 ///*   char input[10] = "testtestt";
 //   reverse(input);
 //   printf("result is %s\n", input);*/


 //   myStack ms;
 //   
 //   ms.push(32);
 //   ms.push(64);
 //   ms.push(23);
 //   ms.push(12);
 //   ms.push(1);

 //   int value1 = 0;
 //   ms.min(&value1);
 //   
 //   int value3 = 0;
 //   ms.pop(&value3);

 //   int value2 = 0;
 //   ms.min(&value2);


    return 0;
}