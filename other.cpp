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

void quicksort(int input[], int start,int end)
{
    if ( start < end ){
       int k = start;
       int i  = start + 1;
       for ( ;i <= end; i++){
           if  ( input[i] < input[start] ){
               int temp = input[++k];
               input[k] = input[i];
               input[i] = temp;
           }
       }

        int temp = input[k];
        input[k] = input[start];
        input[start] = temp;

        quicksort(input, start, k - 1);
        quicksort(input, k + 1, end);
    }

}

void ConversionMachine(string a, string b , int cost[], int cost_num, int max_cost)
{

}


//SRM550 DIV2 250PT（字符串水题）
int EasyConversionMachine(string a, string b ,int max)
{
    if ( a == "" || b == "" || a.length() != b.length() )
        return false;

    int count = 0;
    for ( int i = 0 ; i < a.length(); i++){
        if ( a[i] != b[i] ) count++;
    }
    if ( count <= max ) return true;
    else return false;
}

#include <vector>

//SRM 150 DIV 2 250pt（队列）
int WidgetRepairs(vector<int> input, int numPer)
{
    int remain_count = 0;
    int working_day = 0;
    for ( int i = 0 ; i < input.size(); i++ )
    {
        if ( ( input[i] + remain_count ) != 0 )
            working_day++;
        remain_count = ( input[i] + remain_count - numPer ) > 0 ? (input[i] + remain_count - numPer) : 0;
    }

    if ( remain_count > 0 ){
        if ( remain_count % numPer != 0 )
            working_day += ( remain_count / numPer ) + 1;
        else
            working_day += ( remain_count / numPer );
    }
    return working_day;
}

//     Single Round Match 548 Round 1 - Division II, Level One
class KingdomAndDucks
{
public:
    int minDucks(int* duckTypes, int input_num)
    {
       int t[51];
       for ( int i = 0 ; i < input_num ; i++ ){
           t[duckTypes[i]]++;
       }
       int count;
       int max;
       for ( int i = 1 ; i <= 51; i++ ){
           if ( t[i] != 0 ) count++;
           max = ( t[i] > max )? t[i]: max;
       }
       return max*count;
    }
};

//http://community.topcoder.com/stat?c=problem_statement&pm=11967&rd=15170
//548 level two
class KingdomAndTrees
{
public:
    int minLevel(int* heights, int number);
};

inline int max(int x,int y)
{
    return x>y?x:y;
}    

bool check(int* h, int number, int try_number )
{
    int last = max(h[0] - try_number, 1);
    for ( int i = 0 ; i < number ; i++ ){

        if ( h[i] + try_number < last )
            return false;
        last = max(h[i] - try_number, last + 1);
    }
    return true;
}

int KingdomAndTrees::minLevel(int* heights, int number)
{
    //find the largest number
    int heightest = 0;
    for ( int i = 0 ; i < number ; i++){
        heightest = heightest > heights[i]? heightest : heights[i];
    }

    heightest += number;
    int lowest = 0;
    
    int result = -1;
    while (1){
        if ( heightest <= lowest ) break;
        int try_number = ( heightest + lowest ) / 2;
        if ( check(heights, number, try_number) == true ){
            result = try_number;
            heightest = try_number - 1;
        } else {
            lowest = try_number  + 1;
        }
    }

    return result;
    
}

//Dynamic Programming
//550 level three
class ConversionMachine
{
    int countAll(string word1, string word2, int costs,int number, int maxCost)
    {

    }
};

int main()
{
    KingdomAndTrees kd;
    int input[5] = {548, 47, 58, 250, 2012};
    int result = kd.minLevel(input, 5);
    printf("result is %d\n", result);
    return 0;
}