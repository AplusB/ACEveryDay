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
const int MAX_N = 105;
int i, j, k;

char s[MAX_N];
int dp[MAX_N][MAX_N];//区间[i, j]内的最长括号匹配子序列

bool match(char l, char r){
	if(l == '(' && r == ')') return true;
	if(l == '[' && r == ']') return true;
	return false;
}

int main()
{
	FREAD("2955.txt");
	while(~scanf("%s", s)){
		if(s[0] == 'e') break;
		CLEAR(dp, 0);
		int n=0;
		while(s[n++] != '\0') ;
		for(i=0; i<n-1; i++){
			if(match(s[i], s[i+1]))
				dp[i][i+1] = 2;
			//PINT(dp[i][i+1]);
		}
		//n < 3时，ans最大为2 = dp[0][2]
		//为确保计算i, j时,i+1和j-1已被计算出来，所以这个移动方向
		for(i=n-3; i>=0; i--){//左端点
			for(j=i+2; j<n; j++){//右端点
				if(match(s[i], s[j]))//端点匹配，纳入
					dp[i][j] = dp[i+1][j-1] + 2;//保证i+1 <= j-1，i和j不交错
				//寻找区间内可合并的
				for(k=i+1; k<j; k++)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
				
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
