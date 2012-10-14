#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <queue> 
#include <map>
using namespace std; 

vector<string> input;
vector<string> temp;

vector<vector<string>> output;
//map<string, vector<string>> output;

class StringParse{
public:
    StringParse(string s) : m_s(s),m_position(1) {};
    string getNextString();
private:
    string m_s;
    int m_position;

};

string StringParse::getNextString()
{
    if ( m_position == -1 ) 
        return  "";

    for ( int i = m_position; i < m_s.size(); i++ ){
        if ( m_s[i] == '/' ) {
            m_position = i + 1;
            return m_s.substr(m_position,i);
        }
    }
    m_position = -1;
    return "";
}

int find(string s) { 
  for( int i = 0; i < temp.size(); i++ ) 
    if( temp[i] == s ) return i; 
  temp.push_back(s); 
  output.push_back(vector<string>()); 
  return temp.size()-1; 
} 


void DirectoryTree()
{
    //output.insert( pair<string,vector<string>>("ROOT", vector<string>()));

    for ( int i = 0 ; i < input.size(); i ++ ){
        StringParse s(input[i]);
        string t = s.getNextString();
        while ( t != "" ){
            output[find(t)].push_back(t);
            t = s.getNextString();
        }

    }
   // output.push_back("ROOT");
}

int main()
{
    input.push_back("/usr/lib/libc");
    input.push_back("/usr/bin/find");
    input.push_back("/home/schveiguy/bashrc");
    input.push_back("/usr/bin/bash");
    input.push_back("/usr/local/bin/ssh");

    DirectoryTree();
    
    return 0;
}