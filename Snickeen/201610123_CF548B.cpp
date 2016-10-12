/*
By Snickeen
*/
#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans,dp[555],f[555][555];
int main()
{
	int i,j,k,l;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++){
		k=0;
		for(j=1;j<=m;j++){
			scanf("%d",&f[i][j]);
			if(f[i][j]==1)k++;
			else if(f[i][j]==0&&f[i][j-1]==1){
				dp[i]=max(dp[i],k);
				k=0;
			}
		}
		dp[i]=max(dp[i],k);
	}
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]^=1;
		k=0;dp[x]=0;
		for(j=1;j<=m;j++){
			if(f[x][j]==1)k++;
			else if(f[x][j]==0&&f[x][j-1]==1){
				dp[x]=max(dp[x],k);
				k=0;
			}
		}
		dp[x]=max(dp[x],k);
		ans=0;
		for(i=1;i<=n;i++)ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
