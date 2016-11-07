# Hdu 4804 Campus Design

有一个$n\times m(n\le 100,m\le10)$的棋盘，除了一些不能被覆盖的位置外其他的地方用$1\times2$和$1\times1$的骨牌填满，$1\times1$的骨牌使用次数在$[C,D]$之间。问满足条件的方案数$\pmod {10^9+7}$

---

一个简单的插头dp入门题。

不能覆盖的地方可以视作必须放下$1\times 1$的骨牌并且不占使用的个数来简化代码。

因为直接列下状态数内存吃不消，用滚动数组优化即可

---

*有的时候一些适当的注释能降低写代码的时候的脑力负担*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
char Map[112][12];
bool arr[112][12];
#define LL long long
int dp[2][1<<12][25];

inline int ge(int k,int j){return (k >> j) & 1;}
inline int sub(int k,int j){return k & (~(1<<j));}
inline int add(int k,int j){return k | (1<<j);}

int main(){
    int n,m,c,d;
    while(~scanf("%d %d %d %d",&n,&m,&c,&d)){
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n;i++)
            scanf("%s",Map[i]);
        for(int i = 0;i <= n;i++){
            for(int j = 0;j < m;j++){
                arr[i][j] = (i>0) && (Map[i][j] == '1');
            }
        }
        int bnd = (1<<m) - 1;
        dp[0][bnd][0] = 1;
        for(int i = 1; i <= n;i++){
            for(int j = 0; j < m;j++){

                for(int k = 0 ; k <= bnd; k ++){
                    for(int lef = 0 ; lef <= d;lef++){
                        int &ndp = dp[1][k][lef];
                        if(arr[i][j]){ // can add
                            if(ge(k,j)){
                                (ndp += dp[0][sub(k,j)][lef] ) %= mod; // |
                                if(lef-1>=0) (ndp += dp[0][k][lef-1]) %= mod;  //. 
                                if(j && ge(k,j-1)) (ndp += dp[0][sub(k,j-1)][lef]) %= mod; //- 
                            }
                            else (ndp += dp[0][add(k,j)][lef])%=mod;    //empty
                        }
                        else if(ge(k,j)) (ndp += dp[0][k][lef])%=mod; //only have .
                    }
                }

                for(int k = 0 ; k <= bnd; k ++){
                    for(int lef = 0 ; lef <= d;lef++){
                        dp[0][k][lef] = dp[1][k][lef];
                        dp[1][k][lef] = 0;
                    }
                }
            }
        }
        int ans = 0;
        for(int lef = c ; lef <= d;lef++){
            (ans += dp[0][bnd][lef] ) %= mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

