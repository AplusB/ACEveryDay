#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

bool ok(char c) {
	if(c>='a'&&c<='z'||c>='A'&&c<='Z') return true;
	return false;
}
int main() {
	// FRead();
	string s;
	while(getline(cin, s)!=NULL) {
		int len=s.size();
		string res=""; 
		Rep(i, len) {
			if(s[i]>='A'&&s[i]<='Z') {
				s[i]+=32;
			}
		}
		int start=0;
		bool isCap=true;
		while(true) {
			while(start<len) {
				if(s[start]==','||s[start]=='.') {
					res+=s[start];
					if(s[start]=='.') {
						isCap=true;
					}
				}
				else if(ok(s[start])) break;
				start++;
			}
			if(start>=len) break;
			string num="";
			for(int i=start;i<len;i++) {
				if(s[i]==' ') {
					num=s.substr(start,i-start);
					start=i+1;
					break;
				}
				else if(s[i]==','||s[i]=='.') {
					num=s.substr(start,i-start+1);
					start=i+1;
					break;
				}
			}
			if(num.size()==0) {
				break;
			}
			else {
				if(isCap) {
					num[0]-=32;
					isCap=false;
				}
				if(res.size()==0) {
					res+=num;
				}
				else res+=" "+num;
				if(num[num.size()-1]=='.') {
					isCap=true;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
