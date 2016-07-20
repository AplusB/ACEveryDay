// Paste me into the FileEdit configuration dialog
#include<bits/stdc++.h>
#define LL long long
using namespace std;


class BearPasswordAny {
public:
    int getid(vector<int> x){
        for(int i=x.size()-1;i>=0;i--){
            if(x[i]) return i;
        }
        return -1;
    }
    string findPassword( vector <int> x ) {
        bool c = true;
        string ret = "";
        int pos = getid(x);
        while(pos != -1){
            ret = string(pos+1,c?'a':'b') + ret;
            c ^= 1;
            int cnt = 1;
            for(int i=pos;i>=0;i--){
                x[i] -= cnt;
                if(x[i] < 0) return "";
                cnt++;
            }
            pos = getid(x);
        }
        return ret.size() == x.size() ? ret : "";
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
			int x[]                   = {5,0,0,0,0};
			string expected__         = "ababa";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {4,2,1,0};
			string expected__         = "baaa";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {3,1,1};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {4,3,2,1};
			string expected__         = "aaaa";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {0};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {4,0,3,2};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int x[]                   = {6,3,1,0,0,0};
			string expected__         = "abbaaa";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int x[]                   = {10,5,2,1,0,0,0,0,0,0};
			string expected__         = "bbbbaababb";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 8: {
			int x[]                   = {5,4,2,1,0};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 9: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 11: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordAny().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
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
