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

string minstr(string  letters, int minlnv, string minStr)
{
    if (letters == "") 
        return "";
    for ( int i = 0; i < letters.size() ; i++)
    {
        if ( ( minStr.length() > 0 ) && ( minStr[0] > letters[i] ) )
            continue;
        int nniv = max(minlnv - i, 0);
        int nn = letters.size() - 1;
        //is less , it is impossible to hve the string 
        if ( nn*(nn -1)/2 >= nniv ) {
            string nletters = letters.substr(0, i ) + letters.substr(i+1);
            string nminStr = "";
            if ( ( minStr.length() > 0 ) && ( minStr[0] == letters[i] ) ) 
                nminStr = minStr.substr(1);
            else 
                nminStr = minStr;
            return string(1, letters[i] ) + minstr(nletters, nniv, nminStr);
        }
    }
}

class StrIIRec
{
public:
    string recovstr(int n, int minInv, string minStr)
    {
         string a = "";
         for (int i = 0 ; i < n; i++ )
             a = a + (char)('a'+ i);

         return minstr(a, minInv, minStr);
        //return a;
    }
};

//SRM 528 , div two , level two
class Cut
{
public:
    int getMaximum(int* eelLengths, int num, int maxCuts);
};

int Cut::getMaximum(int* eelLengths, int num, int maxCuts)
{
    if ( eelLengths == NULL || num == 0 ) return 0;
    int count = 0;
    int cut;
    for ( int i =0 ; i < num;i++ ){
        //if ( maxCuts == 0) return count;
        if ( eelLengths[i] % 10 == 0 ){
            cut = min(eelLengths[i]/10 -1,maxCuts);
            count += cut + 1;
           
            maxCuts -= cut;
             if ( maxCuts == 0 ) return count;
        }
    }

     for ( int i =0 ; i < num;i++ ){
        //if ( maxCuts == 0) return count;
        if ( eelLengths[i] % 10 != 0 ){
            cut = min(eelLengths[i]/10 ,maxCuts);
            count += cut ;
           
            maxCuts -= cut;
             if ( maxCuts == 0 ) return count;
        }
    }
     return count;
}

// SRM 528 Div one level two
class SPartition
{
public:
    long getCount(string s);
};

char wanted[21];
//long res = 0;

long mem[21][21];
int length;
string s;

//find the num's result for the target string
long rec( int a, int b)
{
    long res = mem[a][b];
    if ( res == -1 ){
        if ( a == length/2 && b == length/2 ){
            //finded the answer
            res = 1;
        } else {
            res = 0;
            if ( a < length/2 && s[a+b] == wanted[a]){
                res += rec(a + 1, b);
            }
            if ( b < length/2 && s[a+b] == wanted[b]){
                 res += rec(a, b+1);
            }
        }
        mem[a][b] = res;
    }
    return res;
}

//find the possible string
long backtrack(int p, int tx, int to )
{
     if ( tx== 0 && to == 0){
         memset(mem, -1, sizeof(mem));
         printf("%s\n", wanted);
         return rec(0,0);

     } else {
         long res = 0;
         if ( tx != 0 ){
             wanted[p] = 'x';
             res += backtrack(p+1, tx -1 ,to);
         } 
         if ( to != 0 ){
             wanted[p] = 'o';
             res += backtrack(p+1, tx, to-1);
         }
         return res;
     }
}

long SPartition::getCount(string ms)
{
    //count the number
    int to = 0;
    int tx = 0;
    s = ms;
    for ( int i = 0 ; i < s.length(); i++ )
    {
        if ( s[i] == 'o' ) to++;
        else if ( s[i] == 'x' ) tx++;
    }

    length = s.length();
    
    if ( tx %2 != 0 || to % 2 != 0 ) return 0;

    return backtrack(0, tx/2, to/2);
}

//SRM 528 div one level three
//need more study
class ColorfulCookie
{
public:
    int getMaximum(int* cookies, int num, int P1, int P2);
};

#include <math.h>
int dp[50][2002];
bool IsPossible(int* cookies, int num, int P1, int P2, int Sum)
{
    memset(dp, 0, sizeof(dp));

    dp[0][0] = -1;
    for ( int i = 1 ;i <= num ; i++ ){
        int p = i - 1;
        for ( int j = 0; j <= Sum;j++){
            //xp is this cookies used as P1, yp is the cookies used as P2
            for ( int xp = 0 ; xp <= Sum && xp*P1 <= cookies[p] ; xp++){
                int yp = Sum - xp;
                yp = min(yp, (cookies[p]  - xp * P1 ) / P2 );
                dp[i][Sum] = max(dp[i][Sum], yp + dp[p][Sum-xp]);
            }
        }
    }

    return dp[num][Sum] >= Sum;

}

int ColorfulCookie::getMaximum(int* cookies, int num, int P1, int P2)
{
    //search the count that pushed
    int ll = 0;
    int lh = 40*50 + 1;

    int x;
    while( ll + 1 < lh ){
         x = ( lh + ll ) /2;
        if ( IsPossible(cookies, num, P1, P2, x) ) {
            ll = x;
        } else {
            lh = x;
        }
    }
    return  ll * ( P1 + P2);
}


