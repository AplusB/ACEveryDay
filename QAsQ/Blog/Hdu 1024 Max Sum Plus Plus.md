# Hdu 1024 Max Sum Plus Plus

给你$n$个数的序列，在这个序列中取$m$个不相交的区间，使得这些区间的数的和最大

----

题中没有给$m$的范围。。。我以为是$O(n \times m)$会TLE的。。结果过了。。

----

定义状态就是$dp_{i,j}$为前i个数分成了j段且最后一段的最后一个数就是第i个数的最优解

然后就可以转移了$dp_{i,j}= max(dp_{i,j-1},dp_{i-1,k})+val_j (k \le j)$

不过这样的话时间是$O(n^2 \times m)$的

注意到我们查询的是一个前缀最小值，那么在转移的同时维护一下就好了

---

还有一个普通的滚动数组优化

```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1123456;

LL dp[maxn],arr[maxn];
LL ma[maxn];

int main(){
    int n,m;
    while(~scanf("%d %d",&m,&n)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&arr[i]);
        }
        for(int i=0;i<=m;i++){
            dp[i] = ma[i] = -INFF;
        }
        ma[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                dp[j] = max(ma[j-1],dp[j])+arr[i];
                ma[j] = max(dp[j],ma[j]);
            }
        }
        printf("%I64d\n",ma[m]);
    }
    return 0;
}
```

