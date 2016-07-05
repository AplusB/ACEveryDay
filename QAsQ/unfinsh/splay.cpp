#include<bits/stdc++.h>
using namespace std;

struct Info{
    int mer;
    int size;
    Info(int m = 0){
        mer = m;
        size = 1;
    }
};

Info operator + (const Info & L,const Info & R){
    Info ret(max(L.mer,R.mer));
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
    Node(){
        l() = r() = -1;
        fa = -1;
    }
    void maintain();
}node[maxn];

void Node::maintain(){
    info = Info(v);
    if(l()!=-1) info = node[l()].info + info;
    if(r()!=-1) info = info + node[r()].info;
}

int ori(int st){
    int fa = node[st].fa;
    if(fa==-1) return -1;
    return st == node[fa].l();
}

void setc(int st,int sn,int d){
    if(st != -1){
        node[st].son[d] = sn;
        node[st].maintain();
    }
    if(sn != -1) node[sn].fa = d;
}

void zg(int x){
    int d = ori(x);
    int st = node[x].fa;
    setc(st,node[x].son[d^1],d);
    setc(x,st,d^1);
    setc(node[st].fa,x,ori(st));
}
