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

int largestRectangleArea(vector<int> &height) 
{
    if ( height.size() == 0 )
        return 0;

    vector<vector<int> > s;
    vector<int> t;
    t.push_back(height[0]);
    t.push_back(0);
    s.push_back(t);
    int max = 0;

    for ( int i = 1; i < height.size() ;i++)
    {
        int save = i;
        while ( !s.empty() )
        {
            vector<int> temp = s.back();
            if ( temp[0] > height[i] )
            {
                s.pop_back();
                int value = ( i - temp[1]) * temp[0];
                max = max < value? value: max;
                save = temp[1];
            }
            else
            {
                break;
            }
        }
        vector<int> t;
        t.push_back(height[i]);
        
        t.push_back(save);
        s.push_back(t);

    }
    
     while ( !s.empty() )
        {

            vector<int>  temp = s.back();
           
                s.pop_back();
                int value = ( height.size() - temp[1]) * temp[0];
                max = max < value? value: max;
           
        }
     return max;
}

int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     int max = 0;
     vector<vector<int> > temp;
     for ( int i = 0 ; i < matrix.size(); i++ )
     {
         vector<int> t;

         for ( int j = 0 ; j < matrix[0].size();j++)
         {
             if ( matrix[i][j] == '0' )
                 t.push_back(0);
             else if ( i == 0 )
             {
                t.push_back(1);
             }else 
             {
                 t.push_back(temp[i-1][j] + 1);
             }
         }
         temp.push_back(t);
         int value = largestRectangleArea(t);
         if (max < value )
             max = value;
     }
     return max;
}


//check it
class Solution {
    //http://slientcode.blogspot.com/2012/04/find-missing-smallest-positive-integer.html
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;i++){
            while(A[i]!=i+1){
                if(A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]) 
                    break;
                int temp = A[i];
                A[i] = A[temp-1];
                A[temp-1] = temp;
            }
        }
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)   return i+1;
        }
        return n+1;
    }
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if ( s1.length() + s2.length() != s3.length() )
            return false;

        int j = 0;
        for ( int i = 0 ; i < s1.length(); i++)
        {
            int find = false;
            for ( ;j < s3.length(); j++ )
            {
                if ( s1[i] == s3[j] )
                {
                    find = true;
                    break;
                }
            }
            if ( find )
            {
                s3[j] = '\0';
                j++;
            }
            else
            {
                return false;
            }
        }

        j = 0;
        for ( int i = 0; i < s2.length();i++ )
        {
            while( s3[j] == '\0' )
            {
                j++;
            }
            
            if ( j < s3.length() && s2[i] == s3[j] )
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};

class Solution3 {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( s == NULL )
            return 0;
        
        int length = strlen(s);
        int j = length - 1;
        while( j >= 0 )
        {
            if ( s[j] != ' ' )
            {
                break;
            }
            j--;
        }
        if ( j == -1 )
            return 0;
        int length2 = j + 1;
        while( j >= 0 )
        {
            if ( s[j] == ' ' )
            {
                break;
            }
            j--;
        }
        if ( j == -1 )
            return length2;
        else
            return (length2 - 1 - j);
    }
};


bool valid(int* x, int n, int start)
{
	for ( int i =  0 ; i < start; i++ )
	{
		if ( x[i] == x[start] || abs(x[start] - x[i]) == abs(start - i) )
			return false;
	}
	return true;
}

void queen(int* index, int n , int start, int* res)
{
    if ( index == NULL || n == 0 )
		return ;

	if ( start == n )
	{
        (*res)++;
	}

	for( int i  = 0; i < n;i++ )
	{
		
		index[start] = i;
		if ( valid(index, n , start) )
			queen(index, n, start+1,res);
	}
}

  int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* index = new int[n+1];
        if (index == NULL )
            return 0;
        memset(index, 0, n);
        int res = 0;
        queen(index, n, 0,&res);
        delete[] index;
        return res;
    }


