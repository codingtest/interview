#include <stdio.h>

int count = 10;

//dynamic programing
void listAll(char* str, int leftCount, int rightCount)
{
    if ( leftCount < 0 || leftCount != rightCount )
        return;

    if ( leftCount == 0 || rightCount == 0 )
    {
        str[2*count] = '\0';
        printf("%s\n",str - 2*count);
        return;
    }

    if ( leftCount > 0){
     /*   for (; rightCount > 0; rightCount-- ){
            *str = ')';
            str++;
        }
        str[2*count] = '\0';
        printf("%s\n",str - 2*count);
        return;*/
        *str = '(';
        str++;
        listAll(str, leftCount - 1, rightCount);
    }
    
    if ( leftCount < rightCount || rightCount > 0 )
    {
        *str = ')';
        str++;
        listAll(str, leftCount, rightCount - 1);
    }
}


int main()
{
    char* str = new char[2* count + 1];
    if ( str == NULL )
        return -1;
    listAll(str, 10, 10);

    delete[] str;

    return 0;

}