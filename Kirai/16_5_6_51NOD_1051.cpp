#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
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

typedef long long ll;
const int maxn = 501;
const ll inf = 0x7f7f7f7f;
ll n, m;
ll G[maxn][maxn];
ll dp[maxn];

ll lss() {
	ll ans = -inf, tmp = -inf;
	for(int i = 0; i < m; i++) {
		if(tmp > 0) tmp += dp[i];
		else tmp = dp[i];
		ans = max(ans, tmp);
	}
	return ans;
}

inline bool scan_d(ll &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

int main() {
	// freopen("in", "r", stdin);
	scan_d(m); scan_d(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scan_d(G[i][j]);
		}
	}
	ll ans = -inf;
	for(int i1 = 0; i1 < n; i1++) {
		memset(dp, 0, sizeof(dp));
		for(int i = i1; i < n; i++) {
			for(int j = 0; j < m; j++) {
				dp[j] += G[i][j];
			}
			ll tmp = lss();
			ans = max(tmp, ans);
		}
	}
	printf("%I64d\n", ans < 0 ? 0 : ans);
	return 0;
}