string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if ( strs.size() == 0 )
        return "";

    if ( strs.size() == 1)
        return strs[0];

    int i = 0;
    while(1)
    {
        int cur = '\0';
        for (int j =0 ; j < strs.size(); j++)
        {
            if ( i >= strs[j].length() )
                goto out;
            if ( strs[j][i] == '\0')
                goto out;
            if ( cur == '\0' )
                cur = strs[j][i];
            else if ( strs[j][i] != cur )
                goto out;
        }
        i++;
    }
 out:
    return strs[0].substr(0,i);
        
}

bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    vector<char> temp;
    for ( int i  = 0 ; i < s.length(); i++)
    {
        switch(s[i])
        {
        case '(':
            temp.push_back('(');
            count1++;
            break;
        case ')':
            count1--;
            if ( temp.empty() || temp.back() != '(' )
                return false;
            temp.pop_back();
            break;
        case '[':
            temp.push_back('[');
            count2++;
            break;
        case ']':
            if ( temp.empty() || temp.back() != '[' )
                return false;
            temp.pop_back();
            count2--;
            break;
        case '{':
            temp.push_back('{');
            count3++;
            break;
        case '}':
            if ( temp.empty() || temp.back() != '{' )
                return false;
            temp.pop_back();
            count3--;
            break;
        }
    }
     if ( count1 == 0 && count2 == 0 && count3 == 0 )
         return true;
     else
         return false;
}

struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( head == NULL  )
            return NULL;
        if ( m >= n )
            return head;

        ListNode* pre = head;
        ListNode* cur = NULL;
        if ( m > 1)
        {
            for ( int i = 0 ; i < m - 2; i++)
            {
                if ( pre == NULL )
                    return head;
                pre = pre->next;
            }
            cur = pre->next;
        }
        else
        {
            pre = NULL;
            cur = head;
        }

        
        //cur->next = NULL;
        ListNode* start = cur;
        ListNode* save = pre;
        cur = cur->next;
        pre = pre->next;
        ListNode* temp;
        for ( int i = m -1; i < n-2;i++)
        {
            temp = cur->next;
            //pre->next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        if ( save )
            save->next = pre;
       
        start->next = temp;

        return head;
 }

//Swap Nodes in Pairs
ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if ( head == NULL || head->next == NULL )
          return head;

      ListNode* cur = head;
      ListNode* newhead = head->next;
      ListNode* next = head->next;
      ListNode* pre = NULL;
      while( cur && next )
      {
          cur->next = next->next;
          next->next = cur;
          if ( pre )
              pre->next = next;
          pre = cur;
          if ( cur->next == NULL )
              break;
          cur = cur->next;
          next = cur->next;
      }
      return newhead;
}

int bestbuy1(int* A, int n)
{
    if ( A == NULL || n == 0)
        return 0;
    vector<int> s;
    s.push_back(A[0]);
    int max = 0;
    for  ( int i =1; i < n ; i++)
    {
        if ( s.empty() )
        {
            s.push_back(A[i] );
            continue;
        }
        int t = s.back();
        if ( t <= A[i] )
        {
            s.push_back(A[i]);
        }
        else 
        {
            if ( s.size() >= 2 )
            {
                int value = s.back() - s.front();
                if( max < value )
                    max = value;
            }
            s.pop_back();
        }
    }
    if ( s.size() >= 2 )
            {
                int value = s.back() - s.front();
                if( max < value )
                    max = value;
            }
    return max;
}

int bestbuy2(int* A, int n)
{
    if ( A == NULL || n == 0)
        return 0;

    int buy =-1;
    int max = 0;
    for ( int i = 0; i< n ;i++)
    {
        if ( buy == -1 && A[i] > A[i+1] )
            continue;
        if ( buy == -1 && A[i] < A[i+1] )
        { 
            //buy
            buy = A[i];
        }

        if ( buy != -1 && A[i] > A[i+1] )
        {
            //selled
            int value = A[i] - buy;

            max += value;
            buy = -1;
        }
    }
    return max;
}

