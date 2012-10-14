#include <stdio.h>
#include <string>

using namespace std;

class LargestSubsequence
{
public:
    string getLargest(string s);
};

//using dynamic programing
string LargestSubsequence::getLargest(string s)
{
    if ( s.length() == 0 ) return s;

    int p = 0;
    for ( int i  = 1; i < s.length(); i++ )
    {
        if ( s[i] > s[p] )
            p = i;
    }
    return s[p] + getLargest(s.substr(p + 1,s.size() - p ));
}

//div two level one
class TwiceString
{
public:
    string getShortest(string s);
};

string TwiceString::getShortest(string s)
{
    int length = s.length();
    int i;
    for ( i = length - 2 ; i >= 0; i-- ){
        if ( s.substr(0, i + 1 ) == s.substr(length - i - 1, i + 2 ) )
            break;
    }
    return s + s.substr(i + 1, length - i + 2);
}

//div two level three
//tips: each coins has the same probality
class CoinReversing
{
public:
    double expectedHeads(int N, int* a, int num);
};  

double CoinReversing::expectedHeads(int N, int* a, int num)
{
    //for every coins the probality is the samme
    double q = 1.0; //always on the top
    for ( int i = 0 ; i < num; i++ ){
        double p = (double)a[i] / (double)N;
        //if do not choose this coins, the probality of is heads is 1-q, so is q * ( 1-p)
        //if choose the coins, will change the result, so is p * ( 1 - q)
        q = p * ( 1 - q ) + q * ( 1 - p);
    }
    return q * N;

}

//div one level two
class ConvexSequence
{
public:
    long long getMinimum(int* a, int num);
};

//bool possible(int* a , int num, int p)
//{
//    for ( int i = p; i < num; i++ ){
//        if ( 2* a[i - 1] > a[i - 2] + a[i] )
//            return false;
//    }
//    return true;
//}
//
//long ConvexSequence::getMinimum(int* a, int num)
//{
//    for ( int i = 1; i < num ; i++ )
//    {
//        int lo = 0;
//        int hi = a[i] + 1;
//        if ( i > 2){
//            lo = max(2*a[i-1] + a[i-2], 0);
//        }
//        while( lo + 1 < hi ){
//            
//        }
//    }
//}

long long  ConvexSequence::getMinimum(int* a, int num)
{
    bool changed = false;
    long long res = 0;
    do {
        changed = false;
        for ( int i = 1; i < num - 1 ;i++ )
        {
            int top = ( a[i-1] + a[i+1] ) / 2;
            if ( a[i] > top ) {
                res += a[i] - top;
                a[i] = top;
                changed = true;
            }
        }
    }while(changed);
    return res;
}

//SRM 517 div one , level two

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

const int md = (int)(1e9+7);

class AdjacentSwaps {
public:
  int theCount(int* p, int n) ;
};

int result[55][55];
int d[55][55];
int AdjacentSwaps::theCount(int* p, int n) 
{
    int b[55], c[55];
    memset(d, 0, sizeof(d));
    for ( int i = 0 ; i <= 50;i++) 
        d[i][0] = 1;
    for ( int i = 1; i <= 50;i++)
        for ( int j= 1; j <=i;j++)
            d[i][j] = (d[i-1][j] + d[i-1][j-1])%md;
    for ( int i = n -1 ; i>=0;i--)
    {
        for ( int j = i; j < n;j++)
        {
            if ( i == j ) {
                result[i][j] = 1;
            } else {
                result[i][j] = 0;
                //copy the expect result 
                for ( int k = i; k <= j;k++)
                    b[k] = p[k];
                sort(b+i,b+j+1);

                for ( int k = i; k < j;k++ )
                {
                    for ( int q= 0;q<n;q++) c[q] = 0;
                    for (int q=i;q<k;q++) c[b[q]] = 1;
                     c[b[k+1]] = 1;
                     bool ok = true;
                     for(int q = i; q<=k;q++){
                         if ( !c[p[q]]) {
                             ok = false;
                             break;
                         }
                     }
                     if ( ok ){
                         long long ft = (long long)result[i][k]*result[k+1][j] % md;
                            ft = (long long)ft*d[j-i-1][k-i] % md;
                            result[i][j] = (result[i][j]+ft) % md;
                     }
                }

            }
        }
    }


    return result[0][n-1];
}

