//http://community.topcoder.com/stat?c=problem_solution&cr=8355516&rd=14569&pm=11504
//Dynamic ProgramminDynamic Programmin

#include <algorithm>
#include <string>
#include <map>
using namespace std;
 
#define Size(x) (int(x.size()))
 
 map<string, string> memo;
 
string worst(string word);
 
string best(string word) {
  if(memo.count(word)) return memo[word];
  if(word == "") return "";
  string ret = "";
  for(int k=0; k<Size(word); k++) 
      ret = max(ret, word.substr(0, k) + worst(word.substr(k+1)));
  return memo[word] = ret;
  }
 
string worst(string word) {
  if(word == "") return "";
  string ret = "~";
  for(int k=0; k<Size(word); k++) 
      ret = min(ret, word.substr(0, k) + best(word.substr(k+1)));
  return ret;
  }
 
class SistersErasingLetters {
  public:
  string whoWins(string word) {
    // !FDI
    return best(word) > word ? "Camomile" : "Romashka";
    }
  };

int main()
{
    SistersErasingLetters el;
    string ret = el.whoWins("abcd");

    return 0;
}
 
 