# Hdu 5155 Harry And Magic Box

在$n \times m$的盒子中有多少种放置石头的方案使得每一行每一列都至少有一个石头$(0 \le n,m \le 50)$

----

这个dp计数的状态感觉也是十分的炫酷

$dp_{i,j}$表示前$i$行每一行都至少有一个石头并且有且仅有$j$列有石头(也就是剩下$m-j$列都是空列)的方案数。

这样的话答案就是$dp_{n,m}$

---

然后我们考虑状态转移，考虑状态$dp_{i,j}$从哪里转移过来

考虑第$i$行我们恰好放置$k$个石子，已有的状态是前$i-1$行恰好有$j-t$列放置有石头

假设这$k$个石子中有$t$个是放在空列的下面的，剩下的$k-t$个放在非空列的下面

前一部分的方案数为 $\binom{空列的个数}{k}$ ,后一部分的方案为$\binom{非空列的个数}{k-t}$

因为两部分是独立的，所以可以直接乘起来，也就是

$dp_{i,j} = \sum\limits_{k=1}^j  \sum\limits_{t=0}^k dp_{i-1,j-t} \times \binom{m-j+t}{t} \times \binom{j-t}{k-t}$

----

```cpp
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define LL long long

const int maxn = 55;
const int mod = 1000000007;

LL dp[maxn][maxn];
LL c[maxn][maxn];

void init(){
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for(int i=1;i<=50;i++){
        for(int j=0;j<=i;j++){
            c[i][j] = (c[i-1][j] + (j>0?c[i-1][j-1]:0) ) % mod;
        }
    }
}

int main(){
    int n,m;
    init();
    while(~scanf("%d %d",&n,&m)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            dp[1][i] = c[m][i];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=j;k++){
                    for(int t=0;t<=k;t++){
                        (dp[i][j] += ( dp[i-1][j-t] * c[m-j+t][t] ) % mod  
                         * c[j-t][k-t] ) %= mod;
                    }
                }
            }
        }
        printf("%I64d\n",dp[n][m]);
    }
    return 0;
}
```



