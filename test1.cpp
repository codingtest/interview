#include <stdio.h>

bool find(int* a, int length, int sum, int* num1, int* num2)
{
	if ( a == NULL || length == 0 || num1 == NULL || num2 == NULL )
		return false;
	int high = length - 1;
	int low = 0;
	while( low < high ) 
	{
		if ( a[high] + a[low] == sum )
		{
			*num1 = a[high];
			*num2 = a[low];
			return true;
		}
		if (a[high] + a[low] > sum )
		{
			high--;

		} else {
			low++;
		}
	}
	return false;
}


#define MAX_INT (1<<31 - 1)

bool atoi(char* str, int* result)
{
	if ( str == NULL )
		return false;
	//omit the space
	while(*str != '\0' )
	{
		if (*str == ' ')
			str++;
        else
            break;
	}

	bool neg = false;
	if ( *str == '-' )
	{
		neg = true;
		str++;
	}

	if ( *str == '+' )
	{
		str++;
	}
	if ( *str == '\0')
		return false;

	long long num = 0;
	//count it 
	while(*str != '\0' )
	{
		if ( *str < '0' || *str > '9' )
			return false;
		
		num = num*10 + ( *str - '0' ); 
		if ( num > MAX_INT)
			return false;
         str++;
	}
	if ( neg )
		*result = 0 - (int)num;
	else
		*result = (int)num;

	return true;

}

int MaxSum(int* a ,int N)
{
	int maxsum= 0;
	int sum = 0;
	for ( int i = 0 ;i < N ; i++ )
	{
		sum += a[i];
		if ( sum > maxsum )
			maxsum = sum;
		if ( sum < 0 )
			sum = 0;
	}
	return maxsum;
}

#include <vector>
#include <string>
using namespace std;

string add(string &str, int j,char ch)
{
    if ( j > 0 && ch == str[j - 1] )
        return "";
	string str1 = str.substr(0,j);
	string str2 = str.substr(j);
	return str1 + ch + str2;
}


vector<string> pStr(string &str)
{
	vector<string> temp;
     if ( str.length() == 0 )
            return vector<string>();
	if ( str.length() == 1 )
	{
		temp.push_back(str);
		return temp;
	}
	string new_str = str.substr(1);
	vector<string> result  = pStr(new_str);
	for ( int i = 0 ; i < result.size(); i++ )
	{
		for ( int j = 0; j < str.length(); j++)
		{
            string a = add(result[i],j,str[0]);
             if ( a != "")
			    temp.push_back(a);
		}
	}
	return temp;
}

void printStr(string str)
{
	if ( str.length() == 0 )
		return;
	vector<string> temp = pStr(str);
		
	for ( int i = 0 ;i < temp.size(); i++ )
	{
		printf("%s\n", temp[i].c_str());
	}



}


int change(int sum, int cc)
{
	if ( cc == 1 )
		return 1;
	if ( sum == 0 )
		return 1;
	int nc = 0;
	switch(cc)
	{
	case 25:
		nc = 10;
		break;
	case 10:
		nc = 5;
		break;
	case 5:
		nc = 1;
		break;
	default:
		break;
	}
	int result = 0;
	for ( int i = 0; sum - i*cc >= 0 ; i++ )
	{
		result += change(sum-i*cc,nc);
	}
	return result;
}

int makeChange(int sum)
{	
    if ( sum <= 0 )
            return 0;
	return change(sum, 25);
}
#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;
    
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        printf("%c ", x[i-1]);
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

//可重复组合问题是指，在计算（生成）组合时可以允许元素重复的一类组合问题。例如，对于有四个元素的集合{a, b, c, d}，
//其可重复组合C(4, 3）有20个：aaa, aab, aac, aad, abb, abc, abd, acc, acd, add, bbb, bbc, bbd, bcc, bcd, bdd, ccc, ccd, cdd, ddd。

void list(char* input, int num, char* str, int start, int n , int k)
{
	
	if ( k == 0 ){
		printf("%s\n", str);
        return;
    }
	for ( int i = 0 ; i < n; i++)
	{
		str[start] = input[num-n+i];
		list(input, num,str, start+1, n-i, k-1);
	}
	
	
}

//颠倒栈[数据结构]  
#include <stack>
void addtobottom(std::stack<int>& stack, int top)
{
	if( stack.size() == 0 )
		stack.push(top);

	else
	{
		int temp = stack.top();
		stack.pop();
		addtobottom(stack , top);
		stack.push(temp);
	}
}
void ReverseStack(std::stack<int>& stack)
{
	if (!stack.empty() )
	{
		int top = stack.top();
		stack.pop();
		ReverseStack(stack);
		addtobottom(stack,top);
	}
}


//f(513) = 5*f(99) + 100 + f(13)
//Write a method to count the number of 2s between 0 and n.
int count2sR(int n)
{
	if ( n == 0 ) return 0;

	int power = 1;
	while( 10* power < n ) power *=10;
	int first = n/power;
	int second = n%power;

	int nTwofirst = 0;
	if ( first > 2) nTwofirst = 1 * power;
	if ( first == 2) nTwofirst = second + 1;
	
	int nTwoOther = first * count2sR(n-1) + count2sR(second);
	return nTwofirst + nTwoOther;
}


