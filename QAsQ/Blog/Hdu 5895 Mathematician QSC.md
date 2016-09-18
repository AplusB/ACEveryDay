# Hdu 5895 Mathematician QSC

 $f(0) = 0, f(1) = 1, f(n) = f(n - 2) + 2 * f(n - 1) \\g(n) = \sum\limits_{i=0}^nf(i)^2$, 

求 $x^{g(n * y)}\ \mathrm{mod}\ (s + 1)$



---

首先有一个公式写作$x ^ a \pmod{P} = x ^{a \ mod\ \phi(P) + \phi(P)}\pmod{P}$

其中$\phi(n)$是欧拉函数

然后由$f(n)$的递推公式可以得出$g(n) = 5\times g(n-1) + 5\times g(n-2) - g(n-3)$

这样的话$g(n)$就可以用矩阵快速幂的姿势在$log(n \times y)$的时间内求出来

就做完了

具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 112345;

LL MOD;

const int N=4;

struct martix
{
    LL num[N][N];
    void tz()
    {
        memset(num,0,sizeof(num));
    }
    void to()
    {
        this->tz();
        for(int i=0; i<N; i++) num[i][i]=1;
    }
};
martix operator * (const martix & A,const martix & B)
{
    martix C;
    C.tz();
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                ( C.num[i][j] += A.num[i][k]*B.num[k][j] % MOD ) %=MOD ;
    return C;
}
martix pmod(martix x,LL n)
{
    martix res;
    res.to();
    while(n>0)
    {
        if(n & 1) res=res*x;
        x = x*x;
        n >>= 1;
    }
    return res;
}

LL g(LL tim,LL M)
{
    martix q;
    q.num[0][0] = 0; q.num[0][1] = 1; q.num[0][2] = 0; q.num[0][3] = 0;
    q.num[1][0] = 1; q.num[1][1] = 4; q.num[1][2] = 4; q.num[1][3] = 0;
    q.num[2][0] = 0; q.num[2][1] = 2; q.num[2][2] = 1; q.num[2][3] = 0;
    q.num[3][0] = 0; q.num[3][1] = 1; q.num[3][2] = 0; q.num[3][3] = 1;
    MOD = M;
    q = pmod(q,tim+1);
    return q.num[3][0];
}

LL phi(LL n)
{
    LL ans = n;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            ans -= ans / i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

LL pmod(LL x,LL n,LL mod){
    LL ret = 1;
    while(n){
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return ret;
}

int main()
{
    LL n,x,y,s;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%I64d %I64d %I64d %I64d",&n,&y,&x,&s))
    {
        s++;
        LL ph = phi(s);
        LL tv = g(n*y,ph);
        printf("%I64d\n",pmod(x,tv+ph,s));
    }
    return 0;
}
```

