#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 112345;
const int mod = 10007;

struct Info{
    LL s[3];
    LL siz;
    void maintain(LL a,LL b){
        (s[2] *= (a*a*a)  %mod       ) %= mod;
        (s[2] += (3*a*a*b)%mod * s[1]) %= mod;
        (s[2] += (3*a*b*b)%mod * s[0]) %= mod;
        (s[2] += (b*b*b)  %mod * siz ) %= mod;

        (s[1] *= (a*a)    %mod       ) %= mod;
        (s[1] += (2*a*b)  %mod * s[0]) %= mod;
        (s[1] += (b*b)    %mod * siz ) %= mod;

        (s[0] *= a        %mod       ) %= mod;
        (s[0] += b        %mod * siz ) %= mod;
    }
    void maintain(LL c){
        LL x = c;
        for(int i=0;i<3;i++){
            s[i] = (siz * x) % mod;
            (x *= c ) %= mod;
        }
    }
    void clear(){
        memset(s,0,sizeof(s));
        siz = 0;
    }
    void init(LL S){
        clear();
        siz = S;
    }
    void out(){
        printf("siz = %lld\n",siz);
        printf("1:%lld 2:%lld 3:%lld\n",s[0],s[1],s[2]);
        puts("--");
    }
};

Info operator + (const Info &L,const Info &R){
    Info ret;
    ret.init(L.siz + R.siz);
    for(int i=0;i<3;i++){
        ret.s[i] = (L.s[i] + R.s[i]) % mod;
    }
    return ret;
}

LL la[maxn*4],lb[maxn*4];
LL lc[maxn*4];
Info info[maxn*4];

bool inier(int o){
    return la[o] == 1 && lb[o] == 0;
}

void lmaintain(int o,LL a,LL b){
    (la[o] *= a ) %= mod;
    (lb[o] *= a ) %= mod;
    (lb[o] += b ) %= mod;
}

void lclear(int o){
    la[o] = 1,lb[o] = 0;
}

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Mid int m = (l+r)/2
#define Now int o,int l,int r

void buildtree(Now){
    la[o] = 1,lb[o] = 0,lc[o] = -1;
    info[o].init(r-l+1);
    Mid;
    if(l != r){
        buildtree(lson);
        buildtree(rson);
    }
}
void push_downc(Now){
    LL v = lc[o];
    lc[o] = -1;
    if(l != r){
        info[o<<1].maintain(v);   lclear(o<<1);
        info[o<<1|1].maintain(v); lclear(o<<1|1);
        lc[o<<1] = lc[o<<1|1] = v;
    }
}

void push_down(Now){
    if(l!=r){
       info[o<<1].maintain(la[o],lb[o]);
       info[o<<1|1].maintain(la[o],lb[o]);
       lmaintain(o<<1,la[o],lb[o]);
       lmaintain(o<<1|1,la[o],lb[o]);
    }
    lclear(o);
}

void update(Now,int ul,int ur,LL a,LL b){
    if(ul<=l && r<=ur){
        info[o].maintain(a,b);
        lmaintain(o,a,b);
        return;
    }
    Mid;
    if(lc[o] != -1) push_downc(o,l,r);
    if(!inier(o))   push_down(o,l,r);
    if(ul <=m )   update(lson,ul,ur,a,b);
    if(m+1<=ur)   update(rson,ul,ur,a,b);
    info[o] = info[o<<1] + info[o<<1|1];
//    printf("update :: o l r = %d %d %d\n",o,l,r);
//    info[o].out();
}



void update(Now,int ul,int ur,LL c){
    if(ul <= l && r <= ur){
        info[o].maintain(c);
        lc[o] = c;
        lclear(o);
        return;
    }
    Mid;
    if(lc[o] != -1) push_downc(o,l,r);
    if(!inier(o))   push_down(o,l,r);
    if(ul  <= m)  update(lson,ul,ur,c);
    if(m+1 <= ur) update(rson,ul,ur,c);
    info[o] = info[o<<1] + info[o<<1|1];
//    printf("update C olr %d %d %d\n",o,l,r);
//    info[o].out();
}

Info query(Now,int ql,int qr){
//    printf("que :: olr = %d %d %d\n",o,l,r);
//    info[o].out();
    if(ql <= l && r <= qr){
        return info[o];
    }
    Info ret;
    ret.clear();
    Mid;
    if(lc[o] != -1) push_downc(o,l,r);
    if(!inier(o))    push_down(o,l,r);
    if(ql <= m) ret = query(lson,ql,qr) + ret;
    if(m+1<=qr) ret = ret + query(rson,ql,qr);
//    ret.out();
    return ret;
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        buildtree(root);
        int l,r,op,c;
        while(m--){
            scanf("%d %d %d %d",&op,&l,&r,&c);
            switch(op){
                case 1:
                    update(root,l,r,1,c);
                    break;
                case 2:
                    update(root,l,r,c,0);
                    break;
                case 3:
                    update(root,l,r,c);
                    break;
                case 4:
                    printf("%lld\n",query(root,l,r).s[c-1]);
                    break;
            }
        }
    }
    return 0;
}



