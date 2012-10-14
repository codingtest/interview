
#include <stdio.h>
#include <math.h>

//level one
class Pillars
{
public:
    double getExpectedLength(int w, int x, int y);
};

double Pillars::getExpectedLength(int w, int x, int y)
{
    double result = 0;
    int count = 0;
    for ( int i = 1 ; i <= x; i++ ){
        //int low = ( i - w > 0 ) ? i - w: 0;
        for ( int j = 1 ; j <= y;j++ ){
            double s = sqrt((double)(( i - j ) * ( i - j ) + w * w));
            result += s;
            count++;
        }
    }
    if ( count == 0 ) return 0;
    return result/count;
}

class RectangularSum
{
public:
    long minimalArea(int height, int width, long S);
};

//need check
long  RectangularSum::minimalArea(int height, int width, long S)
{
    long result = 0x7fffffff;
    for ( int i = 1 ; i <= height; i++ )
    {
        for ( int j = 1; j <= width; j++ ){
            long long temp = ( i * ( i - 1) /2 ) * j * width + ( j * ( j - 1) / 2) * i ;
            if ( temp > S )
                break;
            /*if ( temp < S ) 
                continue;
            long count = i * j;
            result = result > count ? count : result;*/
            long long res = S - temp;
            if ( res % ( i * j ) != 0 )
                //cannot find the result in the sub result
                continue;
            long val = res / i / j;
            long r = val / i, c = val % j;
            if ( r + i <= height && c + j <= width ) {
                long count = i * j;
                result = result > count ? count : result;
            }

        }
    }
    return result;
}

int main()
{
    /*Pillars pl; 
    double result = pl.getExpectedLength(10, 15,23);*/
    RectangularSum rs;
    long result = rs.minimalArea(50000, 50000, 963761198400);

    printf("result is %d\n", result);
    return 0;
}