#include<bits/stdc++.h>
using namespace std;

#define LL long long 

LL dp[60][50];
int num[60],k;

LL dfs(int pos,bool bnd,int hav){
    if(pos < 0) return hav;
    LL & ndp = dp[pos][hav];
    if(~ndp && !bnd) return ndp;
    LL ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i = 0 ; i <= bound ; i ++){
        ret += dfs(pos-1,bnd && i == bound,hav + (i == k));
    }
    if(!bnd) ndp = ret;
    return ret;
}

LL cal(LL n){
    if(n==0) return 0;
    int len = 0;
    while(n){
        num[len++] = n % 10;
        n /= 10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(len-1,true,false);
}

int main(){
    int T;
    scanf("%d",&T);
    LL l,r;
    while(T-- && ~scanf("%lld %lld %d",&l,&r,&k)){
        printf("%lld\n",cal(r) - cal(l-1));
    }
    return 0;
}
