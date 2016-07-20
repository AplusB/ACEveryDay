// Paste me into the FileEdit configuration dialog
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
char m[5] = "NESW";


class BearNSWE {
public:
    int getid(char c){
        for(int i=0;i<4;i++){
            if(c == m[i])
                return i;
        }
        return -1;
    }
   double totalDistance( vector <int> a, string dir ) {
        int x,y;
        x = y = 0;
        double all = 0;
        for(int i=0;i<a.size();i++){
            int d = getid(dir[i]);
            all += a[i];
            x += a[i] * dx[d];
            y += a[i] * dy[d];
        }
        all += sqrt(1.0 * x * x + y * y);
        return all;
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received );
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int a[]                   = {1,3,3};
			string dir                = "NES";
			double expected__         = 10.60555127546399;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {10,10,10,10};
			string dir                = "NWSE";
			double expected__         = 40.0;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {10,10,10,15,8,20,5};
			string dir                = "NEWEWWE";
			double expected__         = 90.8062484748657;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {42};
			string dir                = "E";
			double expected__         = 84.0;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {10,40,40};
			string dir                = "NSE";
			double expected__         = 140.0;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			string dir                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a[]                   = ;
			string dir                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			string dir                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BearNSWE().totalDistance( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), dir );
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
