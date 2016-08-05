#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD() freopen("in.txt", "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
typedef __int64 ll;
#define sz(a) ll((a).size())
using namespace std;
const int MAX_N = 100005;

int n, k;
int c[MAX_N];
ll sum = 0;
ll ans = 0;

int main()
{
	FREAD();
	RINT(n); RINT(k);
	REP(n){
		RINT(c[i]);//下标从0开始
		sum += c[i];
	}
	REP(n-1){
		ans += c[i] * c[i+1];
	}
	ans += c[n-1]*c[0];

	int cap = 0;
	ll overlap = 0;
	while(k--){
		RINT(cap);
		cap--;
		overlap += c[cap];
		ll x = sum - overlap;//所有未加过的指向cap的c值的和

		//减去相邻的
		if(cap == 0) x -= c[1]+c[n-1];
		else if(cap == n-1) x -= c[n-2] + c[0];
		else x -= c[cap-1] + c[cap+1];

		ans += x * c[cap];
		c[cap] = 0;//之后不被再加
	}
	cout << ans << endl;
	return 0;
}
