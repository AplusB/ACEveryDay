// BEGIN CUT HERE

// END CUT HERE
#line 5 "MicrowaveSelling.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

class MicrowaveSelling
{
        public:
        int mostAttractivePrice(int minPrice, int maxPrice)
        {
        	int ret = 0;
        	int mx = 0;
        	for(int i = minPrice; i <= maxPrice; i++) {
        		int tmp = i;
        		int cnt = 0;
        		while(tmp % 10 == 9) {
        			cnt++;
        			tmp /= 10;
        		}
        		if(cnt >= mx) {
        			ret = i;
        			mx = cnt;
        		}
        	}
        	return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 460; int Arg1 = 680; int Arg2 = 599; verify_case(0, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1000; int Arg2 = 999; verify_case(1, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1255; int Arg1 = 2999; int Arg2 = 2999; verify_case(2, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 25; int Arg2 = 25; verify_case(3, Arg2, mostAttractivePrice(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MicrowaveSelling ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
