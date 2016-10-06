#include<bits/stdc++.h>
using namespace std;

const int v[10] = {6,2,5,5,4,5,6,3,7,6};
#define LL int 
const int maxn = 550;

LL m;
LL dp[2][maxn][8];

LL dfs(bool cry,int left,int bnd){
    if(left <= 0) return left == 0 && !cry && !bnd; 
    LL & ndp = dp[cry][left][bnd];
    if(~ndp) return ndp;
    ndp = 0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int t=0;t<=1;t++){
                int s = i + j + t;
                int nsta = bnd;
                nsta &= (i==0)<<0 | 6;
                nsta &= (j==0)<<1 | 5;
                nsta &= (s==0)<<2 | 3;
                int nleft = left - (!((nsta>>0)&1)) * v[i]
                                 - (!((nsta>>1)&1)) * v[j]
                                 - (!((nsta>>2)&1)) * v[s%10];
                if(nleft < 0) continue;
                if((s > 9) == cry)
                    ndp = (dfs(t
                               ,nleft
                               ,nsta) + 0ll + ndp) % m;
            }
        }
    }
    return ndp;
}

LL cal(int n){
    memset(dp,-1,sizeof(dp));
    return dfs(false,n-3,7);
}
int main(){
    int T,icase = 1;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d %d",&n,&m)){
        printf("Case #%d: %d\n",icase++,cal(n));
    }
    return 0;
}
