#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const int maxn = 5123;

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l+r)/2

int info[maxn*4];

void update(Now,int pos,int v){
    if(l==r){
        info[o] = min(v,info[o]);
        return;
    }
    Mid;
    if(pos <= m) update(lson,pos,v);
    else         update(rson,pos,v);
    info[o] = min(info[o<<1],info[o<<1|1]);
}

int query(Now,int ql,int qr){
    if(ql == 0) return 0;
    if(ql <= l && r <= qr){
        return info[o];
    }
    Mid;
    int ret = INF;
    if(ql <= m) ret = min(ret,query(lson,ql,qr));
    if(m+1<=qr) ret = min(ret,query(rson,ql,qr));
    return ret;
}

void sinit(){
    memset(info,0x3f,sizeof(info));
}

struct Seg{
    int l,r;
    void init(int l,int r):l(l),r(r){}
}

Seg seg[112345];

bool cmp(Seg a,Seg b){
    return a.r < b.r;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        int len = 0;
        sinit();
        int l,r;
        while(~scanf("%d %d",&l,&r) && (l||r)){
            l = max(l+1,1),r = min(r,m);
            if(l<=r){
                seg[len++].init(l,r);
            }
        }
        sort(seg,seg+len,cmp);
        for(int i=0;i<len;i++){
            update(root,seg[i].r,query(root,seg[i].l,



        }
        int ans = query(root,n,n);
        if(ans == INF){
            puts("
