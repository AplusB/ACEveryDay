# Poj 3208 Apocalypse Someday

求第$n$小的数位中含有三个连续的6的数。

---

考虑小于$x$的数位中含有连续三个6的数的个数，可以数位dp。

状态为之前连续的6的个数，如果已经有三个6了，无论加什么数字都是合法状态，否则加一个不为6的数就重置个数为0。

然后二分就好了

```cpp
#include<cstdio>
#include<cstring>
using namespace std;

#define LL long long 
const int maxn = 30;
LL INFF = 0x3f3f3f3f3f3f3f3fll;

LL dp[maxn][4];
int num[maxn];
int nstate(int st,int x){
    if(st == 3) return 3;
    if(x != 6) return 0;
    return st + 1;
}

LL dfs(int pos,bool bnd,int st){
    if(pos < 0) return st == 3;
    LL & ndp = dp[pos][st];
    if(!bnd && ~ndp) return ndp;
    LL ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        ret += dfs(pos-1,bnd && i == bound,nstate(st,i));
    }
    if(!bnd) ndp=ret;
    return ret;
}

LL cal(LL n){
    int len = 0;
    while(n){
        num[len++] = n % 10;
        n /= 10;
    }
    return dfs(len-1,true,0);
}

LL anw(int n){
    LL st = 0,ed = INFF;
    LL ans = -1;
    while(st <= ed){
        LL mid = (st + ed) >> 1;
        if(cal(mid) < n){
            st = mid+1;
        }
        else{
            ans = mid;
            ed = mid - 1;
        }
    }
    return ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int T;
    int n;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        printf("%lld\n",anw(n));
    }
    return 0;
}
```

