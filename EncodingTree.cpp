//http://community.topcoder.com/stat?c=problem_solution&cr=144400&rd=7995&pm=4700
//BST tree
// Single Round Match 261 Round 1 - Division I, Level Two 
#include <string>
using namespace std;

int ntrees[20];

string f(int number, int index,char aa)
{
    if ( number == 0 ) return "";
    int root = 0;
    //find the root node
    while( ntrees[root] * ntrees[number - 1 - root] <= index  ){
        index -= ntrees[root] * ntrees[number - 1 - root];
        ++root;
    }
    string s;
    s += char(aa + root);
    s += f(root, index / ntrees[number - 1 -root], aa );
    s += f(number - 1 - root, index % ntrees[number - 1 -root],aa + root + 1);
    return s;
}

string EncodingTrees(int number, int index )
{
    index--;
    ntrees[0] = 1;
    for ( int i = 1; i <= 19; i++ ){
        ntrees[i] = 0;
        for ( int j = 0; j <= i - 1; j++ ){
            ntrees[i] += ntrees[j] * ntrees[i - 1 - j];
        }
    }
    if ( index < 0 || index >= ntrees[number])
       //out of range
       return "";
    return f(number, index, 'a');
}

int main()
{
    string result = EncodingTrees(12,121212);
    return 0;
}

