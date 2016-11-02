# Codeforces 349D - Apple Tree

有一个有根树，每个叶子节点都有一定量的苹果(可能为0)，非叶子节点上没有苹果。一个节点的重量定义为在以这个节点为根的子树内的节点的苹果个数和。对于一个节点称它是平衡的当且仅当这个节点的每个子节点的重量都相等。问最小需要拿走多少个苹果才能令所有节点都平衡。

---

假设我们已经将一个子树拿成了平衡的，这个子树的父节点需要这个子树继续拿走苹果的时候，苹果是一份一份拿的，一份中含有的苹果的个数依赖于这个子树的形态。手动模拟几次后会发现，某个节点的一份苹果个数等于他这个点的子节点的一份苹果个数的$LCM$(注意这里可能会超过$long\ long$的表示范围，对于这种情况我们可以认为这个树平衡当且仅当所有的苹果都被拿走)。

那么对于一个节点，先计算这个节点的可拿走的苹果个数，然后计算苹果个数的上界。然后贪心的选择一个最大的重量更新状态来更新节点的情况。自底向上计算答案即可。

---

```cpp
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
```

