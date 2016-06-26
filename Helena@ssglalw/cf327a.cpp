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
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 105;
int i;
int n;
int a[MAX_N];
int b[MAX_N];
int dp[MAX_N];
int ans;

int main()
{
	FREAD("327a.txt");
	RINT(n);
	REP(n){
		RINT(a[i]);
		b[i] = (a[i]==1) ? -1 : 1;
		ans += a[i];
	}
	dp[0] = b[0];
	int maxx = dp[0];
	for(int i=1; i<n; i++){
		dp[i] = max(b[i], dp[i-1] + b[i]);//最大子串和
		maxx = max(maxx, dp[i]);
	}
	printf("%d\n", ans + maxx);
	return 0;
}