int maxValue = 0;
#include <list>
void best(int* A, int n ,int day, int count, list<int> &temp)
{
    if ( day == n )
    {
        //end
        if ( maxValue < count )
            maxValue = count;
        return;
    }

    //buy
    temp.push_back(A[day]);
    best(A, n , day+1, count, temp);
    temp.pop_back();

    //nothing
    best(A, n, day+1, count, temp);

    //sell
    if ( temp.size() != 0 )
    {
        int t = temp.front();
        temp.pop_front();
        best(A, n, day+1, count+A[day] - t , temp);
        temp.push_front(t);
    }
}

int bestbuy3(int* A, int n)
{
    if ( A == NULL || n == 0)
        return 0;
    list<int> temp;
    best(A, n, 0,0, temp);
    return maxValue;
}

void letter(string digits, int i, vector<string>& A, vector<string> & res, char* t)
{
    if ( i == digits.length() )
    {
        t[i] = '\0';
        res.push_back(string(t));
        return;
    }

    //if ( digits[i] > '9' || digits[i] < '2' )
    //    return ;
    for ( int j = 0 ; j < A[digits[i] - '0' - 1].length(); j++)
    {
        t[i] = A[digits[i] - '0' - 1][j];
        letter(digits, i+1, A, res, t);
    }

}

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> A; 

        A.push_back(string(""));
        A.push_back(string("abc"));
        A.push_back(string("def"));
        A.push_back(string("ghi"));
        A.push_back(string("jkl"));
        A.push_back(string("mno"));
        A.push_back(string("pqrs"));
        A.push_back(string("tuv"));
        A.push_back(string("wxyz"));
       vector<string> res;
       if ( digits.length() == 0  )
             {
                    res.push_back("");
                    return res;
                }
        char* t = new char[digits.length()+1];
        if( t == NULL )
            return res;
      letter(digits, 0, A, res, t);
      delete[] t;
        return res;
    }

string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if ( s.size() == 0 && s.size() == 1 )
        return s;

    int start = 0;
    int length = 1;
    for( int i = 1; i < s.length();i++ )
    {
        int count, low, high;
        
       
            count = 1;
             low = i-1;
             high = i+1;
       
        while(low >= 0 && high <= s.length() -1 )
        {
            if ( s[low] == s[high])
            {
                low--;
                high++;
                count += 2;
            }
            else
            {
                break;
                
            }
        }
        if ( length < count )
        {
            length = count;
            start = low + 1;
        }
        if ( s[i] == s[i-1] )
        {
             count = 2;
             low  = i-2;
             high = i+1;
             while(low >= 0 && high <= s.length() -1 )
            {
                if ( s[low] == s[high])
                {
                    low--;
                    high++;
                    count += 2;
                }
                else
                {
                    break;
                    
                }
            }
            if ( length < count )
            {
                length = count;
                start = low + 1;
            }
        }
    }
    return s.substr(start, length);
 }
//int main()
//{
//    vector<string> res = letterCombinations("22");
//    //vector<string> input;
//    //input.push_back("");
//    //input.push_back("");
//    //string ret = longestCommonPrefix(input);
//    //int res = totalNQueens(4);
//    //int A[7] = {25,23,21,26,27,25,30};
//    //int res = bestbuy3(A, 7);
//   /* vector<int> input;
//    input.push_back(2);
//    input.push_back(1);
//    input.push_back(2);
//
//    int result = largestRectangleArea(input);*/
//
//   /* Solution2 s;
//    bool result = s.isInterleave("aabcc","dbbca", "aadbbcbcac");*/
//    //Solution3 s;
//   // int result = s.lengthOfLastWord("a ");
//
//    //findMax(input, 7);
//    return 0;
//}