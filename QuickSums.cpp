#include <string>
using namespace std;

string num;
int num_size;
int target;
int data[15];
int len_result = -1;

//dynamic programing
//http://community.topcoder.com/stat?c=problem_solution&cr=7356427&rd=5072&pm=2829
// not pass
void sum(int len, int start)
{
    if ( start == num_size ){
        //goto the last one
        int k = 0;
        int result = 0;
        for ( int i  = 0 ; i < len; i++ ){
            int number1  = num[k] - '0';
            for ( int j = k + 1; j < data[i]; j++ ){
                number1 = number1 * 10 + ( num[j] - '0' );
            }
            result = result + number1;
            k = data[i] + 1;
        }
        if ( result == target && len - 1 < len_result )
            len_result =  len - 1;
        //return;
        //return len;
    }
    for ( int i = start; i < num_size; i++ ){
        data[len] = i;
        sum(len+1, i+1);
    }
}

void QuickSums()
{
     sum(0, 0);
}

int main()
{
    num = "382834";
    target = 100;
    num_size = num.length();

    QuickSums();

    printf("result len is %d\n", len_result);

    return 0;
}