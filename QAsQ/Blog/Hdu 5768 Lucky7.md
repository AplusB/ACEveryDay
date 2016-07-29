# Hdu 5768 Lucky7

求$[x,y]$这个区间内满足

$\pmod{7}  = 0$ 

$\pmod{p_1} \neq a_1$

$\pmod{p_2} \neq a_2​$

.....

$\pmod{p_n} \neq a_n$

的数的个数

$ 0\le x < y \le 10^{18}$，$\prod\limits_{i=1}^np_i\le 10^{18}$

---

一眼数位dp。。一看数据范围直接尿了。。。

再定睛一看只有15个限定条件，感觉是一个容斥.

------

因为忘记了怎么去推两个公式的情况莫名卡了大半辈子,手算了$\pmod{7}$的逆元。。。

---

代码也是十分模板。。。

```cpp
#include <bits/stdc++.h>
#define LL long long

using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    LL d = exgcd(b,a%b,y,x);
    y -= (a/b) *x;
}

LL crt(LL *a,LL *m,int n,LL &M){
    M = 1;
    LL ans = 0;
    for(int i=0;i<n;i++)
        M *= m[i];
    for(int i=0;i<n;i++){
        LL x,y;
        LL Mi = M / m[i];
        exgcd(Mi,m[i],x,y);
        (ans += Mi * x * a[i]) % M;
        (ans += M) %= M;
    }
    return ans;
}
LL getp(LL n,LL p,LL a){
    if(n < a) return 0;
    return (n-a)/p + 1;
}
int n;

LL p[20],a[20];
LL pv[20],av[20];
const int rev[8] = {0,1,4,5,2,3,6};

LL cal(LL y){
    LL ans = y / 7;
    LL M;
    LL mid = getp(y,7,0);
    for(int i=1;i<(1<<n);i++){
        int len = 0,sig = 1;
        for(int j=0;j<n;j++){
            if((i>>j) & 1){
                pv[len] = p[j],av[len] = a[j];
                len++;
                sig *= -1;
            }
        }
        LL a = crt(av,pv,len,M);
        LL x = (7 - a%7) * rev[M % 7] % 7;
        x = x * M + a;
        x %= 7 * M;
        LL tem =  getp(y,7*M,x);
        ans += sig * tem;
    }
    return ans;
}

int main()
{
    int T,m;
    LL x,y;
    int icase = 1;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %I64d %I64d",&n,&x,&y)){
        for(int i=0;i<n;i++){
            scanf("%I64d %I64d",&p[i],&a[i]);
        }
        printf("Case #%d: %I64d\n",icase++,cal(y) - cal(x-1));
    }
    return 0;
}
```

