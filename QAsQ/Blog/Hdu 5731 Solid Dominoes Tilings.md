问$ n \times m$的格子铺上$1 \times 2$的骨牌，并且不存在行或列分割线在不跨越骨牌的情况下分隔棋盘

---

定义$any_{n,m} $为用骨牌铺满$ n \times m$的格子在不考虑题目条件的方案数

然后容斥

容斥的时候我们列举列分割线，求在当前枚举的*列分割线存在的情况下***没有***行分割线*的方案数，然后按照枚举的分割线的方案数做一个奇加偶减的容斥就好

具体的，我们假设分割线分隔出来的块共$ p $个，各个块的大小从左到右分别为 $size_1,size_2...size_p$，当前列分割线下在前$i$行**没有**分割线的状态为$tdp_i$，当前列分割线下铺满前**i**行**其它地方任意**（也就是有没有分割线都可以）的方案数为 $anyInMask_i$，可以看出 $anyInMask_i = \prod\limits_{j=1}^p any_{i,size_j}$ 。
然后还有$tdp_i = anyInMask_i - \sum\limits_{j=1}^{i-1} tdp_{i-j} \times anyInMask_j$

那么这个题就做完了

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long  

const int bit = 17, maxn = 1<<bit;
const int mod = 1000000007;
LL any[bit][bit];
LL dp[bit][bit][maxn];

inline bool get(int x,int pos){
    return (x>>(pos-1))&1;
}
inline int sub(int x,int pos){
    return x & (~(1<<(pos-1)));
}
inline int rev(int x,int pos){
    return x ^ (1<<(pos-1));
}

void cdp(int m){
    int bnd = 1<<m;
    dp[0][m][bnd-1] = 1;
    for(int i=1;i<bit;i++){
        for(int j=1;j<=m;j++){
            LL *pdp = j==1 ? dp[i-1][m]:dp[i][j-1];
            for(int mask=0;mask<bnd;mask++){
                dp[i][j][mask] = pdp[rev(mask,j)];
                if(j>1 && get(mask,j-1) && get(mask,j))
                    (dp[i][j][mask] += pdp[sub(mask,j-1)])%=mod;
            }
        }
    }
}

void init(){
    for(int j=1;j<bit;j++){
        cdp(j);
        int bnd = 1<<j;
        for(int i=1;i<bit;i++){
            any[i][j] = dp[i][j][bnd-1];
        }
    }
}

LL mas[bit],mlen;
LL anym(int n){
    LL ret = 1;
    for(int i=0;i<mlen;i++){
        (ret *= any[n][mas[i]]) %= mod;
    }
    return ret;
}
LL tdp[bit];

LL calexc(int n,int mask,int m){
    mlen = 0;
    mas[mlen] = 1;
    for(int i=1;i<=m-1;i++){
        if(mask & 1){
            mlen++;
            mas[mlen] = 0;
        }
        mask >>= 1;
        mas[mlen]++;
    }
    mlen++;
    for(int i=1;i<=n;i++){
        tdp[i] = anym(i);
        for(int j=1;j<i;j++){
            (tdp[i] -= (1ll * tdp[i-j] * anym(j)) %mod ) %=mod;
            (tdp[i] += mod) %= mod;
        }
    }
    return tdp[n];
}

int sig(int x){
    int ret = 1;
    while(x){
        if(x & 1) ret *= -1;
        x >>= 1;
    }
    return ret;
}
LL cal(int n,int m){
    LL ans = 0;
    for(int i=0;i<(1<<(m-1));i++){
       (ans += sig(i) * calexc(n,i,m))%=mod;
       (ans += mod) %= mod;
    }
    return ans;
}
void out(){
    for(int i=1;i<bit;i++){
        printf("{");
        for(int j=1;j<bit;j++){
            printf(j<bit-1?"%lld,":"%lld},\n",cal(i,j));
        }
    }
}
            
int main(){
    init();
    freopen("ans.out","w",stdout);
    out();
    return 0;
}
```

不知道为什么会MEL.......推测是我之前计算$n \times m$的格子任意放的方案数写挫了，想了想并没有什么好改的。。。于是就使用了打表大法

-----

以下是AC代码

```cpp
#include<bits/stdc++.h>
using namespace std;

int ans[16][16]={
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,6,0,108,0,1182,0,10338,0,79818,0,570342},
{0,0,0,0,6,0,124,62,1646,1630,18120,25654,180288,317338,1684956,3416994},
{0,0,0,0,0,124,0,13514,0,765182,0,32046702,0,136189727,0,378354090},
{0,0,0,0,108,62,13514,25506,991186,3103578,57718190,238225406,965022920,388537910,937145938,315565230},
{0,0,0,0,0,1646,0,991186,0,262834138,0,462717719,0,560132342,0,699538539},
{0,0,0,0,1182,1630,765182,3103578,262834138,759280991,264577134,712492587,886997066,577689269,510014880,807555438},
{0,0,0,0,0,18120,0,57718190,0,264577134,0,759141342,0,567660301,0,47051173},
{0,0,0,0,10338,25654,32046702,238225406,462717719,712492587,759141342,398579168,83006813,821419653,942235780,558077885},
{0,0,0,0,0,180288,0,965022920,0,886997066,0,83006813,0,690415372,0,620388364},
{0,0,0,0,79818,317338,136189727,388537910,560132342,577689269,567660301,821419653,690415372,796514774,696587391,175421667},
{0,0,0,0,0,1684956,0,937145938,0,510014880,0,942235780,0,696587391,0,856463275},
{0,0,0,0,570342,3416994,378354090,315565230,699538539,807555438,47051173,558077885,620388364,175421667,856463275,341279366}
};

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        n--,m--;
        printf("%d\n",ans[n][m]);
    }
    return 0;
}
```

