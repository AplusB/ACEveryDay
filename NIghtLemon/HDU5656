#include<bits/stdc++.h>
#define MAXN 1007
using namespace std;
typedef long long ll;

int n;
ll G[MAXN][MAXN];
ll a[MAXN]; 
ll dp[MAXN][MAXN];
ll MAXn,tmp,ans;

const ll MOD = 100000007;

ll gcd(ll x, ll y){
	if(y) return gcd(y,x%y);
	return x;
}

void init()
{
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			G[i][j] = gcd(i,j);
}

int main()
{
	init();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans = 0;
		memset(dp,0,sizeof(dp)); dp[0][0] = 1LL;
		MAXn = 0LL;
		for(int i=1; i<=n ;i++){
			cin>>a[i];
			if(a[i] > MAXn) MAXn = a[i];
		}
		for(int i=1; i<=n ;i++){
			for(int j=0; j<=MAXn ;j++){
				dp[i][j] = (dp[i][j] + dp[i-1][j] ) % MOD;
				tmp = G[j][a[i]];
				dp[i][tmp] = (dp[i][tmp] + dp[i-1][j]) %MOD;
			} 
		}
		for(int i=1; i<=MAXn ; i++)
			ans = (ans + dp[n][i] * i) %MOD; 
		cout<<ans<<endl;
	}
	return 0;
}
