#include<bits/stdc++.h>
using namespace std;
const int inf=0xfffffff;
int dp[100][100];
int s[100],u[100];
int a,b,c;

int main() {
	int k,n,ans;
	while(~scanf("%d",&n)) {
		if(n==0) break;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0; i<n; i++) {
			scanf("%d",&s[i]);
			u[i]=s[i];
		}
		sort(u,u+n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				dp[i][j]=inf;
			}
		for(int i=0; i<n; i++) {
			if(s[0]<=u[i])
			{	
				dp[0][i]=u[i]*(a+b);
			}
		}
		for(int i=1; i<n; i++) {
			for(int j=0; j<n; j++) {
				for(int k=0;k<n;k++)
				{
					if(dp[i-1][k]==inf) continue;
					if(u[j]>=u[k])
					{
						dp[i][j]=min(dp[i][j],dp[i-1][k]+b*u[j]+(u[j]-u[k])*a);
					}
					else
					{
						dp[i][j]=min(dp[i][j],dp[i-1][k]+b*u[j]+(u[k]-u[j])*c);
					}
				 } 
				 for(int j=0;j<n;j++)
				 {
				 	if(s[i]>u[j])
				 		dp[i][j]=inf;
				 }
				/*if(dp[i-1][j]==inf) continue;
				if(u[j]<=s[i]) {
					dp[i][k]=min(dp[i][k],dp[i-1][j]+s[i]*b+a*(s[i]-u[j]));
				} else {
					dp[i][k]=min(dp[i][k],dp[i-1][j]+s[i]*b+c*(u[j]-s[i]));
					for(int p=0;p<n;p++)
					{
						
					}
					dp[i][j]=min(dp[i][j],dp[i-1][j]+u[j]*b);
				}*/
			}
		}
		/*for(int  i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/
		ans=inf;
		for(int i=0; i<n; i++) {
				if(u[i]>=s[n-1])
					ans=min(ans,dp[n-1][i]);
			}
		printf("%d\n",ans);
	}
	return 0;
}
