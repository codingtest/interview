#include <stdio.h>
#include <stdlib.h>
#include <string>

void heapsort()
{
}

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

bool CountSort(char* input[], int num, int list)
{
    //count as the list 
    int* count = new int[num];
    if ( count == 0 )
        return;
    memset(count, 0 , num);

    for( int i = 0 ; i < num; i++ ){
        int value =  input[i][list] - 'A';
        count[value]++;
    }
    //count the position
    for ( int i = num - 1;i >= 0 ; i--){

    }

    char* tmp[16] ;



    delete[] count;


}

void RadixSort(char* input[], int num, int list)
{
    for( int i = 2 ; i >= 0; i-- ){
        if ( CountSort(input, num, i) == false )
            return;
    }
}

int main()
{
    /*int input[10] = { 23,12,4,775,245,67,2,3,18,3};
    quicksort(input, 0, 9);

    for (int i = 0 ; i < 10; i++)
        printf("%d, ",input[i]);*/

    char* input[16] = {"COW", "DOG","SEA", "RUG", "ROW", "MOB", "BOX", "TAB",
        "BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"};

    RadixSort(input, 16, 3);


        return 0;

   }