struct Info{
    int size;
    Info(int val = 0){ size = 1;
        // info upd
    }
    void setIt(int val){
        //info maintiain
    }
};
Info operator + (const Info & L,const Info & R){
    Info ret; ret.size = L.size + R.size;
    // info maintain
    return ret;
}

const int maxn = 552345;
struct Node{
    int son[2],fa;
    int v; Info info;
    int set,lazy;
    int & l(){return son[0];}
    int & r(){return son[1];}
    Node(int Val=0){
        l() = r() = fa = -1;
        v = Val;
        info = Info(Val);
        set = lazy = 0;
    }
    void setIt(int Val){
        v = Val;
        set = Val;
        lazy = true;
        info.setIt(Val);
    }
    void maintain();
    void push_down();
}node[maxn];
void Node::push_down(){
    if(lazy){
        if(l()!=-1) node[l()].setIt(set);
        if(r()!=-1) node[r()].setIt(set);
        lazy = false;
    }
}
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
    node[st].push_down();
    node[ x].push_down();
    int d = ori(x),dst = ori(st);
    if(st!=-1) p=node[st].fa;

    setc(st,node[x].son[d^1],d);
    setc(x,         st    ,d^1);
    setc(p,         x     ,dst);
}
int root;
#define f(x) (node[x].fa)
void splay(int x,int fa=-1){
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
int build(int l,int r){
    if(l>r) return -1;
    int m = (l + r) >> 1;
    int st = newNode( 0 ); //init value
    setc(st,build(l,m-1),0);
    setc(st,build(m+1,r),1);
    return st;
}
int build(int n){
    return build(0,n+1);
}
int getid(int v,int st){
    node[st].push_down();
    int l = node[st].l();
    int lsize = 1 + (l==-1?0:node[l].info.size);
    if(v == lsize) return st;
    int d = v > lsize;
    if(d) v -= lsize;
    return getid(v,node[st].son[d]);
}
int getseg(int l,int r){
    l--,r++;
    l = getid(l+1,root),r = getid(r+1,root);
    splay(r),splay(l,r);
    return node[l].r();
}
