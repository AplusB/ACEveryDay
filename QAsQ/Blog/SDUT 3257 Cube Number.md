# SDUT 3257 Cube Number

和上一题类似的一个题 

给出$n(n\le1e6)$个数$a_i\le1e6$，问其中有多少个数对满足这个数对的乘积是立方数

对于一个数$x = \prod\limits_{i=1}^np_i^{e_i}$

我们记$sim(x) = \prod\limits_{i=1}^np_i^{e_i mod\;3},sym(x) = \prod\limits_{i=1}^np_i^{ 3 - e_i mod\;3}$

那么其实一个数对$(x,y)$能满足他们的乘积是方立方数当且仅当$sim(x) = sym(y)$

当然这也等价于$sym(x) = sim(y)$，（想一想，为什么

然后还是用哈希就好，值得注意的是$sym(a)$最大可能超过$1e11$，处理方法是不予统计（

代码如下

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
#define LL long long
LL pri[maxn];
LL unp[maxn];

void sieve(){
    memset(pri,-1,sizeof(pri));
    pri[1] = 1;
    unp[1] = 1;
    for(LL i=2;i<maxn;i++){
        if(pri[i] == -1){
            pri[i] = i;
            unp[i] = i*i;
            for(int j=i*2;j<maxn;j+=i){
                if(pri[j] == -1) pri[j] = i,unp[j] = i*i;
                else pri[j] *= i,unp[j] *= i*i;
            }
            int cnt = 1;
            for(LL j=i*i;j<maxn;j*=i){
                cnt++;
                for(LL k=1;k*j<maxn;k++){
                    if(cnt % 3 == 1){
                        pri[k*j] *= i;
                        unp[k*j] *= i*i;
                    }
                    if(cnt % 3 == 2){
                        pri[k*j] *= i;
                        unp[k*j] /= i;
                    }
                    if(cnt % 3 == 0){
                        pri[k*j] /= i*i;
                        unp[k*j] /= i;
                    }
                }
            }
        }
    }
}

int Hash[maxn];

int main(){
    int T;
    sieve();
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        int x;
        LL ans = 0;
        memset(Hash,0,sizeof(Hash));
        while(n--){
            scanf("%d",&x);
            if(unp[x] < maxn)
                ans += Hash[unp[x]];
            Hash[pri[x]]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

```

