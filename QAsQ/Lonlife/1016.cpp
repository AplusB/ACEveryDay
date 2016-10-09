#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 20;

LL dp[maxn][1<<10];
int num[maxn];
int nex[1<<10][10],one[1<<10];

int tem[maxn];

int getnex(int S,int x){
    int n = 0;
    for(int i=9;i>=0;i--) if((S>>i) & 1) tem[n++] = i;
    one[S] = n;
    for(int i=0;i<n;i++){
        if(tem[i] <= x){
            return (S & (~(1<<tem[i]))) | (1<<x);
        }
    }
    return S | (1<<x);
}

void init(){
    for(int i=0;i<(1<<10);i++){
        for(int j=0;j<10;j++){
            nex[i][j] = getnex(i,j);
        }
    }
}

LL dfs(int pos,bool bnd,int sta){
    if(pos < 0) return one[sta];
    LL & ndp = dp[pos][sta];
    if(!bnd && ~ndp) return ndp;
    LL ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        ret += dfs(pos-1
                  ,bnd && i == bound
                  ,nex[sta][i]);
    }
    if(!bnd) ndp = ret;
    return ret;
}

LL cal(LL x){
    int len = 0;
    while(x){
        num[len++] = x % 10;
        x /= 10;
    }
    return dfs(len-1,true,0);
}

int main(){
    int T;
    init();
    scanf("%d",&T);
    LL n;
    memset(dp,-1,sizeof(dp));
    while(T-- && ~scanf("%lld",&n)){
        printf("%lld\n",cal(n)-1);;
    }
    return 0;
}

