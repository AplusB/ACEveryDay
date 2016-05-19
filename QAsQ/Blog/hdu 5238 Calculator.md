# hdu 5238 Calculator

某线段树

打模拟赛的时候不知道区间该维护什么东西使其变得可合并，然后就放着了

赛后看了题解才知道这个题维护的是映射关系，感觉也是十分的厉害



考虑一个算式$a  + 4 \pmod{7} = b$

我们发现来$\pmod{7}$的同余系中，会有以下对应关系



其实这就是一个映射

具体的，保存这个映射可以直接开一个数组$a[7],其中a[i] = (i+4)  \pmod{7}$



-----

我们现在已经能把一个算式对应成一个映射了，那么如果我们能计算出两个映射的复合，就可以用线段树解决本题了，不妨设$f(x),g(x)$是我们需要复合的映射

那么复合的结果就是$g(f(x))$

：一个$x$过来经过$f$变成了$c$,然后$c$进到了$g$里面去出来就是$x$经过这个复合的映射的结果

------

理论基础大概就这些，但是如果直接做的话空间复杂度是$O(29393\times n\times 4)$

显然是吃不消的

如果能注意到这题的$mod$不是$1e9+7$,$1e9+7$，而是一个奇怪的数

而且不是素数,$29393 =7 \times 13 \times 17 \times 19$

四个不相同的素数的乘积，是不是很巧合

聪明的你有没有想到用中国剩余定理来减少运算量呢？

用CRT优化之后，这个题的空间复杂度变成了$O((7+13+17+19)\times n\times 4)$

已经可以解决这个问题了o(` • ~ • ′。)o 

------

最后一点是关于代码的

因为需要四个线段树，为了方便我定义了结构体

-----

其它地方如果有不懂的，希望给窝留言，窝会更新一发博客



那么就酱(⊙v⊙)

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 51234;

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l+r)/2

int pmod(int a,int n,int mod){
    a %= mod;
    int ret = 1;
    while(n){
        if(n&1) (ret *= a) %= mod;
        (a *= a) %= mod;
        n>>=1;
    }
    return ret;
}

struct segtree{
    int v[maxn*4][30];
    int mod;
    void clean(int *s){
        for(int i=0;i<mod;i++){
            s[i] = i;
        }
    }
    void init(int val){
        mod = val;
    }
    void add(int o){
        int l = o<<1,r = o<<1|1;
        for(int i=0;i<mod;i++){
            v[o][i] = v[r][ v[l][i] ];
        }
    }
    void update(int o,char oper,int num){ //[+,*,^]
        int *s = v[o];
        if(oper=='+') for(int i=0;i<mod;i++) s[i] = (i+num)%mod;
        if(oper=='*') for(int i=0;i<mod;i++) s[i] = (i*num)%mod;
        if(oper=='^') for(int i=0;i<mod;i++) s[i] = pmod(i,num,mod);
    }
    void update(Now,int pos,char oper,int num){
        if(l==r){
            update(o,oper,num);
            return;
        }
        Mid;
        if(pos <= m) update(lson,pos,oper,num);
        else update(rson,pos,oper,num);
        add(o);
    }
    int query(int x){
        x %= mod;
        return v[1][x];
    }
};

struct allseg{
    segtree sg[4];
    int v[4]={7,13,17,19};
    int coe[4] = {25194,27132,17290,18564};
    int M = 29393;
    allseg(){
        for(int i=0;i<4;i++)
            sg[i].init(v[i]);
    }
    int n;
    void init(int N){
        n = N;
    }
    void update(int pos,char oper,int x){
        for(int i=0;i<4;i++)
            sg[i].update(root,pos,oper,x);
    }
    int query(int x){
        int ans = 0;
        for(int i=0;i<4;i++){
            (ans += coe[i] * sg[i].query(x) )%= M;
        }
        int ret = 0;
        return ans;
    }
};

allseg S;

int getnum(char *s){
    int ret = 0;
    while(*s){
        ret = ret * 10 + (*s-'0');
        s++;
    }
    return ret;
}

int main()
{
    int T,icase = 1;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        S.init(n);
        char op[10];
        for(int i=1;i<=n;i++){
            scanf("%s",op);
            S.update(i,*op,getnum(op+1));
        }
        int ord,x;
        printf("Case #%d:\n",icase++);
        while(m--){
            scanf("%d",&ord);
            if(ord == 1){
                scanf("%d",&x);
                printf("%d\n",S.query(x));
            }
            else{
                scanf("%d",&x);
                scanf("%s",op);
                S.update(x,*op,getnum(op+1));
            }
        }
    }
    return 0;
}
```

