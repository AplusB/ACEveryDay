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

const int maxn = 55;
const int mod = 1000000007;

LL dp[maxn][maxn];
LL c[maxn][maxn];

void init(){
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for(int i=1;i<=50;i++){
        for(int j=0;j<=i;j++){
            c[i][j] = (c[i-1][j] + (j>0?c[i-1][j-1]:0) ) % mod;
        }
    }
}

int main(){
    int n,m;
    init();
    while(~scanf("%d %d",&n,&m)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            dp[1][i] = c[m][i];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=j;k++){
                    for(int t=0;t<=k;t++){
                        (dp[i][j] += ( dp[i-1][j-t] * c[m-j+t][t] ) % mod  * c[j-t][k-t] ) %= mod;
                    }
                }
            }
        }
        printf("%I64d\n",dp[n][m]);
    }
    return 0;
}
