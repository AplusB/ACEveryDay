#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 50;

LL INFF =0x3f3f3f3f3f3f3f3fll;
LL dp[maxn][2];
int dig[maxn];

LL dfs(int pos,int pre,bool bound){
    if(pos<0) return 1;
    if(dp[pos][pre]!=-1 && !bound){
        return dp[pos][pre];
    }
    LL ret = 0;
    int bnd = bound ? dig[pos]:1;
    for(int i=0;i<=bnd;i++){
        if(!i || !pre)
            ret+=dfs(pos-1,i,bound && i==bnd);
    }
    if(!bound) dp[pos][pre] = ret;
    return ret;
}

LL cal(LL x){
    int len = 0;
    for(int i=0;i<maxn;i++){
        dig[i] = x & 1;
        x >>= 1;
    }
    return dfs(maxn-1,0,true);
}

LL caler(LL k){
    LL st,ed;
    st = 0,ed = INFF;
    while(st < ed){
//        printf("sted %lld %lld\n",st,ed);
        LL mid = st + (ed-st)/2;
        LL tk = cal(mid);
        if(tk == k){
            ed = mid;
        }
        else{
            if(tk > k){
                 ed = mid-1;
            }
            else{
                st = mid + 1;
            }
        }
    }
    return st;
}

int clen(LL x){
    int ret = 0;
    while(x){
        ret++;
        x /= 2;
    }
    return ret;
}


int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    LL k;
    while(cin>>n>>k){
        LL ans = caler(k);
        if(clen(ans) > n){
            puts("-1");
        }
        else{
            for(int i=0;i<maxn;i++){
                dig[i] = ans & 1;
                ans >>= 1;
            }
            for(int i=n-1;i>=0;i--){
                printf("%d",dig[i]);
            }
            puts("");
        }
    }
    return 0;
}
