#include <stdio.h>

class FoxAndGCDLCM
{
public:
    long get(long G, long L);
};

template<class T> inline T gcd(T a, T b)
{
    if ( a < 0 ) return gcd(-a, b);
    if ( b < 0 ) return gcd(a, -b);
    if ( b == 0 ) return a;
    return gcd(b, a%b);
}

long FoxAndGCDLCM::get(long G, long L)
{
    if ( L%G != 0 ) return -1;

    int temp = L/G;
    long result = -1;
    for  ( long a = 1; a * a < temp; a++){
        if ( L %a == 0 && gcd(a, temp/a) == 1 ){
            long s = a + temp/a;
            if ( result < 0 || result > s) result = s;
        }
    }
    return result;
}

class FoxAndBusiness
{
public:
    double minimumCost(int K, int totalWork, int a , int num1,  int p, int num2)
    {
        //count the pay and machine pay per unit for each person


        //sort the pay

        //find the target person

        //count the number
    }
};

#include <vector>
using namespace std;
class TurtleSpy
{
public:
    double maxDistance(vector<string> commands);
};

double TurtleSpy::maxDistance(vector<string> commands)
{
}


int main()
{
    //level one
     FoxAndGCDLCM fa;
     long result = fa.get(2, 20);
     if ( result != -1 ){
        printf("result is %d\n", result * 2);
     }

     //level two


    return 0;
}