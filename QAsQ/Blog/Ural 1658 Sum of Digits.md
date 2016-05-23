# Ural 1658 Sum of Digits

求最小的，各个数位的和为$S_1$,各个数位的平方和为$S_2$的数

----

一眼看下来只会求方案数啊GG，最小的该怎么办呢

然后可以想到如果一个数的位数少，他肯定是短的

所以我们要找到最短位的那个数应该就是答案了

dp的时候顺便维护一下是用哪个数字转移过来的，回溯过去记录答案

最后再把拥有的数从小到大排一下，应该就是最优的了

-----

但是这样空间复杂度是1e10啊QAQ，还是要GG啊

你或许注意到了，要是数位大于100，也是无解

也就是只有$900 \times 8100$的状态，然后就可以很开心的做了

------

最后一个对空间的优化是不用记录上一次的坐标，而是通过转移过来的数字来计算坐标

```cpp
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000;
const int maxm = 9000;
int dp[maxn][maxm],v[maxn][maxm];
vector<int> ans;

int main(){
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=900;i++){
        for(int j=1;j<=8100;j++){
            for(int k=1;k<=9;k++){
                int x = i-k,y = j-k*k;
                if(x>=0 && y>=0){
                    if(dp[i][j] > dp[x][y]+1){
                        dp[i][j] = dp[x][y]+1;
                        v[i][j] = k;
                    }
                }
            }
        }
    }
    int s1,s2;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %d",&s1,&s2)){
        if(s1>900 || s2>8100 || dp[s1][s2]>100){
            puts("No solution");
        }
        else{
            ans.clear();
            int x = s1,y = s2;
            while(x && y){
                ans.push_back(v[x][y]);
                int t = v[x][y];
                x -= t,y -= t*t;
            }
            sort(ans.begin(),ans.end());
            for(auto x : ans){
                printf("%d",x);
            }
            puts("");
        }
    }
    return 0;
}
```

*ps：无解的情况判断错误，不应该是这个地方没有被dp扫到，而是dp\[s1\]\[s2\] > 100*