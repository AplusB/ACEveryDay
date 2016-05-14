// Paste me into the FileEdit configuration dialog
// Paste me into the FileEdit configuration dialog

#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
typedef long long LL;
using namespace std;


class LCMGCD 
{
public:
   string isPossible( vector <int> x, int t ) ;
};
int s[3][3];
int Get(int a, int b)
{
    if(a < b) return 0;
    if(a == b) return 1;
    return 2;
}
bool dp[10][1 << 9];
string LCMGCD:: isPossible( vector <int> x, int t )
{
    int A = 0; while(t % 2 == 0) {t/=2;A++;}
    int B = 0; while(t % 3 == 0) {t/=3;B++;}
    memset(s, 0, sizeof(s));
    for(int num : x) {
        int a = 0; while(num % 2 == 0) {num/=2;a++;}
        int b = 0; while(num % 3 == 0) {num/=3;b++;}
        s[Get(a, A)][Get(b, B)]++;
    }
    if(s[1][1] >= 2) {
        return "Possible";
    }
    memset(dp, false, sizeof(dp));
    vector<pair<int, int> > pts;
    int mp[3][3];
    int p[9][2];
    int tot = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            p[tot][0] = i;
            p[tot][1] = j;
            mp[i][j] = tot++;
            if(s[i][j]) {
                pts.push_back(make_pair(i, j));
            }
        }
    }
    int n = (int)pts.size();
    int mask = 0;
    for(auto num : pts){
        mask |= 1 << mp[num.first][num.second];
    }
    dp[n][mask] = true;
    for(int i = n; i >= 2; i--) {
        for(int mask = 0; mask < 1 << 9; mask++) if(dp[i][mask]) {
            for(int j = 0; j < 9; j++) {
                for(int k = j + 1; k < 9; k++)if((mask >> j & 1) && (mask >> k & 1)) {
                    int x = p[j][0], y = p[j][1];
                    int tx = p[k][0], ty = p[k][1];
                    int nmask = mask ^ (1 << j) ^ (1 << k);
                    int nx = min(x, tx), ny = min(y, ty);
                    dp[i - 1][nmask | (1 << mp[nx][ny])] = true;

                    nx = max(x, tx), ny = max(y, ty);
                    dp[i - 1][nmask | (1 << mp[nx][ny])] = true;
                }
            }
        }
    }
    if(dp[1][1 << mp[1][1]] == true) return "Possible";
    return "Impossible";
} 
// BEGIN CUT HERE
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if ( casenum != -1 ) {
            if ( run_test_case( casenum ) == -1 && !quiet )
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            return;
        }

        int correct = 0, total = 0;
        for ( int i=0;; ++i ) {
            int x = run_test_case(i);
            if ( x == -1 ) {
                if ( i >= 100 ) break;
                continue;
            }
            correct += x;
            ++total;
        }

        if ( total == 0 ) {
            cerr << "No test cases run." << endl;
        } else if ( correct < total ) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }

    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if ( expected == received ) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }

        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;

        if (verdict == "FAILED") {
            cerr << "    Expected: \"" << expected << "\"" << endl; 
            cerr << "    Received: \"" << received << "\"" << endl; 
        }

        return verdict == "PASSED";
    }

    int run_test_case( int casenum ) {
        switch( casenum ) {
            case 0: {
                        int x[]                   = {2,3};
                        int t                     = 6;
                        string expected__         = "Possible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 1: {
                        int x[]                   = {4,9};
                        int t                     = 6;
                        string expected__         = "Impossible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 2: {
                        int x[]                   = {6,12,24,18,36,72,54,108,216};
                        int t                     = 36;
                        string expected__         = "Possible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 3: {
                        int x[]                   = {6,27,81,729};
                        int t                     = 6;
                        string expected__         = "Impossible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 4: {
                        int x[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
                        int t                     = 1;
                        string expected__         = "Possible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 5: {
                        int x[]                   = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
                        int t                     = 72;
                        string expected__         = "Possible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 6: {
                        int x[]                   = {100663296, 544195584, 229582512, 59049};
                        int t                     = 60466176;
                        string expected__         = "Possible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }
            case 7: {
                        int x[]                   = {2,4,8,16,32,64};
                        int t                     = 256;
                        string expected__         = "Impossible";

                        clock_t start__           = clock();
                        string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                        return verify_case( casenum, expected__, received__, clock()-start__ );
                    }

                    // custom cases

                    /*      case 8: {
                            int x[]                   = ;
                            int t                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                            return verify_case( casenum, expected__, received__, clock()-start__ );
                            }*/
                    /*      case 9: {
                            int x[]                   = ;
                            int t                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                            return verify_case( casenum, expected__, received__, clock()-start__ );
                            }*/
                    /*      case 10: {
                            int x[]                   = ;
                            int t                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = LCMGCD().isPossible( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), t );
                            return verify_case( casenum, expected__, received__, clock()-start__ );
                            }*/
            default:
                    return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// END CUT HERE
