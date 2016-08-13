// Paste me into the FileEdit configuration dialog
// Paste me into the FileEdit configuration dialog

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn = 60;
const int INF = 0x3f3f3f3f;

int edge[maxn], dp[1<<21];
LL link[maxn];
class Gperm {
public:
    LL lowbit(LL x){
        return x & (-x);
    }
    int rev(LL x){
        int ret = 0;
        while(x){
            ret++,x>>=1;
        }
        return ret-1;
    }
    int dfs(int S){
        if(dp[S] != -1) return dp[S];
        if(S == 0) return dp[S] = 0;
        dp[S] = INF;
        LL v = 0;
        int val = 0; 
        for(int i=0;i<25;i++){
            if((S>>i)&1){
                v |= link[i];
                val++;
            }
        }
        for(int i=0;i<55;i++){
            if(!((v>>i)&1)) continue;
            dp[S] = min(dp[S],dfs(S & (~edge[i]))+val);
        }
        return dp[S];
    }
    int countfee( vector <int> x, vector <int> y ) {
        memset(link,0,sizeof(link));
        memset(edge,0,sizeof(edge));
        for(int i=0;i<x.size();i++){
            edge[x[i]] |= 1<<i;
            edge[y[i]] |= 1<<i;
            link[i] = (1ll<<x[i]) | (1ll<<y[i]);
        }
        memset(dp,-1,sizeof(dp));
        return dfs((1<<x.size())-1) ;
    }
};

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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int x[]                   = {0};
			int y[]                   = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {0,1};
			int y[]                   = {1,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {4,7,7};
			int y[]                   = {7,4,4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {0,0,1};
			int y[]                   = {1,2,2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {7,8,9};
			int y[]                   = {4,5,6};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};
			int y[]                   = {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};
			int expected__            = 53;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Gperm().countfee( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
