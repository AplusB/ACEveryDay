#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;

vector<int> edge[maxn];
const LL INFF = 0x3f3f3f3f3f3f3f3f;

LL val[maxn],dp[maxn],csub[maxn];

bool hav;
LL lcm(LL a,LL b){
    if(a * b > INFF){
        hav = false;
        return 1;
    }
    LL gcd = __gcd(a,b);
    return a / gcd * b;
}
void dfs(int st,int fa){
    dp[st] = val[st], csub[st] = 1 ;
    int ssiz = 0;
    for(auto x : edge[st]){
        if(x == fa) continue;
        ssiz ++;
        dfs(x,st);
        csub[st] = lcm(csub[st],csub[x]); 
        dp[st] += dp[x];
    }
    for(auto x : edge[st]){
        if(x == fa) continue;
        dp[st] = min(dp[st],dp[x] - dp[x] % csub[st]);
    }
    if(ssiz == 0) ssiz = 1;
    dp[st] *= ssiz;
    csub[st] *= ssiz;
}


int main(){
    int n;
    scanf("%d",&n);
    LL sum = 0;
    for(int i = 1;i<=n;i++){
        scanf("%I64d",&val[i]);
        sum += val[i];
    }
    int l,r;
    for(int i = 1;i<n;i++){
        scanf("%d %d",&l,&r);
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    hav = true;
    dfs(1,0);
    if(!hav) dp[1] = 0;
    printf("%I64d\n",sum - dp[1]);
    return 0;
}
