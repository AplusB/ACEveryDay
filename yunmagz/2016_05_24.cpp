//lightoj 1071 - Baker Vai
#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[205][105][105],mp[105][105];
int dfs(int s,int x,int xx){
    if(dp[s][x][xx]!=-1)
        return dp[s][x][xx];
    int y=s+2-x;
    int yy=s+2-xx;
    int ans=0;
    if(y<m&&yy<m&&x!=xx) ans=max(ans,dfs(s+1,x,xx));
    if(y<m&&xx<n&&xx+1!=x) ans=max(ans,dfs(s+1,x,xx+1));
    if(x<n&&yy<m&&x+1!=xx) ans=max(ans,dfs(s+1,x+1,xx));
    if(x<n&&xx<n&&x!=xx) ans=max(ans,dfs(s+1,x+1,xx+1));
    ans+=mp[x][y]+mp[xx][yy];
    return dp[s][x][xx]=ans;
}
int main(){
    int t,cas=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",cas++,dfs(0,1,1)-mp[1][1]+mp[n][m]);
    }
    return 0;
}
