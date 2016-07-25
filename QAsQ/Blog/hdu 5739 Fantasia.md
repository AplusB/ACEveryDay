# hdu 5739 Fantasia

偷偷放上[题解 -by zimpha](http://bestcoder.hdu.edu.cn/blog/2016-multi-university-training-contest-2-solutions-by-zimpha/)

> 感谢叉姐在ICPCCamp上出的这道题最初的原型 -- Data Structure You've Never Heard Of, 同样感谢Claris老师的教导.
> 由于and, or和xor方法都差不多, 这里仅考虑and操作. 不妨令$dp(s)=f(s)-w_s$, 我们大概要求的就是$dp(i)=\displaystyle\max_{j \text{ is ancestor of } i}\{dp(j)+w_i\text{ and }w_j\}$. 然后, 显然$dp(j)+w_i\text{ and }w_j$这个式子可以拆成$dp(j)$+[$w_i$后8位] and [$w_j$后8位] + ([$w_i$前8位] and [$w_j$前8位]) &lt;&lt; 8.
> 先考虑序列上应该如何做, 即求$dp(i)=\displaystyle\max_{j < i}\{dp(j)+w_i\text{ and }w_j\}$. 考虑这样一个二维数组$ds(x,y)$, 表示对于某个$w_i$的后8位为$y$, 对于某个$w_j$的前8位为$x$时, $dp(j)$ + [$w_i$后8位] and [$w_j$后8位]的最值.
> 如果知道了上述数组, 那么对于某个$i$, 计算$dp(i)$的值就十分方便, 不妨令$w_i=(a &lt;&lt; 8) | b$, 即$a$和$b$分别是$w_i$前8位和后8位, 那么只需要枚举$w_j$的前8位$x$, 用$ds(x,b)+((a \text{ and } x) &lt;&lt; 8)$更新$dp(i)$. 把新的$dp$值更新到$ds(x,y)$也是类似的.
> 上述方法推广到树上也是十分简单, 由于每次更新$ds(x,y)$的时候只有数组的一维会变动(令$a$=$w_i$>>8, 那么只有$ds(a,\cdot)$会变化), 那么只要对数组的第一维做一个可持久化就好了(或者说边dfs边备份).



---

写的时候~~强行~~以为子节点更新的时候不一定会更新当前节点的同一行,错了几发

----

~~Data Structure You've Never Heard Of这个名字我可以玩一星期~~

```cpp
#include<bits/stdc++.h>
using namespace std;

char opt[5];
int op(int x,int y){
    if(*opt == 'A') return x & y;
    if(*opt == 'X') return x ^ y;
    return x | y;
}
const int mod = 1e9+7;
const int maxn = 112345;
const int bit = 1<<8;
#define LL long long
const LL INF = 0x3f3f3f3f3f3f3f3fll;

vector<int> edge[maxn];
void init(int n){
    for(int i=0;i<=n;i++) edge[i].clear();
}

int w[maxn];
LL dp[maxn];
LL ds[bit][bit],space[maxn][bit];

void dfs(int st){
    int a = w[st] >> 8, b = w[st] & (bit - 1);
    dp[st] = 0;
    for(int x=0;x<bit;x++)
      	dp[st] = max(dp[st],ds[x][b] + (op(a,x)<<8)); 
    for(int y=0;y<bit;y++){
        space[st][y] = ds[a][y];
        ds[a][y] = max(ds[a][y],dp[st] + op(b,y));
    }
    for(auto x : edge[st]) 
      	dfs(x); 
    for(int i=0;i<bit;i++) 
      	ds[a][i] = space[st][i];
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d %s",&n,opt)){
        for(int i=1;i<=n;i++) 
          	scanf("%d",&w[i]); 
        for(int i=0;i<bit;i++)
            for(int j=0;j<bit;j++)
                ds[i][j] = -INF;
        init(n);
        int x;
        for(int i=2;i<=n;i++){
            scanf("%d",&x);
            edge[x].push_back(i);
        }
        LL ans = 0;
        dfs(1);
        for(int i=1;i<=n;i++){
            (ans += (dp[i] + w[i]) * i)%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
```

