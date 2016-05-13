//lightoj 1057 - Collecting Gold
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[(1<<16)+10][16];
int x[20],y[20];
char mp[25][25];
int dis(int i,int j){
    return max(abs(x[i]-x[j]),abs(y[i]-y[j]));
}
int main(){
    int cas=1,t,n,m;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        memset(dp,inf,sizeof dp);
        int xx,yy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]=='g'){
                    x[cnt]=i;
                    y[cnt]=j;
                    cnt++;
                }
                else if(mp[i][j]=='x'){
                    xx=i;
                    yy=j;
                }
            }
        }
        x[cnt]=xx;
        y[cnt]=yy;
        cnt++;
        dp[0][cnt-1]=0;
        for(int s=0;s < (1<<cnt)-1;s++){
            for(int i=0;i<cnt;i++){
                for(int j=0;j<cnt;j++){
                    if(s&(1<<j)) continue;
                    dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],dp[s][i]+dis(i,j));
                }
            }
        }
        printf("Case %d: %d\n",cas++,dp[(1<<cnt)-1][cnt-1]);
    }
    return 0;
}
