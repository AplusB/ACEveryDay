#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define LL long long

const int maxn = 51;
const int mod = 1000000007;

int dp[maxn][maxn][maxn][3][maxn];
int v[3];

int dfs(int a,int b,int c,int u,int use){
    int & ndp = dp[a][b][c][u][use];
    if(ndp != -1) return ndp;
    ndp = 0;
    if(use == 1){
        int ta,tb,tc;
        ta = a,tb = b,tc = c;
        if(u==0) ta--;
        if(u==1) tb--;
        if(u==2) tc--;
        if(ta <0 || tb < 0 || tc < 0){
            return ndp = 0;
        }
        for(int i=0;i<3;i++){
            if(i == u) continue;
            for(int j=1;j<=v[i];j++){
                if(i == 0 && a) (ndp += dfs(ta,tb,tc,i,j) ) %= mod;
                if(i == 1 && b) (ndp += dfs(ta,tb,tc,i,j) ) %= mod;
                if(i == 2 && c) (ndp += dfs(ta,tb,tc,i,j) ) %= mod;
            }
        }
    }
    else{
        if(u == 0 && a) ndp = dfs(a-1,b,c,u,use-1);
        if(u == 1 && b) ndp = dfs(a,b-1,c,u,use-1);
        if(u == 2 && c) ndp = dfs(a,b,c-1,u,use-1);
    }
    return ndp;
}

int main(){
    int T;
    scanf("%d",&T);
    int a,b,c;
    while(T-- && ~scanf("%d %d %d",&a,&b,&c)){
        for(int i=0;i<3;i++){
            scanf("%d",&v[i]);
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0][0][0][1] = 1;
        dp[0][1][0][1][1] = 1;
        dp[0][0][1][2][1] = 1;
        LL ans = 0;
        for(int i=0;i<3;i++){
            for(int j=1;j<=v[i];j++){
                (ans += dfs(a,b,c,i,j)) %= mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
