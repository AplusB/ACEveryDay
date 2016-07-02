#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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
const int MAX_N = 505;

int i, j;

bool dp[MAX_N][MAX_N][MAX_N];//dp[i][j][y] 从前i个硬币选出总和j再选子集和y，是否能够凑出
int n, k;
int a[MAX_N];
int ans[MAX_N];

int main()
{
	FREAD("687c.txt");
	RINT(n); RINT(k);
	REPE(n) RINT(a[i]);
	dp[0][0][0] = 1;
	REPE(n){
		for(j=0; j<=k; j++){
			for(int y = 0; y <= j; y++){
				dp[i][j][y] = dp[i-1][j][y];
				if(j >= a[i]){
					dp[i][j][y] |= dp[i-1][j-a[i]][y];
					if(y >= a[i])
						dp[i][j][y] |= dp[i-1][j-a[i]][y-a[i]];
				}
			}
		}
	}
	int cnt = 0;
	for(i=0; i<=k; i++){
		if(dp[n][k][i]) ans[cnt++] = i;
	}
	PINT(cnt);
	pn();
	REP(cnt){
		PINT(ans[i]);
		printf(" ");
	}
	pn();
	return 0;
}
