//Round A APAC Test 2017 
//D. Clash Royale
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
int dp[10][1010],k[10],l[10],a[15][15],c[15][15];
int main()
{
	freopen("D-small-practice.in","r",stdin);
	freopen("out.out","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--){
        int n,m;
        cin>>m>>n;
        for(int i=1;i<=n;i++){
            cin>>k[i]>>l[i];
            for(int j=1;j<=k[i];j++) cin>>a[i][j];
            for(int j=1;j<k[i];j++){
                cin>>c[i][j];
                c[i][j]+=c[i][j-1];
            }
        }
        memset(dp,-1,sizeof dp);
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int ii=0;ii<=m;ii++)
            	if(dp[i-1][ii]!=-1)
            		dp[i][m]=max(dp[i][m],dp[i-1][ii]+a[i][l[i]]);
            for(int j=l[i]-1;j<k[i];j++)
                for(int v=m;v>=0;v--)
                    if(c[i][j]-c[i][l[i]-1]+v<=m&&dp[i-1][v]!=-1)
                        dp[i][c[i][j]-c[i][l[i]-1]+v]=max(dp[i][c[i][j]-c[i][l[i]-1]+v],dp[i-1][v]+a[i][j+1]);
        }
        int ans=0;
        for(int ii=0;ii<=m;ii++) ans=max(ans,dp[n][ii]);
        printf("Case #%d: %d\n",cas++,ans);
    }
	return 0;
}
