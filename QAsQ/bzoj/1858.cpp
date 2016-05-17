#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 112345;

struct Info{
    int v[2][4]; // lma max rma sum
    void maintain(int val){
        if(val<=1){
            int all = v[0][3]+v[1][3];
            for(int i=0;i<4;i++)
                v[1^val][i] = 0,v[val][i] = all;
        }
        else{
            for(int i=0;i<4;i++) swap(v[0][i],v[1][i]);
        }
    }
    void clear(){
        memset(v,0,sizeof(v));
    }
    void init(){
        memset(v,0,sizeof(v));
        for(int i=0;i<4;i++)
            v[0][i] = 1;
    }
    void out(){
        puts("----------------------st");
        for(int i=0;i<=1;i++){
            printf("%d : (ls %d ma %d rs %d) sum = %d\n",i,v[i][0],v[i][1],v[i][2],v[i][3]);
        }
        puts("-----------------------here");
    }
};

Info operator + (const Info & L,const Info & R){
    Info ret;
    ret.clear();
    for(int i=0;i<=1;i++){
        ret.v[i][3] = L.v[i][3] + R.v[i][3];
        ret.v[i][0] = L.v[i][0]; if(L.v[i^1][3]==0) ret.v[i][0] += R.v[i][0];
        ret.v[i][2] = R.v[i][2]; if(R.v[i^1][3]==0) ret.v[i][2] += L.v[i][2];
        ret.v[i][1] = max(L.v[i][1],R.v[i][1]);
        ret.v[i][1] = max(ret.v[i][1],L.v[i][2]+R.v[i][0]);
    }
    return ret;
}

#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define root 1,1,n
#define Now int o,int l,int r
#define Mid int m=l + (r-l)/2

Info val[maxn*4];
int lazy[maxn*4];

int chag(int x){
    if(x==-1) return 2;
    if(x<2) return x^1;
    return -1;
}

void push_down(Now){
    int v = lazy[o];
    lazy[o] = -1;
    if(l==r) return;
    val[o<<1].maintain(v);
    val[o<<1|1].maintain(v);
    if(v<=1){
        lazy[o<<1] = lazy[o<<1|1] = v;
    }
    else{
        lazy[o<<1] = chag(lazy[o<<1]);
        lazy[o<<1|1] = chag(lazy[o<<1|1]);
    }
}

void update(Now,int ul,int ur,int v){
    if(ul <= l && r <= ur){
        if(v<=1) lazy[o] = v;
        else     lazy[o] = chag(lazy[o]);
        val[o].maintain(v);
        return;
    }
    Mid;
    if(lazy[o]!=-1) push_down(o,l,r);
    if(ul <= m){
        update(lson,ul,ur,v);
    }
    if(m+1<=ur){
        update(rson,ul,ur,v);
    }
    val[o] = val[o<<1] + val[o<<1|1];
}

Info query(Now,int ql,int qr){
    if(ql <= l && r <= qr){
        return val[o];
    }
    Info ret;
    ret.clear();
    if(lazy[o]!=-1){
        push_down(o,l,r);
    }
    Mid;
    if(ql <= m)ret = query(lson,ql,qr) + ret;
    if(m+1<=qr)ret = ret + query(rson,ql,qr);
    return ret;
}

void buildtree(Now){
    if(l!=r){
        Mid;
        buildtree(lson);
        buildtree(rson);
        val[o] = val[o<<1] + val[o<<1|1];
    }
    else val[o].init();
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        int v;
        memset(lazy,-1,sizeof(lazy));
        buildtree(root);
        for(int i=1;i<=n;i++){
            scanf("%d",&v);
            update(root,i,i,v);
        }
        int l,r;
        while(m--){
            scanf("%d %d %d",&v,&l,&r);
            l++,r++;
            if(v<=2) update(root,l,r,v);
            else{
                if(v == 3) printf("%d\n",query(root,l,r).v[1][3]);
                else       printf("%d\n",query(root,l,r).v[1][1]);
            }
        }
    }
    return 0;
}