//SRM 538 div two level one
// 10 minutes total
class LeftOrRight
{
public:
    	int maxDistance(string program);
};

int LeftOrRight::maxDistance(string program)
{
    //farest is in Left
    int bestL = 0;
    int pos = 0;
    for (int i = 0 ; i < program.length(); i++ )
    {
        
        switch(program[i]){
        case 'L':
            pos++;
            break;
        case 'R':
            pos--;
            break;
        case '?':
                pos++;
                break;
        default:
            break;
        }
        bestL = max(bestL, pos);
    }

      int bestR = 0;
       pos = 0;
    for (int i = 0 ; i < program.length(); i++ )
    {
        
        switch(program[i]){
        case 'L':
            pos--;
            break;
        case 'R':
            pos++;
            break;
        case '?':
                pos++;
                break;
        default:
            break;
        }
        bestR = max(bestR, pos);
    }
    return max(bestR, bestL);
}

//SRM 538 div two level two
//18 mintues
class EvenRoute
{
public:
    string  isItPossible(int* x,int num1,  int* y, int num2, int wantedParity);
};

string EvenRoute::isItPossible(int* x,int num1,  int* y, int num2, int wantedParity)
{
    if ( x == NULL || y == NULL || num1 != num2 || wantedParity/2 != 0 )
        return "CANNOT";

    for ( int i = 0 ; i < num1; i++ ) {
        if ( ( x[i] + y[i])%2 == wantedParity)
            return "CAN";
    }
    return "CANNOT";
}

//SRM div one, level two
class TurtleSpy
{
public:
    double maxDistance(vector<string>  commands);
};

#include <stdio.h>
#include <cmath>

double TurtleSpy:: maxDistance(vector<string>  commands)
{
    int fowd = 0;
    int backwd = 0;
    bool d[360];
    d[0] = true;
    for ( int i = 0 ; i < commands.size(); i++ ){
        //string cmd;
        char cmd[10];
        memset(cmd, 0 ,10);
        int number = 0;
        sscanf(commands[i].c_str(),"%s %d", cmd, number);
        if ( cmd == "forward"){
            fowd += number;
        } else  if ( cmd == "backward"){
            fowd += number;
        } else{
            int val = number;
            if (cmd == "left"){
                val = 360 - val;
            }

            bool temp[360];
            memset(temp, 0 , 360);
            for ( int i = 0; i< 360; i++ ){
                //current value + val set to 1
                temp[i] = d[i] | d[ (i+val)%360 ];
            }
             for ( int i = 0; i< 360; i++ ){
                 d[i] = temp[i];
             }
        }
    } 
     double pi = 2 * acos((double)0);
    double res = abs(fowd - backwd);
    for ( int i = 0 ; i < 360; i++){
        double a = (double)fowd;
               double b = (double)backwd;
               double c = a * a + b * b - 2 * a * b * cos(i / 180.0 * pi);
               res = max(res, c);
    }

    return res;

}

//SRM 543 div two , level one
class EllysTSP
{
public:
    int getMax(string places);
};

int EllysTSP::getMax(string places)
{
    int nc = 0;
    int nv = 0;
    for ( int i = 0 ; i < places.length(); i++ )
    {
        if ( places[i] == 'V')
            nv++;
        else if (places[i] == 'C')
            nc++;
    }

    if ( nc == 0 ){
        if ( nv != 0 ) return 1;
        else return 0;
    }

    if ( nc > nv ){
        return nv * 2 + 1;
    }
    else 
        return nc * 2 + 1;

}



int main()
{
    /*StrIIRec sr;
    string result = sr.recovstr(2,1,"ab");
    printf("result is %s\n", result.c_str());*/

    //Cut ct;
    //int input[4] ={30, 50, 30, 50};
    //int result = ct.getMaximum(input, 4, 360);
    //printf("result is %d\n", result);

    //SPartition sp;
    //long result = sp.getCount("ooooxoox");
    //printf("result is %d\n", result);

  /*  ColorfulCookie cc;
    int input[3] = {50, 250, 50};
    int result = cc.getMaximum(input, 3, 50, 100);*/

    //LeftOrRight lr;
    //int result = lr.maxDistance("LL???RRRRRRR???");
    //printf("result is %d\n", result);
    /*EvenRoute er;
    int input1[4] = {-1,-1,1,1};
    int input2[4] = {-1,1,1,-1};
    string  result = er.isItPossible(input1,4, input2,4, 1);
    printf("result is %s\n", result.c_str());
*/

    /*vector<string> input;
    input.push_back(string("left 10"));
    input.push_back( string("forward 40"));
    input.push_back(string( "right 30"));
    input.push_back(string( "left 10"));
    input.push_back(string("backward 4"));
    input.push_back(string("forward 4") );
    TurtleSpy ts;
    double result = ts.maxDistance(input);
    printf("result is %f\n", result);*/
    EllysTSP et;
    int res = et.getMax("VVVVCVV");
    printf("result is %d\n", res);

    return 0;
}