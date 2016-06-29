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
const int MAX_N = 4005;
int i, j;
int n, a, b, c;
int dp[MAX_N];//dp[i]=总长度为i时能切成的最大块数

int main()
{
	CLEAR(dp, 0);
	RINT(n);
	RINT(a); RINT(b); RINT(c);
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	for(i=0; i<a; i++)
		dp[i] = 0;
	for(i=a; i<b; i++){
		if(i % a == 0) dp[i] = i/a;
		else dp[i] = 0;
	}
	for(i=b; i<=c; i++){
		if(i % a == 0){
			dp[i] = i/a;
			continue;
		}
		else{
			bool flag = 0;
			for(j=0; j*a < i; j++){
				if((i-j*a) % b == 0){
					flag = 1;
					dp[i] = max(dp[i], j + (i-j*a)/b);
				}
			}
			if(flag) continue;
		}
		if(i % b == 0) dp[i] = max(dp[i], i/b);
		else if(i == c) dp[i] = max(dp[i], 1);
		else dp[i] = 0;
	}
	//printf("dp[%d] = %d\n", b, dp[b]);
	for(i=c; i<=n; i++){
		if(dp[i-a] > 0) 
			dp[i] = max(dp[i], dp[i-a] + 1);
		if(dp[i-b] > 0)
			dp[i] = max(dp[i], dp[i-b] + 1);
		if(dp[i-c] > 0)
			dp[i] = max(dp[i], dp[i-c] + 1);
	}
	// REP(n) 
	// 	printf("dp[%d]  = %d\n", i, dp[i]);
	PINT(dp[n]);
	return 0;
}