// double c[50][1000000];
// int b[51][51];
//
//class EllysRivers
//{
//public:
//    double getMin(int length, int walk, double* width,int num1, double* speed, int num2);
//};
//
//double EllysRivers::getMin(int length, int walk, double* width,int num1, double* speed, int num2)
//{
//    //double c[][];
//    memset(c, 0 , sizeof(c));
//    memset(b, 0 , sizeof(b));
//
//    for ( int j = 0 ;  j <= length ; j++ )
//    {
//        double temp2 = (length - j ) * (length - j) + width[num1 - 1]* width[num1 - 1];
//        double temp =  sqrt ( temp2 ) / speed[num1 - 1];
//        c[num1][j] =temp;
//    }
//
//    for ( int i = num1 - 1 ; i > 0; i-- ){
//        for ( int j = 0 ;  j <= length ; j++){
//            for ( int k = j ; k <= length; k++ ){
//                double temp = sqrt ( (k - j ) * (k - j) + width[i - 1]* width[i - 1] ) / speed[i - 1] + c[i+1][k];
//                if ( c[i][j] == 0 || temp < c[i][j] ) {
//                    c[i][j] = temp;
//                    b[i][j] = k - j;
//                }
//            }
//        }
//    }
//
//    return c[1][0];
//
//}


//example in test book
int c[1000][1000];
int b[1000][1000];

string PrintLCS(string s1, string s2, int i , int j)
{
    if ( i == 0 || j == 0 ) 
        return "";

    if ( b[i][j] == 2 )
        return PrintLCS(s1, s2, i-1, j-1) + s1[i];
    if ( b[i][j] == 1 )
        return PrintLCS(s1, s2, i - 1, j);
    if ( b[i][j] == 0)
        return PrintLCS(s1,s2, i, j - 1);
}

//do not use b[i][j]
//
//string PrintLCS(string s1, string s2, int i , int j)
//{
//     if ( i == 0 || j == 0 ) 
//        return "";
//     if (c[i-1][j-1] == c[i][j] -1 )
//         return PrintLCS(s1, s2, i-1, j-1) + s1[i];
//     if (c[i-1][j] == c[i][j]  )
//         return PrintLCS(s1, s2, i - 1, j);
//     if (c[i][j-1] == c[i][j]  )
//         return PrintLCS(s1,s2, i, j - 1);
//}

string LCS(string s1, string s2)
{
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));

    for( int i = 1 ; i < s1.length() ;i++ ){
        for ( int j = 1 ; j < s2.length() ; j++){
            if ( s1[i] == s2[j] ){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 2;
            }else if ( c[i - 1][j] >= c[i][j - 1] ){
                c[i][j] = c[i-1][j];
                b[i][j]= 1;
            } else{
                c[i][j] = c[i][j-1];
                b[i][j]= 0;
            }
        }
    }
    
    return PrintLCS(s1, s2,s1.length(), s2.length());
}


#include<stdio.h>
int c[10][100];/*对应每种情况的最大价值*/
int b[10][100];

//int PRINT(int n, int m)
//{
//    if ( b[n][m] == 1 )
//        return PRINT(n-1, m-w[n]) + n;
//}
int knapsack(int m,int n)
{
 int i,j,w[10],p[10];
 for(i=1;i<n+1;i++)
        scanf("\n%d,%d",&w[i],&p[i]);
int x[10];
 memset(c, 0,sizeof(c));
 for(i=1;i<n+1;i++)
      for(j=1;j<m+1;j++)
      {
            if(w[i]<=j) /*如果当前物品的容量小于背包容量*/
             {
                      if(p[i]+c[i-1][j-w[i]]>c[i-1][j]){
                            c[i][j]=p[i]+c[i-1][j-w[i]];
                            x[i]=1;
                      }
                       else {
                            c[i][j]=c[i-1][j];
                            x[i]=0;
                       }
               }
              else{
                  c[i][j]=c[i-1][j];
                  x[i] = 0;
              }
       }

      for(i=0;i<n;i++)
         printf("%d ",x[i]);

     // PRINT(n, m);
 return(c[n][m]);
                     
}

int main()
{
    //double width[4] = {100, 200, 300, 400};
    //double speed[4] = {11, 12, 13, 14};
    ///*double width[1] = {911};
    //double speed[1] = {207};*/

    //EllysRivers er;
    //double result = er.getMin(1337,2 , width, 4, speed, 4);
    //printf("result is %ld\n", result);

    string result = LCS("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA","GTCGTTCGGAATGCCGTTGCTCTGTAAA");
    printf("result is %s\n", result.c_str());


    //AdjacentSwaps as;
    //int input[3] = 	{1, 2, 0};
    //long long result = as.theCount(input, 3);
    //printf("result is %ld\n",result);


    /*LargestSubsequence ls;
    string result = ls.getLargest("dcbae");*/
    /*TwiceString ts;
    string result = ts.getShortest("abracadabra");
    printf("result is %s\n", result.c_str());*/

    /*CoinReversing cr;
    int input[10] = {916,153,357,729,183,848,61,672,295,936};
    double result = cr.expectedHeads(1000, input, 10);
    printf("result is %f\n", result);*/

   /* ConvexSequence cs;
    int input[50] = {854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
 686305822, 663789601};
    long long result = cs.getMinimum(input, 50);
    printf("result is %ld\n", result);*/
    return 0;
}