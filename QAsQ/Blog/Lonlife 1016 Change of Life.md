# Lonlife 1016 Change of Life 

定义$f(x)$为$LIS(a_0,a_1...a_m)(n = a_0 + a_1\times 10+...+a_m\times 10^m,0\le a_i\le 9,a_m\neq 0)$

求$\sum_{i=1}^nf(i)$

$1 \le n \le 10^{15}$

---

一眼看过去就是一个数位$dp$，但是我们用怎么样的状态表示最长上升子序列这个东西呢？

考虑到最长上升子序列的二分$nlog(n)$解法中用到的状态表示$dp_i$表示长$i$的最长上升子序列结尾最小的那个序列的结尾，同时保证了$dp$数组的单调性。

因为是严格上升，所以$dp$数组是不重复的。因为序列中的数只有$[0,9]$这10个数，我们可以用状态压缩保存$dp$数组有哪几个数，又因为$dp$数组的单调性，所以这个状态表示是唯一的。

---

因为低位在第一个位置的最长上升子序列不好写，改成了最高位在第一个位置的最长下降子序列

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 20;

LL dp[maxn][1<<10];
int num[maxn];
int nex[1<<10][10],one[1<<10];

int tem[maxn];

int getnex(int S,int x){
    int n = 0;
    for(int i=9;i>=0;i--) if((S>>i) & 1) tem[n++] = i;
    one[S] = n;
    for(int i=0;i<n;i++){
        if(tem[i] <= x){
            return (S & (~(1<<tem[i]))) | (1<<x);
        }
    }
    return S | (1<<x);
}

void init(){
    for(int i=0;i<(1<<10);i++){
        for(int j=0;j<10;j++){
            nex[i][j] = getnex(i,j);
        }
    }
}

LL dfs(int pos,bool bnd,int sta){
    if(pos < 0) return one[sta];
    LL & ndp = dp[pos][sta];
    if(!bnd && ~ndp) return ndp;
    LL ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        ret += dfs(pos-1
                  ,bnd && i == bound
                  ,nex[sta][i]);
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
    return dfs(len-1,true,0);
}

int main(){
    int T;
    init();
    scanf("%d",&T);
    LL n;
    memset(dp,-1,sizeof(dp));
    while(T-- && ~scanf("%lld",&n)){
        printf("%lld\n",cal(n)-1);;
    }
    return 0;
}
```

