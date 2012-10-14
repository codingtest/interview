#include <stdio.h>

class KleofasTail
{
public:
    long long countGoodSequences(long K, long A, long long B);
};

//too slow 
/*long KleofasTail::countGoodSequences(long K, long A, long B)
{
    int count = 0;
    for ( long i = A ; i <= B ; i++ )
    {
        //check has the value
        long num = i;
        while ( num >= 1 ){
            if ( num == K ) {
                count++ ;
                break;
            } else if ( num < K ) {
                break;
            }

            if ( num % 2 == 0 ) num = num / 2;
            else  num = num - 1;
        }
    }
    return count;
}*/

//level one
long long KleofasTail::countGoodSequences(long K, long A, long long B)
{
    long long count = 0;
    if ( K == 0 ) return B - A + 1;
    long long L = K, R = K, ans = 0, s, f;
    if (!(R & 1)) R++;
      while (L <= B) {
            if (L > A) s = L;
            else s = A;
            if (R < B) f = R;
            else f = B;
            if (s <= f) count += f-s+1;
            L = L*2;
            R = R*2+1;
      } 
      return count;
}

class FavouriteDigits
{
public:
    long findNext(long N, int digit1, int count1, int digit2, int count2);
};  

inline void swap( int a , int b )
{
    int temp = a;  
    a = b ; 
    b = a;
}

#define max(a, b) (a>b?a:b)

int good( long long  N, long long x, int k, int d1, int c1, int d2, int c2 )
{
  c1 = max(c1, 0);
  c2 = max(c2, 0);
  if (k < c1 + c2)
    return 0;
  int d3 = 9, c3 = k - (c1 + c2);
  while (c3--) x = x * 10 + d3;
  while (c2--) x = x * 10 + d2;
  while (c1--) x = x * 10 + d1;
  printf("x = %I64d\n", x);
  return N <= x;
}


long FavouriteDigits::findNext(long N, int d1, int c1, int d2, int c2)
{
    if (d1 > d2){
        swap(d1, d2);
        swap(c1, c2);
    }
 
    long long  x = 0;
    int k = 18;
    while (k > 0)
    {
        int t = 0;
        //printf("x = %I64d, k = %d\n", x, k);
        while (!good(N, x * 10 + t, k - 1, d1, c1 - (t == d1 && (x || d1)), d2, c2 - (t == d2 && (x || d2))))
            t++;
        c1 -= (t == d1 && (x || d1));
        c2 -= (t == d2 && (x || d2));
        x = x * 10 + t;
        k--;
    }
    return x;
}

#include <vector>
#include <string>
using namespace std;

class SRMIntermissionPhase
{
};



//div2 level2
class SRMCodingPhase
{
public:
    int countScore(int* points,int num1, int* skills, int num2,int luck);
};


int memo[3][128][128];

int find ( int id, int tm, int* points,int num1, int* skills, int num2,int luck)
{
    //all problem is solved
    if ( id == 3 ) return 0;
    if ( memo[id][tm][luck] != 0 ) return memo[id][tm][luck];

    //do not choose this problem
    int res = find(id+1, tm, points,num1, skills, num2, luck);

    for ( int t = 1; t <= skills[id] && t <= tm; t++ )
    {
        int need = skills[id] - t;
        if ( need <= luck )
            //use need lucks for problem id
            res = max(res, find(id+1, tm-t, points, num1, skills, num2, luck-need) + points[id] - (2<<id)*t);
    }
    return memo[id][tm][luck] = res;

}

int SRMCodingPhase::countScore(int* points,int num1, int* skills, int num2,int luck)
{
    memset(memo, 0, 3*128*128);
    return find(0, 75, points, num1, skills, num2, luck);
}

//div2 level3
#define MOD 1000000007 
class SRMSystemTestPhase
{
public:
    int countWays(vector<string> description);
};
int SRMSystemTestPhase::countWays(vector<string> description)
{
        return 0;
}

//Single Round Match 544 Round 1 - Division II, Level Two
class BoardSplitting
{
public:
    int minimumCuts(int desiredLength, int desiredCount, int actualLength);
};

int BoardSplitting::minimumCuts(int desiredLength, int desiredCount, int actualLength)
{
    if (desiredLength == actualLength)
    {
        return desiredCount;
    }
    
    int res = 0;
    int currentLength = actualLength;

    while ( desiredCount){
        if ( desiredLength == currentLength ){
            desiredCount--;
            currentLength = actualLength;;
        }else if ( desiredLength < currentLength ){
            res++;
            desiredCount--;
            currentLength = currentLength - desiredLength;
        } else {
            currentLength += actualLength;
        }

    }
    return res;
}

