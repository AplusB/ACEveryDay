#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Info{
    int st,size;
    Info(int x = 0){
        size = 1,st = x;
    }
};

Info operator + (const Info & L,const Info & R){
    Info ret(max(L.st,R.st - L.size));
    ret.size = L.size + R.size;
    return ret;
}

const int maxn = 112345;

struct Node{
    int son[2],fa;
    int v;
    Info info;
    int & l(){return son[0];}
    int & r(){return son[1];}
    Node(int Val=0){
        l() = r() = fa = -1;
        v = Val;
        info = Info(Val);
    }
    void maintain();
}node[maxn];

void Node::maintain(){
    info = Info(v);
    if(l()!=-1) info = node[l()].info + info;
    if(r()!=-1) info = info + node[r()].info;
}
void setc(int st,int sn,int d){
    if(st != -1){
        node[st].son[d] = sn;
        node[st].maintain();
    }
    if(sn != -1) node[sn].fa = st;
}
int ori(int st){
    int fa = node[st].fa;
    if(fa==-1) return -1;
    return st == node[fa].r();
}
void zg(int x){
    int st = node[x].fa,p = -1;
    int d = ori(x),dst = ori(st);
    if(st!=-1) p=node[st].fa;

    setc(st,node[x].son[d^1],d);
    setc(x,         st    ,d^1);
    setc(p,         x     ,dst);
}

#define f(x) (node[x].fa)
void splay(int x,int &root,int fa=-1){
    while(f(x) != fa){
        if(f(f(x)) == fa) zg(x);
        else{
           if(ori(x)==ori(f(x))) zg(f(x));
           else zg(x);
           zg(x);
        }
    }
    if(fa==-1) root = x;
}

int input[maxn],_cnt;
int newNode(int v){
    node[_cnt] = Node(v);
    return _cnt++;
}
int build(int l,int r){
    if(l>r) return -1;
    int m = (l + r) >> 1;
    int st = newNode(input[m]);
    setc(st,build(l,m-1),0);
    setc(st,build(m+1,r),1);
    return st;
}
int build(int n){
    return build(0,n+1);
}
int getid(int v,int st){
    int l = node[st].l();
    int lsize = 1 + (l==-1?0:node[l].info.size);
    if(v == lsize) return st;
    int d = v > lsize;
    if(d) v -= lsize;
    return getid(v,node[st].son[d]);
}
int getseg(int l,int r,int &root){
    l--,r++;
    l = getid(l+1,root),r = getid(r+1,root);
    splay(r,root),splay(l,root,r);
    return node[l].r();
}

Info info[maxn];

int root[maxn];
#define L(x) (node[x].l())
Info getinfo(int &root){
    int st = getseg(1,node[root].info.size-2,root);
    return node[st].info;
}

void swaper(int x,int a,int y,int b,int n){
    int ax = getseg(1,a,root[x]);
    int by = getseg(1,b,root[y]);
    setc(L(root[y]),ax,1);
    setc(L(root[x]),by,1);
    node[root[x]].maintain();
    node[root[y]].maintain();
    for(int i=1;i<=n;i++){
        info[i-1] = getinfo(root[i]);
    }
    sort(info,info+n,[](Info a,Info b){return a.st < b.st;});
    for(int i=1;i<n;i++){
        info[0] = info[0] + info[i];
    }
}


int main(){
    int n;
    while(~scanf("%d",&n)){
        int len;
        _cnt =  0;
        for(int k=1;k<=n;k++){
            scanf("%d",&len);
            for(int i=1;i<=len;i++){
                scanf("%d",&input[i]);
            }
            root[k] = build(len);
        }
        scanf("%d",&len);
        while(len--){
            int x,y,a,b;
            scanf("%d %d %d %d",&x,&a,&y,&b);
            swaper(x,a,y,b,n);
            printf("%d\n",info[0].st);
        }
    }
    return 0;
}
