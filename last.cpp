#include <vector> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <queue> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <string> 
#include <cassert> 

using namespace std;



inline string insertCharAt(string s, char c, int i)
{
	string start = s.substr(0, i);
	string end = s.substr(i);
	return start + c + end;
}

vector<string> getPerms(string s)
{
	vector<string> res;
	if ( s.size() == 1 )
    {
        res.push_back(s);
		return res;
    }
	
	char f = s[0];
	string rem = s.substr(1);
	vector<string> t = getPerms(rem);
    
	for ( int i = 0 ; i < t.size(); i++ )
	{
		for ( int j = 0 ; j < t[0].length() + 1; j++)
		{
			string r = insertCharAt(t[i], f, j);
            res.push_back(r);
		}
	}
	return res;
}

int main()
{
    vector<string> res =  getPerms("abc");
    for ( int i = 0 ; i < res.size(); i++ )
	{
            printf("%s\n", res[i].c_str());
    }
    return 0;
}
