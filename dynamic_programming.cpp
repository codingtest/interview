#include <vector>
#include <string>
using namespace std;


//div2 level3
#define MOD 1000000007 
class SRMSystemTestPhase
{
public:
    int countWays(vector<string> description);
};
int dp[51][4][4];

int SRMSystemTestPhase::countWays(vector<string> description)
{
        int N = description.size();
        for ( int p = 0 ; p <= 3; p++ )
            for ( int c = 0 ; c <= 3; c++ )
                dp[N][p][c] = 1;

        for (int i = N - 1; i >= 0; i-- ){
            for (int p = 0; p <= 3; p++ ){
                for (int c = 0; c<=3; c++ ){

                    int opt[3] = {0};
                    for ( ; opt[0] < 3; opt[0]++ ) {
                        for ( ; opt[1] < 3; opt[1]++ ){
                            for ( ; opt[2] < 3; opt[2]++ ){

                                //p_j is the number of passed solutions in the j-th outcome
                                // c_j is the number of challenged solutions in the j-th outcome.
                                int p_j = 0, c_j = 0;
                                bool valid = true;
                                for ( int k = 0; k < 3; k++ ){
                                    if ( description[i][k] == 'Y' ){
                                        if ( opt[k] == 0 ) p_j++;
                                        else if ( opt[k] == 1 ) c_j++;
                                    } else if ( opt[k] != 0 )
                                        valid = false;
                                }
                                if ( !valid ) continue;

                                if (p_j < p || (p_j == p && c_j >= c))
                                    dp[i][p][c] = (dp[i][p][c] + dp[i+1][p_j][c_j]) % MOD;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][3][3];
}

int main()
{
    /*KleofasTail kt;
    long long result = kt.countGoodSequences(3, 0, 1000000000000000000);
    printf("result is %ld\n", result);*/

   /* FavouriteDigits fd;
    long long result = fd.findNext(47, 2, 1, 0, 2);
    printf("result is %ld\n", result);*/

    SRMSystemTestPhase sc;
    /*int points[3] ={300, 600, 900};
    int skills[3] = {30, 65, 90};*/
    vector<string> input;
    input.push_back("YYY");
    int result = sc.countWays(input);
    printf("result is %d\n", result);


    return 0;
}