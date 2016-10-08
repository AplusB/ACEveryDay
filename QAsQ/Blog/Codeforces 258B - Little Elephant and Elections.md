# Codeforces 258B - Little Elephant and Elections

从$[1,m]$中依次选择$7$个数，满足前六个数中$4$和$7$的个数之和小于最后一个数的$4$和$7$的个数的方案数$\pmod{1e9+7}$

---

我们按照4和7的个数对[1,m]的数做等价类划分。然后dfs就好。前半部分可以用数位dp解决。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 12,mod = 1e9+7;
#define LL long long  

LL dp[maxn][2][maxn];
int num[maxn];

LL dfs(int pos,bool bnd,int ned){
    if(ned < 0) return 0;
    if(pos < 0) return ned == 0;
    LL & ndp = dp[pos][bnd][ned];
    if(~ndp) return ndp;
    ndp = 0;
    int bound = bnd ? num[pos] : 9 ;
    for(int i=0;i<=bound;i++)
        ndp += dfs(pos-1,bnd && i == bound,ned - (i==4||i==7) );
    return ndp;
}

LL cnt[maxn];

int init(LL x){
    int len = 0;
    while(x){
        num[len++] = x % 10;
        x /= 10;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=len;i>=0;i--){
        cnt[i] = dfs(len-1,true,i);
    }
    cnt[0]--;
    return len;
}

LL ans;

void dfs(int st,LL v,int len,int adder){
    if(st == 7){
        for(int i=adder+1;i<=len;i++){
            (ans += v * cnt[i] % mod) %= mod;
        }
        return;
    }
    if(adder >= len) return;
    for(int i=0;i<=len;i++){
        if(cnt[i] == 0) continue;
        LL mid = v * cnt[i] % mod;
        cnt[i]--;
        dfs(st+1,mid,len,adder+i);
        cnt[i]++;
    }
}

int main(){
    LL n;
    scanf("%I64d",&n);
    int len = init(n);
    ans = 0;
    dfs(1,1,len,0);
    printf("%I64d\n",ans);
    return 0;
}
```