//-八皇后问题[算法]  
bool valid(int* x, int n, int start)
{
	for ( int i =  0 ; i < start; i++ )
	{
		if ( x[i] == x[start] || abs(x[start] - x[i]) == abs(start - i) )
			return false;
	}
	return true;
}

void queen(int* index, int n , int start)
{
    if ( index == NULL || n == 0 )
		return ;

	if ( start == n )
	{
        //end
		for ( int i = 0 ; i < n ; i++ )
		{
			printf("%d", index[i]);
		}
		printf("\n");
	}

	for( int i  = 0; i < n;i++ )
	{
		
		index[start] = i;
		if ( valid(index, n , start) )
			queen(index, n, start+1);
	}
}

//Node* reverse(Node* node)
//{
//	if ( node == NULL )
//		return NULL;
//
//	Node* temp1 = node;
//	Node* temp2 = node->next;
//	node->next = NULL;
//	while( temp2 != NULL )
//	{
//		Node* temp3 = temp2->next;
//		temp2->next = temp1;
//		temp1 = temp2;
//		temp2 = temp3;
//	}
//	return temp1;
//}
//


void printcircle(int** numbers, int colums, int rows, int start)
{
	if ( numbers == NULL || colums == 0 || rows == 0 )
		return;

	for ( int i = start ; i < colums - start ; i++)
	{
		printf("%d", numbers[start][i]);
	}
    
	for ( int i = start + 1; i < rows-start; i++)
	{
		printf("%d", numbers[i][colums-start -1]);
	}

	for ( int i = colums-start-2; i >= 0; i--)
	{
		printf("%d", numbers[rows-start-1][i]);
	}

	for ( int i = rows-start-2; i >= 1; i--)
	{
		printf("%d", numbers[i][start]);
	}
}

void PrintMatrixClock(int** numbers, int colums, int rows)
{
	if ( numbers == NULL || colums == 0 || rows == 0 )
		return;
	
	int start = 0;
	while (colums > start * 2 && rows > start * 2)
	{
		printcircle(numbers, colums, rows, start);
		start++;
	}
}

#include <iostream>
using namespace std;
class A
{
private:
	int n1;
	int n2;
public:
	A(): n2(0), n1(n2+2)
	{
	}
	void Print()
	{
		cout <<n1<<" "<<n2<<endl;
	}
};


bool verifyBST(int* a, int length)
{
	if ( a == NULL || length <= 0 )
		return false;
	
	int root = a[length-1];
	
	int i;
	for ( i = 0; i < length; i++)
	{
		if ( a[i] >= root)
			break;
	}

	for(int j = i; j< length;j++)
	{
		if ( a[j] < root )
			return false;
	}
	bool left = true;
	if ( i >  0 )
		left = verifyBST(a, i);
	bool right = true;
	if ( i < length - 1)
		right = verifyBST(a + i, length - i - 1);

	return left && right;
	
}

//对称子字符串的最大长度[算法]   O(n2)
int MaxCircle(char* str)
{
	if ( str == NULL )
		return 0;
	
	int maxLength = 0;

	char* pchar = str + 1;
	while(*pchar != '\0')
	{
		if ( *(pchar + 1 ) != '\0' && *pchar == *(pchar + 1) )
		{
			char* pfirst = pchar - 1;
			char* plast = pchar + 2;
			while(pfirst >= pchar && *pfirst != '\0' && *pfirst == *plast)
			{
				pfirst--;
				plast++;
			}
            int length ;
            if ( *pfirst != *plast )
			    length = plast- pfirst - 1 ;
            else 
                length = plast - pfirst + 1;
			maxLength = length > maxLength ?length: maxLength;
		}
		else
		{
			char* pfirst = pchar - 1;
			char* plast = pchar + 1;
			while(pfirst >= pchar && *pfirst != '\0' && *pfirst == *plast)
			{
				pfirst--;
				plast++;
			}
			int length ;
            if ( *pfirst != *plast )
			    length = plast- pfirst - 1 ;
            else 
                length = plast - pfirst + 1;
			maxLength = length > maxLength ?length: maxLength;
		}
		pchar++;
	}
	return maxLength;
	
}
int main(int argc, char **argv)
{
    /*int numbers[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    A a;
    a.Print();*/

    int result = MaxCircle("");
    //int a[7] = {5,7,6,9,11,10,8};
    //int result = verifyBST(a, 7);

  //  PrintMatrixClock(numbers, 4,4);
////    int index[8];
////queen(index, 8, 0);
  /*  std::stack<int> temp;
      temp.push(5);
      temp.push(4);
      temp.push(3);
      temp.push(2);
      temp.push(1);

      ReverseStack(temp);*/
    /*char* str = new char(3+1);
if ( str == NULL)
	return 1 ;
memset(str, 0 ,3+1);
char input[4] = {'a', 'b', 'c','d'};
list(input,4, str,0,4, 3);*/

    /*char x[MAXLEN] = {"ABCBDAB"};
    char y[MAXLEN] = {"BDCABA"};
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int m, n;
    
    m = strlen(x);
    n = strlen(y);
    
    LCSLength(x, y, m, n, c, b);
    PrintLCS(b, x, m, n);*/
    
    return 0;
}