#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define LL long long

const LL INFF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 112345;

vector<int> edge[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

int tid[maxn],_cnt,siz[maxn];
LL sum[maxn],nod[maxn];

void dfs(int st,int fa,LL lef){
    tid[st] = _cnt++;
    lef += nod[st],siz[st] = 1;
    sum[st] = lef;
    for(auto & x : edge[st]){
        if(x != fa){
            dfs(x,st,lef);
            siz[st] += siz[x];
        }
    }
}

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l+r)/2

LL info[maxn*4],lazy[maxn*4];

void push_down(Now){
    LL v = lazy[o];
    lazy[o] = 0;
    if(l!=r){
        info[o<<1]+=v,info[o<<1|1]+=v;
        lazy[o<<1]+=v,lazy[o<<1|1]+=v;
    }
}

void update(Now,int ul,int ur,int v){
    if(ul <= l && r <= ur){
        info[o] += v,lazy[o] += v;
        return;
    }
    if(lazy[o]) push_down(o,l,r);
    Mid;
    if(ul <= m) update(lson,ul,ur,v);
    if(m+1<=ur) update(rson,ul,ur,v);
    info[o] = max(info[o<<1],info[o<<1|1]);
}

LL query(Now,int ql,int qr){
    if(ql <= l && r <= qr){
        return info[o];
    }
    if(lazy[o]) push_down(o,l,r);
    LL ret = -INFF;
    Mid;
    if(ql <= m) ret = max(ret,query(lson,ql,qr));
    if(m+1<=qr) ret = max(ret,query(rson,ql,qr));
    return ret;
}

void sinit(){
    memset(lazy,0,sizeof(lazy));
    memset(info,0,sizeof(info));
}

int n;
LL nodev[maxn];

void update(int x,LL v){
    LL dif = v - nodev[x];
    update(root,tid[x],tid[x]+siz[x]-1,dif);
    nodev[x] = v;
}

LL query(int x){
    return query(root,tid[x],tid[x]+siz[x]-1);
}

int main(){
    int T,m;
    scanf("%d",&T);
    int icase = 1;
    while(T-- && ~scanf("%d %d",&n,&m)){
        init(n);
        int x,y;
        for(int i=1;i<n;i++){
            scanf("%d %d",&x,&y);
            x++,y++;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        _cnt = 1;
        for(int i=1;i<=n;i++)
            scanf("%I64d",&nod[i]);
        dfs(1,0,0);
//        for(int i=1;i<=n;i++){
//            printf(i<n?"%d ":"%d\n",siz[i]);
//        }
//        for(int i=1;i<=n;i++){
//            printf(i<n?"%d ":"%d\n",tid[i]);
//        }
        sinit();
        memset(nodev,0,sizeof(nodev));
        for(int i=1;i<=n;i++){
            update(root,tid[i],tid[i],sum[i]);
            nodev[i] = nod[i];
        }
//        for(int i=1;i<=n;i++){
//            printf(i<n?"%lld ":"%lld\n",query(root,tid[i],tid[i]));
//        }
        printf("Case #%d:\n",icase++);
        int ord,pos;
        LL v;
        while(m--){
            scanf("%d",&ord);
            if(ord){
                scanf("%d",&pos);
                pos++;
                printf("%I64d\n",query(pos));
            }
            else{
                scanf("%d %I64d",&pos,&v);
                pos++;
                update(pos,v);
            }
//            printf("los = %d %d\n",tid[pos],tid[pos]+siz[pos]-1);
        }
    }
    return 0;
}


