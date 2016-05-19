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
