#include <stdio.h>
#include <string>
using namespace std;

string base = "acabaabaabcacaabc";

void buildNext(int* next)
{
    
    //求模式串T的next函数值并存入数组next  
    int i = 0; 
    next[0] = 0; 
    int j = 0;  
    while (i < base.length() - 1 )  
    {  
        if(/*j ==0 ||*/ base[i] == base[j])  
        {  
            ++i; ++j;  
            if (base[i] != base[j])  
                next[i] = j;  
            else  
                next[i] = next[j];  
        }   
        else   
        {  
            j = next[j];  
        }     
    }  
}

int KMP(string input)
{
    int* next = new int[base.length()];
    buildNext(next);
    int i=0;  
    int j=0;  
    while(i < input.length() && j< base.length() ){  
            if(/*j == 0 || */input[i] == base[j]) { ++i; ++j; }//继续比较后继字符  
            else   j = next[j];//模式串象右移动  
    }  
    delete[] next;
    if ( j < base.length() )
        return j - input.length()+ 1;
   //if(j>base[0])   return   i-base[0];//匹配成功  
   //           else   return   0;  
    
    return 0;
}

//SRM 551
class ColorfulBrick
{
public:
    int countLayouts(string bricks);
};

int ColorfulBrick::countLayouts(string bricks)
{
    if ( bricks.length() == 1 ) return 1;
    if ( bricks.length() == 0 ) return 0;
     char ch1, ch2;
     ch1 = bricks[0];
     ch2 = -1;
     for ( int i = 1 ;i < bricks.length(); i++)
     {
          if ( ch1 != bricks[i]  ){
              if ( ch2 == -1 )
                ch2 = bricks[i];
              else if ( ch2 != bricks[i] )
                  return 0;
          }
     }
     if (ch2 != -1 ) return 2;
     else return 1;
}

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

class ColorfulChocolates
{
public:
    int maximumSpread(string chocolates, int maxSwaps);
};


int ColorfulChocolates::maximumSpread(string chocolates, int maxSwaps)
{
    
    int res = 0;
    for ( int i = 0 ; i < chocolates.length(); i++ )
    {
        std::vector<int> cols;
        int ln = 0 ;
        int rn= 0;
        for ( int j = i + 1; j < chocolates.length(); j++ ){
            if ( chocolates[i] == chocolates[j])
                cols.push_back(ln);
            else
                ln++;
        }

         for ( int j = i - 1; j >= 0; j-- ){
            if ( chocolates[i] ==chocolates[j])
                cols.push_back(rn);
            else
                rn++;
        }

         sort(cols.begin(), cols.end());
         int sum = maxSwaps;
         int change = 0;
         for ( int k  = 0 ; k < cols.size(); k++)
         {
             if ( cols[k] <= sum ){
                 change++;
                 sum -= cols[k];
             } else {
                 break;
             }
                 
         }

         res = max( change, res);



    }
    return res + 1;
}


class ColorfulCupcakesDivTwo
{
public:
    int countArrangements(string cupcakes);
};

const long long mod = 1000000007;

int count(string cupcakes, char ch, int sum0, int sum1, int sum2)
{
    long long  res = 0;
    if ( sum0 == 0 && sum1 == 0 && sum2 == 0 )
        return 1;

    if ( ch != 'A' && sum0 != 0)
        res += count(cupcakes, 'A',sum0 - 1, sum1, sum2);
    if ( ch != 'B' && sum1 != 0)
         res += count(cupcakes, 'B',sum0, sum1 -1 , sum2);
    if ( ch != 'C' && sum2 != 0)
         res += count(cupcakes, 'C',sum0, sum1  , sum2 - 1);
    return res % mod;
}

int ColorfulCupcakesDivTwo::countArrangements(string cupcakes)
{
    int sum[3] = {0};
   for ( int i = 0 ; i < cupcakes.length() ; i++ )
   {
       switch(cupcakes[i]){
       case 'A':
           sum[0]++;
            break;
       case 'B':
           sum[1]++;
           break;
       case 'C':
           sum[2]++;
           break;
       }
   }
  

   return count(cupcakes,0,sum[0], sum[1], sum[2]);
}

class ColorfulWolves
{
public:
    int getmin(vector <string> colormap);
};

int MAX = 50000000;
int a[50][50];

int ColorfulWolves::getmin(vector <string> colormap)
{
    memset(a, 0 , sizeof(a));
    int length = colormap.size();
    //init a
    for ( int i = 0 ; i  < colormap.size(); i++ ){
        int ans = 0;
        for ( int j = 0; j < colormap.size(); j++ ){
            if ( colormap[i][j] == 'Y' ){
                a[i][j] = ans;
                ans++;
            } else {
                a[i][j] = MAX;
            }
        }
    }
      for ( int i = 0 ;i < length; i++){
        for ( int j = 0; j < length ; j++){
            for ( int k = 0; k < length; k++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
      }
      return a[0][length-1];
}

void reverse(char* input,int  length)
{
       char ch;
    //   int length = strlen(input);
    for ( int i = 0 ; i < length/2 ; i++ )
    {
        ch = input[i];
         input[i] = input[length - i - 1];
        input[length - i - 1] = ch;
    }
//    return input;
}
void CS(char* input)
{
     int length = strlen(input);
    reverse(input, length);
    
    char* start = input;
//    for ( int i =0; i <= length; i++)
//    {
//        if ( i == length || input[i] == ' '){
//            
//            strncpy((char*)input.c_str() + start,(char*)reverse(input.substr(start, i - start)).c_str(), i - start );
////reverse(input.substr(start, i - start));
//            start = i+1;
//            i++;
//        }
//    }
    for ( ; *input != '\0' ; input++ )
    {
        if ( *(input + 1) == ' ' || *(input + 1) == '\0' )
        {
            reverse(start,input-start + 1 );
            start= input + 2;
        }
    }
   // strncpy((char*)input.c_str() + start,(char*)reverse(input.substr(start, input.size() - start)).c_str(),  input.size()  - start );
   // return input;
}

int main()
{
    //int position = KMP("abaabcac");
    //printf("result is %d\n", position);

   // ColorfulBrick cb;
   //int result =  cb.countLayouts("BABA");
    //ColorfulCupcakesDivTwo cc;
    //int result = cc.countArrangements("ABC");

    /*ColorfulWolves cw;
    cw.getmin(
   printf("result is %d\n", result);*/

    char* input1 = "hello he world";
    char input[20];
    memset(input, 0, 20);
    strncpy(input, input1, strlen(input1));
 CS(input);
    printf("result is %s\n", input);



    return 0;
}