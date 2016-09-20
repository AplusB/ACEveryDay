# hdu 4899 Hero meet devil

给出一个模式串$S,|S| \le 15$

问存在多少个长为$m,m\le 1000$的字符串$T$满足$LCS(S,T) = x(0\le x\le|S|)$

输出$|S|+1$个结果$\pmod{10^9+7}$

$|S|$表示字符串$S$的长度

本题中的字符集为$A,T,C,G$四个字母

---

算是一个$dp\ of\ dp$的入门题？

[题解](http://wjmzbmr.com/archives/my-favorite-problems-in-2014/)见陈老师博客

```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int cnt(int x){
    int ret = 0;
    while(x){
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}
int toid(char c){
    if(c == 'A') return 0; 
    if(c == 'T') return 1; 
    if(c == 'C') return 2; 
    if(c == 'G') return 3; 
    return -1;
}

const int maxn = 17,mod = 1e9 + 7;
char inp[maxn];int arr[maxn];

int nex[1<<maxn][4];
int old[maxn],nw[maxn];

void initState(int n){
    old[0] = 0;
    for(int i=0;i<(1<<n);i++){
        for(int k=1;k<=n;k++){
            old[k] = old[k-1] + ((i>>(k-1))&1);
        }
        for(int j=0;j<4;j++){
            for(int k=1;k<=n;k++){
                nw[k] = max(nw[k-1],old[k]);
                if(arr[k-1] == j) nw[k] = max(nw[k],old[k-1]+1);
            }
            nex[i][j] = 0;
            for(int k=0;k<n;k++){
                nex[i][j] |=(nw[k+1] - nw[k])<<k;
            }
        }
    }
}

LL dp[2][1<<maxn];
LL ans[maxn];

int yet(int i){return i & 1;}
int bef(int i){return (i+1)&1;}

int main(){
    int T;
    scanf("%d",&T);
    int m;
    while(T-- && ~scanf("%s %d",inp,&m)){
        int n = strlen(inp);
        for(int i=0;i<n;i++)
            arr[i] = toid(inp[i]);
        initState(n);
        memset(dp[0],0,sizeof(dp[0]));
        dp[0][0] = 1;
        for(int i = 1;i <= m;i++){
            memset(dp[yet(i)],0,sizeof(dp[yet(i)]));
            for(int mask = 0;mask < (1<<n);mask++){
                for(int j = 0;j < 4;j++){
                    (dp[yet(i)][nex[mask][j]] += dp[bef(i)][mask]) %= mod;
                }
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i=0;i<(1<<n);i++)
            (ans[cnt(i)] += dp[yet(m)][i]) %= mod;
        for(int i=0;i<=n;i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
```