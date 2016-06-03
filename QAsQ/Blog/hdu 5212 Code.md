# hdu 5212 Code

求$\sum\limits_{i=1}^n\sum\limits_{j=1}^ngcd(a_i,a_j) \times (gcd(a_i,a_j)-1) \pmod{10007}$

$1\le n,a_i\le 10000$

几乎是反演模板题

枚举gcd算贡献就好

具体见代码

----

```cpp
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 11234;
const int mod = 10007;

vector<int> fac[maxn];
LL mu[maxn];

void init(){
    memset(mu,0,sizeof(mu));
    mu[1] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            fac[j].push_back(i);
            if(j!=i) mu[j] -= mu[i];
        }
    }
}

LL cnt[maxn];

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        memset(cnt,0,sizeof(cnt));
        int x;
        while(n--){
            scanf("%d",&x);
            for(vector<int>::iterator it = fac[x].begin();it!=fac[x].end();it++){
                cnt[*it]++;
            }
        }
        LL ret = 0;
        for(int i=1;i<maxn;i++){
            LL tim = 0;
            for(int j=i;j<maxn;j+=i){
                (tim += mu[j/i]*(cnt[j]*cnt[j])) %= mod;
            }
            ret += tim * i % mod * (i-1);
            ret %= mod;
        }
        printf("%I64d\n",ret);
    }
    return 0;
}
```

