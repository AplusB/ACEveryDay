//TC SRM 690 DIV2 1000
#line 5 "WolfHockeyTeamEasy.cpp"
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[1010][1010][2];
void ADD(int &a,int b){
    a=(a+b)%mod;
}
class WolfHockeyTeamEasy
{
public:
    int count(int N, int K)
    {
        dp[1][0][0]=(2 * N - 1 >= K);
        for(int i=0;i<=N;i++)
            for(int j=0;j <= N && j + i < 2 * N ;j++)
                for(int k=0;k<2;k++)
                    if(dp[i][j][k]){
                        int nxt=2*N-1-(i+j);
                        if(j<i) ADD(dp[i][j+1][k||(nxt>=K)],dp[i][j][k]);
                        if(i<N){
                            ADD(dp[i+1][j][k],dp[i][j][k]);
                            if(!k) ADD(dp[i+1][j][k||(nxt>=K)],dp[i][j][k]);
                        }
                    }
        int ans=dp[N][N][1];
        for(int i=2;i<=N;i++) ans=ans*1LL*i%mod;
        ans=ans*2%mod;
        return ans;
    }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 12; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 1104; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 120; int Arg2 = 803057135; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 234; int Arg1 = 467; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 810; int Arg1 = 893; int Arg2 = 281618909; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WolfHockeyTeamEasy ___test;
    ___test.run_test(-1);
}
// END CUT HERE
