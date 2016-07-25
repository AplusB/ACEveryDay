#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long 
const int bit= 12;
const int maxn = 1<<bit;

LL dp[bit][bit][maxn];

inline bool get(int x,int pos){
    return (x>>pos)&1;
}
inline int sub(int x,int pos){
    return x & (~(1<<pos));
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        memset(dp,0,sizeof(dp));
        int bnd = 1<<m;
        dp[0][m-1][bnd-1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                LL *pdp = !j ? dp[i-1][m-1]:dp[i][j-1];
                for(int mask=0;mask<bnd;mask++){
                    if(get(mask,j)){
                        dp[i][j][mask] = pdp[sub(mask,j)];
                        if(j && get(mask,j-1)){
                            dp[i][j][mask] += pdp[sub(mask,j-1)];
                        }
                    }
                    else{
                        dp[i][j][mask] = pdp[mask | (1<<j)];
                    }
                }
            }
        }
        printf("%lld\n",dp[n][m-1][bnd-1]);
    }
    return 0;
}

