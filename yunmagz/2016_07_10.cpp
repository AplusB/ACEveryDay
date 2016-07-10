//TC SRM694 Div2
//250
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
class MakingPairs
{
        public:
        int get(vector <int> card)
        {
            int n=card.size();
            int ans=0;
			for(int i=0;i<n;i++){
				ans+=card[i]/2;
			} 
			return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, get(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, get(Arg0)); }
	void test_case_2() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, get(Arg0)); }
	void test_case_3() { int Arr0[] = {43,23,10,39,39,22,22,0,3,4,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 102; verify_case(3, Arg1, get(Arg0)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, get(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        MakingPairs ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

//500
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
map<string,int>mp;
class DistinguishableSetDiv2
{
        public:
        int count(vector <string> answer)
        {
            int n=answer.size();
            int m=answer[0].size();
            int cnt=0;
            for(int i=1;i<(1<<m);i++){
            	mp.clear();
            	int flag=1;
            	for(int j=0;j<n&&flag;j++){
            		string s="";
            		for(int k=0;k<m;k++){
            			if(i&(1<<k)){
            				s.push_back(answer[j][k]);
						}
					}
					if(mp[s]) flag=0;
					else mp[s]++;
				}
				if(flag) cnt++;
			}
			return cnt;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA","AB","CC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"XYZ","XYZ","XYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAAA","BACA","CDCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1017; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"XYZ","XAB","YAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        DistinguishableSetDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE


//1000
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
const int mod=1e9+7;
int dp[55][5005];
class UpDownNess
{
        public:
        int count(int N, int K)
        {
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            for(int i=0;i<N;i++){
            	for(int j=0;j<=K;j++){
            		for(int k=0;k<=i;k++){
            			if(j+k*(i-k)>K||dp[i][j]==0) continue;
            			dp[i+1][j+k*(i-k)]+=dp[i][j];
            			dp[i+1][j+k*(i-k)]%=mod;
					}
				}
			}
			return dp[N][K];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 19; int Arg2 = 24969216; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 2000; int Arg2 = 116596757; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        UpDownNess ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
