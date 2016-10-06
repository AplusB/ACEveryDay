# Hdu 5456 Matches Puzzle Game

问有多少个等式满足使用的火柴棍个数恰好为$n$个

输出等式个数$\pmod{m}$

$5\le n \le 500,3 \le m \le 2\times 10^9$

---

就是求满足$a + b = c$，并且$a,b,c$每一位按照使用的火柴棍个数加权之后恰好等于$n-3$的等式个数

考虑到这个题的状态和之前使用了多少位无关并且保证剩下的火柴棍是单调递减的

可以记$dp_{cnt,cry,az,bz,cz}$为火柴棍还有$cnt$个，下一位是否要进位，$a$，$b$，$c$是否都是前导零的方案数

---

因为刚开始把位数记录到了状态里，在$TLE$的时候把$az,bz,cz$压到了一个数用二进制表示了。其实本质还是一样的

```cpp
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
```

