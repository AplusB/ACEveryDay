区间每一个数开根
区间加x
区间求和

---
线段树，具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long

struct Info{
    LL same,siz,sum;
    Info(LL x = 0){
        same = sum = x;
        siz = x!=0;
    }
    void add(LL x){
        sum += siz * x;
        if(same != -1) same += x;
    }
    void sqr(){
        same = (LL)sqrt(same * 1.0);
        sum = same * siz;
    }   
    void set(LL x){
        same = x;
        sum = siz * x;
    }
};

Info operator + (const Info & L,const Info & R){
    Info ret;
    if(L.same == R.same) ret.same = L.same;
    else ret.same = -1;
    ret.siz = L.siz + R.siz;
    ret.sum = L.sum + R.sum;
    return ret;
}

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) / 2

const int maxn = 112345;
LL arr[maxn];
int n;
Info info[maxn*4];
LL lazy[maxn*4];

void seter(int o,LL v){
    lazy[o] += v;
    info[o].add(v);
}

void push_down(Now){
    if(l != r){
        if(info[o].same != -1){
            info[o<<1].set(info[o].same);
            info[o<<1|1].set(info[o].same);
            lazy[o<<1] = lazy[o<<1|1] = 0;
            lazy[o] = 0;
        }
        if(lazy[o]){
            seter(o<<1,lazy[o]);
            seter(o<<1|1,lazy[o]);
        }
    }
    lazy[o] = 0;
}

void add(Now,int ul,int ur,LL v){
    if(ul <= l && r <= ur){
        info[o].add(v);
        lazy[o] += v;
        return;
    }
    Mid;
    if(lazy[o] || info[o].same != -1) push_down(o,l,r);
    if(ul <= m) add(lson,ul,ur,v);
    if(m+1<=ur) add(rson,ul,ur,v);
    info[o] = info[o<<1] + info[o<<1|1];
}

void sqrt(Now,int ul,int ur){
    if(ul <= l && r <= ur && info[o].same != -1){
        info[o].sqr();
        return;
    }
    Mid;
    if(lazy[o] || info[o].same != -1) push_down(o,l,r);
    if(ul <= m) sqrt(lson,ul,ur);
    if(m+1<=ur) sqrt(rson,ul,ur);
    info[o] = info[o<<1] + info[o<<1|1];
}

Info query(Now,int ql,int qr){
    if(ql <= l && r <= qr){
        return info[o];
    }
    Mid;
    if(lazy[o] || info[o].same != -1) push_down(o,l,r);
    Info ret;
    if(ql <= m) ret = ret + query(lson,ql,qr);
    if(m+1<=qr) ret = ret + query(rson,ql,qr);
    return ret;
}

void build(Now){
    if(l != r){
        Mid;
        build(lson),build(rson);
        info[o] = info[o<<1] + info[o<<1|1];
    }
    else{
        info[o] = Info(arr[l]);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&arr[i]);
        }
        build(root);
        memset(lazy,0,sizeof(lazy));
        int ord,l,r;
        LL x;
        while(m--){
            scanf("%d %d %d",&ord,&l,&r);
            if(ord == 1){
                scanf("%I64d",&x);
                add(root,l,r,x);
            }
            if(ord == 2) sqrt(root,l,r);
            if(ord == 3) printf("%I64d\n",query(root,l,r).sum);
        }
    }
    return 0;
}
```

