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
string ans;
vector<int> f[2];

int cmp(int a,int b){
    return a>b;
}

class Ropestring {
public:
   string makerope( string s ) {
    int i,j,k,l,num;
    l=s.size();num=0;k=0;
    for(i=0;i<2;i++)f[i].clear();ans.clear();
    for(i=0;i<l;i++){
        if(s[i]=='-')k++;
        else {
            if(k>0)f[k%2].push_back(k);
            k=0;
            num++;
        }
    }
	if(k)f[k%2].push_back(k);
    for(i=0;i<2;i++)
        sort(f[i].begin(),f[i].end(),cmp);
    for(int ii=0;ii<2;ii++)
	    for(i=0;i<f[ii].size();i++){
	        k=f[ii][i];
	        for(j=0;j<k;j++)ans+='-';
	        if(num>0){
	        	ans+='.';
				num-=1;
			}
	    }
    while(num>0){
        num-=1;
        ans+='.';
    }
//    cout<<ans<<endl;
    return ans;
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
			string s                  = "..-..-";
			string expected__         = "-.-...";

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string s                  = "-.-";
			string expected__         = "-.-";

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string s                  = "--..-.---..--";
			string expected__         = "--.--.---.-..";

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string s                  = "--..-.---..--..-----.--.";
			string expected__         = "--.--.--.-----.---.-....";

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string s                  = "...";
			string expected__         = "...";

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Ropestring().makerope( s );
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
