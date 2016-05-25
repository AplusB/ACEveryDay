#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 112345;
int cook[maxn][13],dp[maxn][13];

int m(int i,int j){
    return max(dp[i][j],max(dp[i][j-1],dp[i][j+1]));
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        memset(cook,0,sizeof(cook));
        memset(dp,0,sizeof(dp));
        int x,t;
        int bound = 0;
        while(n--){
            scanf("%d %d",&x,&t);
            bound = max(bound,t);
            cook[t][x+1]++;
        }
        for(int j=0;j<13;j++){
            dp[0][j] = -INF;
        }
        dp[0][6] = 0;
        for(int i=1;i<=bound;i++){
            for(int j=1;j<=11;j++){
                dp[i][j] = cook[i][j]+m(i-1,j);
            }
        }
        int ans = 0;
        for(int i=1;i<=11;i++){
            ans = max(ans,dp[bound][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