// Division Two - Level Three:
//dynamic programing
int dp[51][51][51][51];
class AliceBobShuffle
{
public:
    int countWays(int* AliceStart,int num1, int* BobStart,int num2, int* AliceEnd, int num3, int* BobEnd, int num4);
};

int count(int* AliceStart,int num1, int* BobStart,int num2, int* AliceEnd, int num3, int* BobEnd, int num4)
{
    // 1 as none. 0 as not decided
    int res = dp[num1][num2][num3][num4] - 1;
    if ( res == -1 ){
        if ( num1 ==  0 && num2 == 0 && num3 == 0 && num4 == 0 )
            return 1;
        if ( num1 > 0 && AliceStart[num1 - 1] == AliceEnd[num3 - 1] )
            res += count(AliceStart,num1 - 1, BobStart,num2, AliceEnd, num3 - 1, BobEnd, num4);
        else if ( num1 > 0 && AliceStart[num1 - 1] == BobEnd[num4 - 1] )
            res += count(AliceStart,num1 - 1, BobStart,num2, AliceEnd, num3, BobEnd, num4 - 1);
        if ( num2 > 0 && BobStart[num2 - 1] == AliceEnd[num3 - 1] )
            res += count(AliceStart,num1, BobStart,num2 - 1, AliceEnd, num3 - 1, BobEnd, num4);
        else if ( num1 > 0 && BobStart[num2 - 1] == BobEnd[num4 - 1] )
            res += count(AliceStart,num1, BobStart,num2 - 1, AliceEnd, num3, BobEnd, num4 - 1);
        res = res + 1;
    }

    return res;
}


int AliceBobShuffle::countWays(int* AliceStart,int num1, int* BobStart,int num2, int* AliceEnd, int num3, int* BobEnd, int num4)
{
    memset(dp, 0, sizeof(dp));
    return count(AliceStart,num1, BobStart,num2, AliceEnd, num3, BobEnd, num4);
}


//class ElectionFraudDiv1
//{
//public:
//    int MinimumVoters(int* percentages, int num1);
//};
//
//int MAX = 201;
//
//int ElectionFraudDiv1::MinimumVoters(int* percentages, int num)
//{
//    int sum = 0;
////double total = 0;
//    int lower = 0;
//    int higher = 0;
//    for ( int total = 0 ; total < MAX ;total++)
//    {
//        for ( int i = 0 ; i < num ; i++ ){
//            percentages[i]
//        }
//        
//
//
//        return total;
//       
//    }
//}

class AkariDaisukiDiv2
{
public:
    int countTuples(string S);
};

int AkariDaisukiDiv2::countTuples(string s)
{
    int res = 0;
    for ( int i = 1; i <= ( s.length() - 3 ) / 2 ; i++ ){
        for ( int j = 1; j <= s.length() - 2 ; j++ ){
            for ( int k = j + 2; k < s.length() - i - 1   ; k++ ){
                if ( s.substr(j, i) ==  s.substr(k, i) )
                    res++;

            }
        }
    }
    return res;
}



int main()
{
    AkariDaisukiDiv2 as;
    int result = as.countTuples("waaiusushioakariusushiodaisuki");

    printf("result is %d\n", result);

    /*KleofasTail kt;
    long long result = kt.countGoodSequences(3, 0, 1000000000000000000);
    printf("result is %ld\n", result);*/

   /* FavouriteDigits fd;
    long long result = fd.findNext(47, 2, 1, 0, 2);
    printf("result is %ld\n", result);*/

    /*SRMCodingPhase sc;
    int points[3] ={300, 600, 900};
    int skills[3] = {30, 65, 90};
    int result = sc.countScore(points, 3, skills, 3, 25);*/
  /*  BoardSplitting bs;
    int result = bs.minimumCuts(314,159,26);*/

    /*AliceBobShuffle ab;
    int AliceStart[2] = {1, 3};
    int BobStart[2] = {2, 4};
    int AliceEnd[2] = {2, 3};
    int BobEnd[2] = {1, 4};
    int result = ab.countWays(AliceStart,2, BobStart,2, AliceEnd, 2, BobEnd, 2);*/
    


    return 0;
}