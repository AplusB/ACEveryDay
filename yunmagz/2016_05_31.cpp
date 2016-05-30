//TC SRM691 div2 300

#line 6 "Plusonegame.cpp"
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
string aa[10]={"0","1","2","3","4","5","6","7","8","9"};
class Plusonegame
{
        public:
        string getorder(string s)
        {
            string ans="";
            int cnt[15];
            memset(cnt,0,sizeof cnt);
            int n=s.size();
            int m=0;
            for(int i=0;i<n;i++){
                if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
                else m++;
            }
            for(int i=0,j=0,k=0;i<10&&j<n;i++){
                if(cnt[i]){
                    while(k<i&&m){
                        ans.append("+");
                        k++;
                        m--;
                    }
                    while(cnt[i]--){
                        ans+=aa[i];
                    }
                }
            }
            while(m--){
                ans.append("+");
            }
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1++"; string Arg1 = "+1+"; verify_case(0, Arg1, getorder(Arg0)); }
	void test_case_1() { string Arg0 = "549"; string Arg1 = "459"; verify_case(1, Arg1, getorder(Arg0)); }
	void test_case_2() { string Arg0 = "++++++"; string Arg1 = "++++++"; verify_case(2, Arg1, getorder(Arg0)); }
	void test_case_3() { string Arg0 = "+++++2+"; string Arg1 = "++2++++"; verify_case(3, Arg1, getorder(Arg0)); }
	void test_case_4() { string Arg0 = "++++4++++200++2++1+6++++++"; string Arg1 = "00+1+22++4++6+++++++++++++"; verify_case(4, Arg1, getorder(Arg0)); }
	void test_case_5() { string Arg0 = "++11199999"; string Arg1 = "+111+99999"; verify_case(5, Arg1, getorder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Plusonegame ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
