#include <string>
#include <vector>
using namespace std;

vector<string> tree;

// too complex , can we find the better solution
//http://community.topcoder.com/stat?c=problem_solution&cr=20018722&rd=9999&pm=6713

const int MAX = 1<<23;
char ch[MAX];
 int pos;

 //check the tree is valided or not
 bool valid(int i)
 {
    int left = i * 2;
    if ( ch[left] )
    {
        //find the next char
        while ( ch[left * 2 + 1] ) left = left*2 + 1;
        if ( ch[left] > ch[i] || !valid(i*2) ) return false;
    }
    int right = i * 2  + 1;
    if ( ch[right] )
    {
        while( ch[right*2] ) right * 2;
        if ( ch[right] <= ch[i] || !valid(i*2 + 1) ) return false;
    }
    return true;
 }

string IncompleteBST()
{
    int n = tree.size();
    memset(ch, 0 ,sizeof(ch));
    //build the tree
    for ( int i = 0 ; i < tree.size() ; i++ ){
        int tmp = 0 ;
        int len = tree[i].length();
        for ( int j = 2; j <  len; j++ ) tmp = tmp * 10 + tree[i][j] - '0';
        ch[tmp] = tree[i][0];
        if ( tree[i][0] == '?' ) pos = tmp;
    }
    //find the value
    string ans = "";
    for(char c = 'A';c <= 'Z';c ++)
    {
        ch[pos] = c;
        if( valid(1) )
            ans += c;
    }
    return ans;

}

int main()
{
    tree.push_back("B 1");
    tree.push_back("? 2");
    string result = IncompleteBST();
    return 0;
}

