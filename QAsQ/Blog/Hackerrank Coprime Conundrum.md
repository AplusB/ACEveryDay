# Hackerrank Coprime Conundrum

计算小于乘积小于$n$的互质二元组的个数

具体的，计算$\sum_\limits{i=1}^n\sum\limits_{j=i}^n[i \times j \le n][gcd(i,j)=1]$

其中$n\le 10^9$

----

可以考虑枚举$i$，计算和$i$互质大于$i$并且和$i$乘积小于等于$n$的数的个数

这部分可以用容斥在$O(log(i))$的时间内解决

于是这题就可以在$O( \sqrt{n}\times log(n) )$的时间内解决了

---

容斥这部分可以先筛一个莫比乌斯函数在预处理每个数那些莫比乌斯函数不等于0的因子来简化计算，具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;

LL count(LL v,LL st,LL ed){
    return ed / v - st / v;
}

int mu[maxn];
vector<int> fac[maxn];

LL cal(LL v,LL ed){
    LL ret = 0;
    for(auto x : fac[v]){
        ret += mu[x] * count(x,v,ed);
    }
    return ret;
}

int main(){
    memset(mu,0,sizeof(mu));
    mu[1] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=i*2;j<maxn;j+=i){
            mu[j] -= mu[i];
        }
    }
    for(int i=1;i<maxn;i++){
        if(mu[i])
            for(int j=i;j<maxn;j+=i)
                fac[j].push_back(i);
    }
    LL n;
    cin>>n;
    LL ans = 0;
    for(LL i = 2;i * i <= n;i++){
        ans += cal(i,n / i);
    }
    cout<<ans<<endl;
    return 0;
}
```

