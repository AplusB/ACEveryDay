# hdu 1074 Doing Homework

给出$n(n\le 15)$个作业的需要完成的时间和deadline，求一个作业的排列，使得最后被扣的分最少，对于每个作业，如果在deadline之后完成，超过deadline的时间就是被扣的分数，当然在deadline之前完成就不扣分了

----

因为是要求一个排列，而且$O(2^n)$的复杂度看起来很科学的样子，所以想到状压dp

---

$dp_{mask}$代表已经完成$mask$中的作业的最小扣的分数，通过枚举哪一个作业最后完成来进行转移

----

最后要求字典序最小，那么在转移的时候优先考虑字典序最大的前一个状态（因为转移是从后往前的

----

剩下的就是代码了

```cpp
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 16;
const int INF = 0x3f3f3f3f;

int dp[1<<maxn],pre[1<<maxn];
int dl[maxn],last[maxn];

char arr[maxn][110];
int n;

int slast(int S){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(S&(1<<i)) ret += last[i];
    }
    return ret;
}

int dfs(int S){
    if(dp[S] != INF){
        return dp[S];
    }
    int sumer = slast(S);
    for(int i=0;i<n;i++){
        if(S&(1<<i)){
            int ndp = dfs(S-(1<<i)) + max(0,sumer-dl[i]);
            if(ndp <= dp[S]){
                dp[S] = ndp,pre[S] = i;
            }
        }
    }
    return dp[S];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s %d %d",arr[i],&dl[i],&last[i]);
        }
        int all = (1<<n)-1;
        memset(dp,0x3f,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        dp[0] = 0;
        printf("%d\n",dfs(all));
        stack<int> S;
        while(all){
            S.push(pre[all]);
            all -= (1<<pre[all]);
        }
        while(S.empty()==false){
            printf("%s\n",arr[S.top()]);
            S.pop();
        }
    }
    return 0;
}
```

