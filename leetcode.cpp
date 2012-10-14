#include<vector>
#include <list>
#include <map>
#include <set>
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
#include <stdio.h>

using namespace std;

bool jump(int A[], int n , int position)
{
	if ( position == n-1)
		return true;
	int maxJump = A[position];
	for ( int i = 1; i <= maxJump;i++)
	{
		if ( jump(A, n, position + i ) )
			return true;
	}
	return false;

}

bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
   	return jump(A, n, 0);
}



int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if ( A == NULL || n == 0 )
	return 0;
	int sum = 0;
	int max = -0x7FFFFFFF;
     for ( int i = 0 ;i < n;i++)   
	{
		sum += A[i];
		if ( max < sum ) max = sum;
		if ( sum < 0 ) sum = 0;
	}
	return max;
}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    if  ( A == NULL || n == 0 )
    {
            vector<int> result;
    	result.push_back(-1);
	    result.push_back(-1);
    }
    int start = -1;
	int end = -1;

    int i = 0;
	for ( ; i< n; i++)
	{
		if ( A[i] != target && start != -1 )
		{
			end = i - 1;
			break;
		}
		 if ( A[i] == target && start == -1 )
		{
			start = i;
		}	
	}        
	if ( i == n && start != -1 && end == -1 )
		end = n - 1;

	vector<int> result;
	result.push_back(start);
	result.push_back(end);
    return result;
}


bool inter(string s1, string s2, string s3)
{
	if ( s1.length() == 0 && s2.length() == 0 )
		return true;

	if ( s1.length() == 0 )
		return s3 == s2;
	
	if (s2.length() == 0 )
		return s1 == s3;

	bool ret = false;
	if ( s1[0] == s3[0] )
		ret = inter(s1.substr(1),s2, s3.substr(1));

	if ( ret == false && s2[0] == s3[0] )
		ret = inter(s1, s2.substr(1),s3.substr(1));

	return ret;
}


bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
	if ( s1.length() + s2.length() != s3.length() )
		return false;

	return inter(s1,s2,s3);  
        
}

class Solution {
public:
    void count(vector<int> &candidates, int target, int start, vector<int>& temp)
    {
            if ( target == 0 ){
                res.push_back(temp);
                return;
            }
                
            for (int i = start; i < candidates.size();i++ )
            {
                if ( target < candidates[i] )
                    continue ;
                temp.push_back(candidates[i]);
                count(candidates, target - candidates[i], i, temp);
                temp.pop_back();
            }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> temp;
        count(candidates, target, 0, temp);
        
        sort(temp.begin(), temp.end());
        return res;
    }
    private:
    vector<vector<int> > res;
};

vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> temp = numbers;
        sort(temp.begin(), temp.end());
        int start = 0;
        int end = numbers.size() - 1;
        int find = false;
        while ( start < end)
        {
            int  sum = temp[start] + temp[end];
            if ( sum == target )
            {
                int index1; 
                int index2;
                for ( int i = 0 ; i < temp.size(); i++ )
                {
                    if ( numbers[i] == temp[start] )
                    index1 = i;
                    else if ( numbers[i] == temp[end] )
                        index2 = i;
                }
                vector<int> res;
                if ( index1 < index2)
                {       
                    
                    res.push_back(index1);
                    res.push_back(index2);
                }
                else
                {
                    res.push_back(index2);
                    res.push_back(index1);
                }
                return res;
            }
            if ( sum < target )
            {
                start++;
            }
            else
            {
                end--;
            }
                
        }
        
        
        return vector<int>();
   }

int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 0 )
            return 1;
        if ( n == 1 )
            return 1;
        if ( n == 2 )
            return 2;
            
        int num = 0;
        for ( int i = 1 ; i <= n  ;i++ )
        {
            num += numTrees(i-1) * numTrees(n - i );
        }
        return num;
    }

int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int DP[101][101];
        memset(DP, 0, sizeof(DP));
        DP[0][0] = 1;
        for ( int i = 0; i < m ;i++)
        {
            for ( int j = 0; j < n ;j++)
            {
                if ( i == 0 && j == 0 )
                    DP[i][j] = 1;
                   
                else if ( i == 0 )
                    DP[i][j] = DP[i][j-1];
                else if ( j == 0 )
                    DP[i][j] = DP[i-1][j];
                else
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }
        return DP[m-1][n-1];
    }

