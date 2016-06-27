#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[20][1 << 10][20][2];
int bit[20];

LL count(LL N, int K){
	int len = 0;
	while(N){
		bit[++len] = N % 10;
		N /= 10;
	}
	memset(dp, 0, sizeof dp);
	dp[len + 1][1][0][0] = 1;
	for(int i = len; i >= 1; i--){
		for(int mask = 0; mask < (1 << 10); mask++){
			for(int j = 0; j <= K; j++){
				for(int f = 0; f < 2 ; f++) if(dp[i + 1][mask][j][f]){
					for(int num = 0; num <= 9; num++) if(num <= bit[i] || f){
						int nxt = mask & ((1 << (num + 1)) - 1);
						int ff = f | (num < bit[i]);
						int val = 1 - ((nxt >> num) & 1);
						nxt |= (1 << num);
						dp[i][nxt][j + val][ff] += dp[i + 1][mask][j][f]; 
					}
				}
			}
		}
	}
	LL ans = 0;
	for(int mask = 1; mask < (1 << 10); mask++){
		ans += dp[1][mask][K][1];
	}
	return ans;
}

int main(){
	LL L, R;
	int K;
	scanf("%lld%lld%d", &L, &R, &K);
	printf("%lld\n", count(R + 1, K) - count(L, K));
	return 0;
}
