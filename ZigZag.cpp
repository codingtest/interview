#include <stdio.h>

int input[] =  { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
size_t input_size  = 50 ;

int ZigZag()
{
    if (input_size == 1 ) return 1;

    int temp[50];
    for ( int i = 0; i < input_size; i ++){
        temp[i] = input[i+1] - input[i];
    }
    int ii = 0;
    while ( ii < 49 && temp[ii] == 0 ) ii++;
    if ( ii == 49 ) return 1;
    int len = 2;
    int dir = temp[ii];
    for ( int i = ii + 1; i < 49; i++){
        if ( temp[i] * dir < 0 ){
            len++;
            dir = dir * -1;
        }
    }
    return len;
}

int main()
{
    int result= ZigZag();
    printf("result is %d\n", result);
    return 0;
}