vector<int> findString(vector<vector<int>> input, int n)
{
    map<float, vector<int> > temp;

    for  (int i  = 0; i < n;i++)
    {
        for ( int j= i+1; j < n; j++)
        {
                float deg = tanh(float(input[i][1] - input[j][1])/ float(input[i][0] - input[j][0] ));
                if ( int(deg) >= 180)
                    deg = deg - 180;
                map<float, vector<int>>::iterator iter = temp.find(deg);
                if (iter == temp.end())
                {
                    vector<int> l ;
                    l.push_back(i);
                    l.push_back(j);
                    temp.insert(pair<float, vector<int> >(deg, l));
                }
                else{
                    int find = false;
                    for( int i = 0 ; i < iter->second.size() ;i++ )
                    {
                        if ( j == iter->second[i] )
                        {
                            find = true;
                            break;
                        }
                    
                    }
                    if ( find == false )
                        iter->second.push_back(j);
                }
        }
    }

    int max = 0;
    vector<int>* res;
    for ( map<float, vector<int>>::iterator iter= temp.begin(); iter != temp.end();iter++)
    {
        int num = iter->second.size();
        if ( max < num )
        {
            max = num;
            res = &(iter->second);
        }
    }
    return (*res);
}


   int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if ( s.length() == 0 )
        return 0;
        
    int a[26] = {0};
	int count = 1;
    int max = 1;
    a[s[0] - 'a' ] = 1;
	for ( int i = 1 ;i < s.length(); i++ )
	{
		if ( a[s[i] - 'a'] == 0 )
		{
			a[s[i] - 'a' ] = 1;
			count++;
		}
		else
		{
            if ( max < count )
                        max = count;
			while( count > 0 )
			{
				if ( s[i-count] != s[i] )
				{
                   
					a[s[i-count] - 'a'] = 0;
                     count--;
				}
				else
					break;
			}
		}
		
	}
    if ( max < count )
                        max = count;
	return max;    
}

   int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = word1.length();
        int n = word2.length();
        int* v = new int[(m+1)*(n+1)];
        if ( v == NULL )
            return 0;
        memset(v, 0, (m+1)*(n+1));
        
        for ( int i = 0; i <= m ; i++ )
        {
            v[i*(n+1)] = i;
        }
        for ( int i = 0; i <= n ; i++ )
        {
            v[i] = i;
        }
        
        for ( int i = 1 ; i <= m;i++ )
        {
            for  ( int j = 1; j <= n; j++ )
            {
                if ( word1[i-1] == word2[j-1]) v[ i*(n + 1) + j - 1 ] = v[(i-1)*(n+1) + j-2];
                else
                    v[ i*(n+1) + j - 1] = 1 + min( min(v[(i-1)*(n+1)  + j - 1], v[i*(n+1)  + j-2]),v[(i-1)*(n+1)  + j-2]);
            }
        }
        int ret =  v[m*n -1];
        delete[] v;
        return ret;
    }

   string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a1;
        a1 = 1;
        int a[10] = {0};
        for (int i = 2 ; i < n ;i++)
        {
            memset(a, 0, 10);
            for ( int j = 0 ;j < a1.size();j++)
            {
                a[a1[j]]++;
            }
            a1.clear();
            for ( int j =0 ; j < 10; j++)
            {
                if ( a[j] != 0 )
                {
                    a1.push_back(a[j);
                    a1.push_back(j);
                }
            }
        }
        char* res = new char[a1.size() + 1];
        for ( int i = 0 ; i < a1.size() ;i++)
        {
            res[i] = a1.back() + '0';
            a1.pop_back();
        }
        return string(res);
    }

   //最长递增子序列
 int LIS(int d[], int n){
    int *B = new int[n];
    int left, right, mid, len = 1;
    B[0] = d[1]; //为了和上面的一致，我们从1开始计数吧:)
    for(int i = 2; i <= n; ++i){
        left = 0, right = len;
        while(left <= right){
            mid = (left + right) / 2;
            if(B[mid] < d[i]) left = mid + 1; //二分查找d[i]的插入位置
            else right = mid - 1;
        }
        B[left] = d[i]; //插入
        if(left > len) len++; //d[i]比现有的所有数字都大，所以left 才会大于 len。
    }
    delete[] B;
    return len;
}

 int main()
 {
     /* HMODULE m_ntdll = LoadLibrary(L"ntdll.dll");
    FPTR_ZwAllocateVirtualMemory m_ZwAllocateVirtualMemory = (FPTR_ZwAllocateVirtualMemory)GetProcAddress(m_ntdll,"ZwAllocateVirtualMemory");
    FreeLibrary(m_ntdll);
    void* address = (void*)0x100000;
    int size = 0x10;
   int ret  = m_ZwAllocateVirtualMemory(GetCurrentProcess(), &address, 0, (PULONG)&size,  MEM_COMMIT   , 1);
*/
     int* v = new int[2*3];
        if ( v == NULL )
            return 0;
        memset(v, 0,6);
        
    int (*t)[] = (int  (*)[])v;
    t[0][1] = 1;
     int res = lengthOfLongestSubstring("abcd");
    
     Solution s;
     vector<vector<int> > i;
     vector<int> a ;
     a.push_back(1);
     a.push_back(1);

      vector<int> b;
     b.push_back(2);
     b.push_back(2);
     vector<int> c;
     c.push_back(3);
     c.push_back(3);
i.push_back(a);
i.push_back(b);
i.push_back(c);

//     vector<int> res = findString(i, 3);
  //  bool ret = isInterleave("aacaac", "aacaaeaac", "aacaacaaeaacaac");
     //vector<vector<char>> matrix = ["00010111","01100101","10111101","00010000","00100010","11100111","10011001","01001100","10010000"];
     return 0;
 }