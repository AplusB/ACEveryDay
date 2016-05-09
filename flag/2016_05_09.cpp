#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int md = 2015;
const int maxn = 1e5 + 5;
int dp[7][maxn][2][7];

void add(int &a, int b){
	(a += b) %= md;
}

void init(){
	for(int x = 1; x < 7; x++){
		dp[x][x + 1][0][1] = 1;
		for(int i = x + 2; i < maxn; i++){
			for(int a = 0; a < 2; a++){
				for(int b = 0; b < 7; b++){
					if(b + 1 < 7)
					add(dp[x][i][a][b + 1], dp[x][i - 1][a][b]);
					add(dp[x][i][!a][1], dp[x][i - 1][a][b]);
				}
			}
		}
	}
}

int main(){
	init();
	int T, n;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		scanf("%d", &n);
		if(n == 1){
			printf("Case #%d: 2\n", cas);
			continue;
		}
		int ans = 0;
		for(int x = 0; x < 7; x++){
			for(int a = 0; a < 2; a++){
				for(int b = 1; b < 7; b++){
					if(x + b <= n){
						if(1 == a && x + b >= 7) continue;
						add(ans, dp[x][n][a][b] * 2 % md);
					}
				}
			}
		}
		if(n < 7) ans += 2;
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
