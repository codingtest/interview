#include <stdio.h>

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

class MergersDivOne
{
public:
    double findMaximum(int* revenues, int num);
};

double MergersDivOne::findMaximum(int* revenues, int num)
{
    if ( revenues == NULL )
        return 0;

    quicksort(revenues, 0, num - 1);
    double result  = revenues[0];
    for (int i = 1; i < num; i++){
        result = ( result + revenues[i] ) / 2; 
    }
    return result;
}


class RollingDiceDivOne
{
public:
    long mostLikely(int* dice, int num);
};

long RollingDiceDivOne::mostLikely(int* dice, int num)
{
    if ( dice == NULL )
        return 0;

    quicksort(dice, 0, num - 1);

    int total = 0;
    double tmp = 0;
    for ( int i = 0 ; i < num; i++ ){
        total += dice[i];
        tmp += dice[i] + 1;
    }
    total++;
    if ( tmp / 2 < total ) return tmp/2;
    else return total;
}

class BinaryPolynomialDivOne
{
public: 
    int findCoefficient(int a,int num, long m, long k);
};

int BinaryPolynomialDivOne::findCoefficient(int a,int num, long m, long k)
{
}

int main()
{
    ////Level one
    //MergersDivOne md;
    ////int input[3] = {5, -7, 3};
    //int input[6] = {10, -10, 100, -100, 1000, -1000};
    //double result = md.findMaximum(input, 6);
    //printf("result is %f\n",result);


    //Level two
    int input[20] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240};
    RollingDiceDivOne rd;
    long result = rd.mostLikely(input, 20);
    printf("result is %d\n", result);







    return 0;
}