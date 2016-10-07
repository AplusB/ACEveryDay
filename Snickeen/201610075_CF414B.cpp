#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 2e3+10;
LL t,n,m,ans,MOD=1e9+7;
LL dp[MAXN][MAXN];

int main()
{
	LL i,j,k,l,ca=0;
	cin>>n>>t;
	dp[0][1]=1;
	for(i=1;i<=t;i++){
		for(j=1;j<=n;j++){
			for(k=j;k<=n;k+=j){
				dp[i][k]+=dp[i-1][j];
				dp[i][k]%=MOD;
			}
		}
	}
	for(i=1;i<=n;i++){
		ans+=dp[t][i];
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
