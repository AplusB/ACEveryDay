# hdu 4288 Coder

线段树

单点更新，查询总的区间下标$\pmod{5}=3$的数的和



先离散化一下

然后每个区间存一下这个区间下标$\pmod{5}=k(0\le k\le5)$的数的和，这个区间数的个数

区间合并的时候考虑左区间数的个数然后怼起来就好了，具体见代码 



```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 112345;

struct Info{
    LL v[5];
    int siz;
    void init(LL val){
        memset(v,0,sizeof(v));
        siz = 1;
        v[0] = val;
    }
    void clear(){
        memset(v,0,sizeof(v));
        siz = 0;
    }
    void out(){
        printf("siz = %d\n",siz);
        for(int i=0;i<5;i++){
            printf(i<4?"%lld ":"%lld\n",v[i]);
        }
    }
};

Info operator + (const Info &L,const Info &R){
    Info ret = L;
    int offset = L.siz % 5;
    for(int i=0;i<5;i++){
        ret.v[i] += R.v[(i+offset)%5];
    }
    ret.siz += R.siz;
    return ret;
}

Info info[maxn*4];

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Mid int m = (l+r)/2
#define Now int o,int l,int r

LL msp[maxn];
void update(Now,int pos,int op){
    if(l==r){
        if(op)
            info[o].init(msp[pos]);
        else
            info[o].clear();
        return;
    }
    Mid;
    if(pos <=   m) update(lson,pos,op);
    else           update(rson,pos,op);
    info[o] = info[o<<1] + info[o<<1|1];
}

int oper[maxn];
LL val[maxn];

int main(){
    int m;
    while(~scanf("%d",&m)){
        char ord[5];
        int n = 0;
        for(int i=0;i<m;i++){
            scanf("%s",ord);
            if(*ord == 's'){
                oper[i] = 2;
            }
            else{
                oper[i] = *ord=='a' ? 1 : 0;
                scanf("%I64d",&val[i]);
                msp[n++] = val[i];
            }
        }
        msp[n++] = -1;
        sort(msp,msp+n);
        n = unique(msp,msp+n)-msp;
        for(int i=1;i<=n;i++){
            update(root,i,0);
        }
        for(int i=0;i<m;i++){
            if(oper[i] == 2){
                printf("%I64d\n",info[1].v[3]);
            }
            else{
                int st = lower_bound(msp,msp+n,val[i])-msp;
                update(root,st,oper[i]);
            }
        }
    }
    return 0;
}
```

