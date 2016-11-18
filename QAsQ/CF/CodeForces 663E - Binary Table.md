# CodeForces 663E - Binary Table

给出一个$n(n \le 20)$行$m(m\le 10^5)$列的$01$矩阵。每次操作可以将某一行取反或者将某一列取反。要求操作后的矩阵中的$1$的个数最少，求最小个数。

---

因为行比较少，我们考虑状压。

状压每一列的状态，$sta$第$i$位为$1$表示第$i$行为$1$，为$0$表示第$i$行为$1$

用一个函数$F(sta)$表示状态为$sta$的列的数量

考虑状压我们操作了哪些行，$mask$第$i$位为$1$表示我们翻转了第$i$行，为$0$表示没有翻转第$i$行

考虑一个$mask$对$sta$的影响，显然操作后的结果为$mask \oplus  sta$，不妨记为$res$。

然后对一个$res$，我们可以直接计算这一列的$1$的个数和取反后$1$的个数并且选择一个比较小的作为结果。

不妨预处理出来一个函数$G(res)$表示$res$这样的一列在翻至多一次之后的最小的$1$的个数

对于$m$有$10^5$,我们考虑优化一下

构造一个函数$H(mask)$，表示操作为mask的时候$1$的个数。不难想到$H(mask) = \sum\limits_{sta=0}^{2^n-1} F(sta) \times G(sta \oplus mask)$

这个看起来好像不是很好优化，我们换一种写法
$H(mask) = \sum\limits_{sta=0}^{2^n-1}\sum\limits_{res=0}^{2^n-1} [sta \oplus mask = res]F(sta) \times G(res)$

因为异或的一些优良的性质，我们也可以写成

$H(mask) = \sum\limits_{sta=0}^{2^n-1}\sum\limits_{res=0}^{2^n-1} [sta \oplus res= mask]F(sta) \times G(res)$

这不就是异或卷积嘛(╯‵□′)╯︵┻━┻

然后就做完了

----

具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

void fwt (LL a[] , int n ,bool on) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                if(on){
                    a[i + j] = ( x + y )  ;
                    a[i + j + d] = ( x - y  )  ;
                }
                else{
                    a[i + j] = ( x + y ) / 2 ;
                    a[i + j + d] = ( x - y ) / 2;
                }
            }
        }
    }
}

char inp[22][maxn];
int arr[maxn];
LL A[1<<22],B[1<<22];

int getone(int x,int n){
    int ret = 0 ;
    while(x){
        ret += x & 1;
        x >>= 1;
    }
    return min(ret,n - ret);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n; i ++) scanf("%s",inp[i]);
    for(int i = 0 ; i < m ; i++){
        arr[i] = 0;
        for(int j = 0 ; j < n ; j ++){
            arr[i] |= (inp[j][i] - '0') << j;
        }
    }
    memset(A,0,sizeof(A));
    for(int i = 0 ; i < m ; i++) A[arr[i]] ++;
    for(int i = 0 ; i < (1<<n) ; i ++){
        B[i] = getone(i,n);
    }
    fwt(A,1<<n,true);
    fwt(B,1<<n,true);
    for(int i = 0; i < (1<<n);i++) A[i] *= B[i];
    fwt(A,1<<n,false);
    LL ans = INFF;
    for(int i = 0 ; i < (1<<n);i++) ans = min(ans,A[i]);
    printf("%I64d\n",ans);
    return 0;
}
```

