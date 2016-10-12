# Codeforces 55D - Beautiful numbers

统计$[L,R]$内能被自己每一非零位整除的数的个数。

---

~~一眼数位dp~~

考虑到$LCM(1,2...9) = 2520$

可以用前缀mod2520和前缀非0数的LCM做为状态

注意到由1到9组成的lcm其实是很稀疏的，可以离散化一下。

具体就见代码吧。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
#define LL long long 
const int full = 2520;
LL dp[maxn][full][50];
int num[maxn];

int sid[full+1],cid[full];

int nex(int bef,int x){
    if(!x) return bef;
    bef = cid[bef];
    bef /= __gcd(bef,x);
    bef *= x;
    bef = sid[bef];
    return bef;
}
void init(){
    int len = 0;
    for(int i=0;i<(1<<10);i++){
        int v = 1;
        for(int j=1;j<=9;j++){
            if((i>>j) & 1){
                v /=  __gcd(v,j) ,v *= j;
            }
        }
        cid[len++] = v;
    }
    sort(cid,cid+len);
    len = unique(cid,cid+len) - cid;
    memset(sid,-1,sizeof(sid));
    for(int i=0;i<len;i++){
        sid[cid[i]] = i;
    }
}

LL dfs(int pos,bool bnd,int fz,int mask){
    if(pos < 0) return fz % cid[mask] == 0;
    LL & ndp = dp[pos][fz][mask];
    if(!bnd && ~ndp) return ndp;
    LL ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        ret += dfs(pos-1,bnd && i == bound,(fz * 10 + i) % full,nex(mask,i));
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
    return dfs(len-1,true,0,sid[1]);
}

int main(){
    init();
    int t;
    cin>>t;
    LL l,r;
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin>>l>>r;
        cout<<cal(r) - cal(l-1)<<endl;
    }
    return 0;
}
```

