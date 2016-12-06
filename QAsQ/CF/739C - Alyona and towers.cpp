#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;
#define LL long long 
struct Info{
    LL lv,rv;
    int siz;
    int lu,ld,ru,rd,lud,rud;
    int ma;
    Info(LL v = 0){
        siz = ma = lu = ld = ru = rd = 1;
        lud = rud = 0;
        lv = rv = v;
    }
    int lma(){ return max(lud,max(lu,ld)); }
    int rma(){ return max(rud,max(ru,rd)); }
    void upd(LL v){
        lv += v,rv += v;
    }
    void out(){
        printf("(%I64d %I64d) siz = %d luld = %d %d rurd = %d %d lrud = %d %d ma = %d\n"
                ,lv,rv,siz,lu,ld,ru,rd,lud,rud,ma);
    }
};

Info info[maxn * 4];
LL lazy[maxn * 4];

Info operator + (const Info & L,const Info & R){
    Info ret;
    ret.siz = L.siz + R.siz;
    ret.lv = L.lv,ret.rv = R.rv;
    LL lv = L.rv,rv = R.lv;

    ret.lu = L.lu + (lv < rv && L.lu == L.siz) * R.lu; 
    ret.ru = R.ru + (lv < rv && R.ru == R.siz) * L.ru; 

    ret.ld = L.ld + (lv > rv && L.ld == L.siz) * R.ld; 
    ret.rd = R.rd + (lv > rv && R.rd == R.siz) * L.rd; 

    ret.lud = L.lud , ret.rud = R.rud;

    ret.lud = max(ret.lud,(lv < rv && L.lu == L.siz && R.lud) * (L.lu + R.lud));
    ret.rud = max(ret.rud,(lv > rv && R.rd == R.siz && L.rud) * (L.rud + R.rd));

    ret.lud = max(ret.lud,(lv > rv && L.lud == L.siz) * (L.lud + R.ld));
    ret.rud = max(ret.rud,(lv < rv && R.rud == R.siz) * (L.ru + R.rud));

    ret.lud = max(ret.lud,(L.lu == L.siz) * ((lv < rv && R.ld != 1) || lv > rv) * (L.lu + R.ld));
    ret.rud = max(ret.rud,(R.rd == R.siz) * ((lv > rv && L.ru != 1) || lv < rv) * (L.ru + R.rd));

    ret.ma = max(L.ma,R.ma);
    ret.ma = max(ret.ma,max(max(ret.lu,ret.ld),max(ret.ru,ret.rd)));
    ret.ma = max(ret.ma,max(ret.lud,ret.rud));
    ret.ma = max(ret.ma,(lv != rv) * (L.ru + R.ld));
    ret.ma = max(ret.ma,(lv < rv) * (L.ru + max(R.lud,R.lu)));
    ret.ma = max(ret.ma,(lv > rv) * (max(L.rd,L.rud) + R.ld));
    return ret;
}

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) / 2

void push_down(Now){
    if(l != r){
        lazy[o<<1] += lazy[o], info[o<<1].upd(lazy[o]);
        lazy[o<<1|1] += lazy[o], info[o<<1|1].upd(lazy[o]);
    }
    lazy[o] = 0;
}

void update(Now,int ul,int ur,LL x){
    if(ul <= l && r <= ur){
        lazy[o] += x;
        info[o].upd(x);
        return;
    }
    Mid;
    if(lazy[o]) push_down(o,l,r);
    if(ul <= m) update(lson,ul,ur,x);
    if(m+1<=ur) update(rson,ul,ur,x);
    info[o] = info[o<<1] + info[o<<1|1];
}

void out(Now){
    if(l != r){
        Mid;
        out(lson),out(rson);
    }
    printf("___________________\n_______________[%d,%d]\n",l,r);
    info[o].out();
}
int main(){
    int n,m;
    scanf("%d",&n);
    memset(lazy,0,sizeof(lazy));
    LL x;
    for(int i = 1 ;i <= n; i ++){
        scanf("%I64d",&x);
        update(root,i,i,x);
    }
    //out(root);
    scanf("%d",&m);
    int l,r;
    while(m--){
        scanf("%d %d %I64d",&l,&r,&x);
        update(root,l,r,x);
        printf("%d\n",info[1].ma);
    }
    return 0;
}
