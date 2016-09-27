//SRM 699 div2
//UpDownHiking
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}



class UpDownHiking
{
public:
    int maxHeight(int N, int A, int B)
    {
        int ans=0;
        for(int i=1;i<N;i++)
            ans=max(ans,min(A*i,B*(N-i)));

        return ans;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10; int Arg3 = 10; verify_case(0, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 40; int Arg2 = 30; int Arg3 = 80; verify_case(1, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 50; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 42; int Arg2 = 42; int Arg3 = 42; verify_case(3, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 7; int Arg2 = 9; int Arg3 = 77; verify_case(4, Arg3, maxHeight(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
 UpDownHiking ___test;
 ___test.run_test(-1);
 return 0;
}
// END CUT HERE

//LastDigit
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

LL check(LL x){
    LL ans=0;
    while(x){
        ans+=x;
        x/=10;
    }
    return ans;
}

class LastDigit
{
public:
    long long findX(long long S)
    {
        LL l=0,r=S;
        while(l<=r){
            LL m=(l+r)>>1;
            LL a=check(m);
            if(a==S) return m;
            else if(a<S) l=m+1;
            else r=m-1;
        }

        return -1;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 564LL; long long Arg1 = 509LL; verify_case(0, Arg1, findX(Arg0)); }
	void test_case_1() { long long Arg0 = 565LL; long long Arg1 = -1LL; verify_case(1, Arg1, findX(Arg0)); }
	void test_case_2() { long long Arg0 = 3000LL; long long Arg1 = 2701LL; verify_case(2, Arg1, findX(Arg0)); }
	void test_case_3() { long long Arg0 = 137174210616796LL; long long Arg1 = 123456789555123LL; verify_case(3, Arg1, findX(Arg0)); }
	void test_case_4() { long long Arg0 = 837592744927492746LL; long long Arg1 = -1LL; verify_case(4, Arg1, findX(Arg0)); }
	void test_case_5() { long long Arg0 = 999999999999999999LL; long long Arg1 = 900000000000000000LL; verify_case(5, Arg1, findX(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
 LastDigit ___test;
 ___test.run_test(-1);
 return 0;
}
// END CUT HERE


//FromToDivisibleDiv2



#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int v[550];
class FromToDivisibleDiv2
{
public:
    int shortest(int N, int S, int T, vector <int> a, vector <int> b)
    {
        map<int,int>p;
        queue<int>q;
        p.clear();
        while(!q.empty()) q.pop();
        for(int i=0;i<SZ(a);i++){
            if(S%a[i]==0&& !p[b[i]]){
                q.push(b[i]);
                p[b[i]]=1;
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(T%t==0) return p[t];
            for(int i=0;i<SZ(a);i++){
                if(1LL*t*a[i]/__gcd(t,a[i])>N) continue;
                if(!p[b[i]]){
                    p[b[i]]=p[t]+1;
                    q.push(b[i]);
                }
            }
        }
        return -1;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 9; int Arg2 = 6; int Arr3[] = {3,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(0, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 12345; int Arg1 = 18; int Arg2 = 12; int Arr3[] = {1,42,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,17,3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(1, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 60; int Arg1 = 30; int Arg2 = 8; int Arr3[] = {16,15,12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2,20,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(2, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 77; int Arg1 = 10; int Arg2 = 62; int Arr3[] = {2,5,7,4,17,26}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {25,7,11,13,31,34}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 4; verify_case(3, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 90; int Arg2 = 40; int Arr3[] = {20,30,100,99,100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10,30,100,100,99}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(4, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 700; int Arg2 = 42345; int Arr3[] = {3500,12000,42345,20000,35,19}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {15,1,700,20000,40000,17}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(5, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(6, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
 FromToDivisibleDiv2 ___test;
 ___test.run_test(-1);
 return 0;
}
// END CUT HERE
