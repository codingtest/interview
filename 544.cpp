#include <stdio.h>
#include <string>
using namespace std;

class ElectionFraudDiv2
{
public:
    string IsFraudulent(int* percentages, int num);
};
int total = 10000;
string ElectionFraudDiv2::IsFraudulent(int* p, int num)
{
    int lower = 0 ;
    int higher  = 0;
    for ( int i = 0 ; i< num ; i++)
    {
        int low = ((double)p[i] - 0.5) * 100;
        int high = ((double)p[i] + 0.4) * 100;
        lower += low;
        higher += high;
    }
    if ( total >= lower && total <= higher )
        return "NO";
    else
         return "YES";
}


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
            for ( int k = j + i  + 1; k <= s.length() - i - 1   ; k++ ){
                if ( s.substr(j, i) ==  s.substr(k, i) ){
                    printf("%s, %s\n", s.substr(j,i).c_str(), s.substr(k,i).c_str());
                    res++;
                }

            }
        }
    }
    return res;
}
#include <vector>
class AntsMeet{
public:
    int countAnts(vector <int> x, vector <int> y, string direction);
};

int a[50];
int AntsMeet::countAnts(vector <int> x, vector <int> y, string direction)
{
    memset(a, 0, 50);
    for ( int i = 0 ; i < x.size(); i++){
        for ( int j = i; j < x.size();j++){
            if ( a[j] != 0 )
                continue;

            if ( x[i] == x[j] ){
                if ( y[i] < y[j] && direction[i] == 'N' && direction[j] == 'S'){
                    a[i] = 1;
                    a[j] = 1;
                    break;
                } else if ( y[i] < y[j] && direction[i] == 'S' && direction[j] == 'N') {
                       a[i] = 1;
                    a[j] = 1;
                    break;
                }
                continue;
            }

             if ( y[i] == y[j] ){
                if ( x[i] < x[j] && direction[i] == 'E' && direction[j] == 'W'){
                    a[i] = 1;
                    a[j] = 1;
                    break;
                } else if ( x[i] < x[j] && direction[i] == 'W' && direction[j] == 'E') {
                       a[i] = 1;
                    a[j] = 1;
                    break;
                }
                continue;
            }

             //if ( abs(x[i]-x[j]) == abs(y[i] - y[j]){
             //    if ( x[i] < x[j] && direct
             //}
            
        }
    }
}


int main()
{

        AkariDaisukiDiv2 as;
    int result = as.countTuples("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    printf("result is %d\n", result);

    /*int input[8] = {12, 12, 12, 12, 12, 12, 12, 12};
    ElectionFraudDiv2 ef;
    string result = ef.IsFraudulent(input, 8);
    printf("result is %s\n", result.c_str());*/
    return 0;
}