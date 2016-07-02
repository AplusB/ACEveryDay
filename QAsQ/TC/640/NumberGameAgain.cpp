#include<bits/stdc++.h>
using namespace std;

#define LL long long

class NumberGameAgain {
public:
    int len(LL x){
        int ret = 0;
        while(x){
            ret++,x>>=1;
        }
        return ret;
    }
    bool isCover(LL small,LL big){
        if(small > big) return false;
        int k = len(big) - len(small);
        return (big>>k) == small;
    }
    bool isCover(LL x,vector<LL> table){
        for(auto v : table){
            if(v!=x && isCover(v,x))
                return true;
        }
        return false;
    }
    vector<LL> uni(vector<LL> s){
        sort(s.begin(),s.end());
        s.erase(unique(s.begin(),s.end()),s.end());
        vector<LL> ret;
        for(auto v : s){
            if(!isCover(v,s))
                ret.push_back(v);
        }
        return ret;
    }
    LL sizer(int n){
        return (1ll<<n)-1;
    }
    long long solve( int k, vector<long long> table ) {
        table = uni(table);
        LL ans = sizer(k);
        for(auto x : table){
            ans -= sizer(k - len(x) + 1);
        }
        return ans-1;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int k                     = 3;
			long table[]              = {2,4,6};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int k                     = 5;
			long table[]              = {2,3};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int k                     = 5;
			long table[]              = {};
			long long expected__      = 30LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int k                     = 40;
			long table[]              = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135};
			long long expected__      = 549755748288LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int k                     = 40;
			long table[]              = {};
			long long expected__      = 1099511627774LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int k                     = ;
			long table[]              = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int k                     = ;
			long table[]              = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int k                     = ;
			long table[]              = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = NumberGameAgain().solve( k, vector<long long>( table, table + ( sizeof table / sizeof table[0] ) ) );
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
