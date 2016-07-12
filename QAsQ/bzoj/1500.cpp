#include<bits/stdc++.h>
using namespace std;

struct Info{
    int size;
    int lmax,rmax,sum,value;
    Info(int val = 0){
        size = 1;
        lmax = rmax = sum = value = val;
    }
    void setIt(int val){
        sum = val * size;
        value = lmax = rmax = max(val,sum);
    }
    void revIt(){
        swap(lmax,rmax);
    }
};

Info operator + (const Info & L,const Info & R){
    Info ret;
    ret.size = L.size + R.size;
    ret.sum = L.sum + R.sum;
    ret.lmax = max(L.lmax,L.sum+R.lmax);
    ret.rmax = max(R.rmax,R.sum+L.rmax);
    ret.value = max(max(L.value,R.value),L.rmax+R.lmax);
    return ret;
}


const int maxn = 552345;

struct Node{
    int son[2],fa;
    int v;
    int set, flp;
    bool lazy;
    Info info;
    int & l(){return son[0];}
    int & r(){return son[1];}
    Node(int val=0){
        l() = r() = fa = -1;
        v = val;
        info = Info(val);
        set = flp = 0;
        lazy = false;
    }
    void setIt(int val){
        v = val;
        set = val;
        lazy = true;
        info.setIt(val);
    }
    void revIt(){
        flp ^= 1;
        swap(l(),r());
        info.revIt();
    }
    void maintain();
    void push_down();
}node[maxn];

void Node::push_down(){
    if(lazy){
        if(l()!=-1) node[l()].setIt(set); 
        if(r()!=-1) node[r()].setIt(set); 
        set = 0;
        lazy = false;
    }
    if(flp){
        if(l()!=-1) node[l()].revIt();
        if(r()!=-1) node[r()].revIt();
        flp = 0;
    }
}

void Node::maintain(){
    info = Info(v);
    if(l()!=-1) info = node[l()].info + info;
    if(r()!=-1) info = info + node[r()].info;
}

int ori(int st){
    int fa = node[st].fa;
    if(fa==-1) return -1;
    return st == node[fa].r();
}

void setc(int st,int sn,int d){
    if(st != -1){
        node[st].son[d] = sn;
        node[st].maintain();
    }
    if(sn != -1) node[sn].fa = st;
}

void zg(int x){
    int st = node[x].fa,p = -1;

    node[st].push_down();
    node[x].push_down();

    int d = ori(x),dst = ori(st);
    if(st!=-1) p=node[st].fa;
    setc(st,node[x].son[d^1],d);
    setc(x,st,d^1);
    setc(p,x,dst);
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

int arr[maxn],nex[maxn];
int head,tail;

void init(){
    for(int i=0;i<maxn;i++){
        nex[i] = i+1;
    }
    head = 0,tail = maxn - 1;
    nex[tail] = -1;
}
int newNode(int v){
    int ret = head;
    head = nex[head];
    node[ret] = Node(v);
    return ret;
}
void deleteNode(int st){
    if(st == -1) return;
    deleteNode(node[st].l());
    deleteNode(node[st].r());
    nex[tail] = st;
    tail = st;
}

int build(int l,int r){
    if(l>r) return -1;
    int m = (l + r) >> 1;
    int st = newNode(arr[m]);
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

void segMaintain(int pos){
    node[node[root].l()].maintain();
    node[root].maintain();
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        char order[10];
        root = build(n);
        int pos,tot;
        int x;
        while(m--){
            scanf("%s",order);
            if(*order == 'I'){ //insert
                scanf("%d %d",&pos,&tot);
                if(tot==0) continue;
                for(int i=1;i<=tot;i++){
                    scanf("%d",&arr[i]);
                }
                int neo = build(1,tot); 
                int l = getid(pos+1,root),r = getid(pos+2,root);
                splay(r),splay(l,r);
                setc(l,neo,1);
                node[root].maintain();
            }
            else if(*order == 'M' && order[2] == 'X'){ //max sum
                int sizer = node[root].info.size-2;
                printf("%d\n",node[getseg(1,sizer)].info.value);
            }
            else{
                scanf("%d %d",&pos,&tot);
                pos = getseg(pos,pos+tot-1);
                if(*order == 'D'){ //delete
                    deleteNode(pos);
                    node[f(pos)].r()=-1;
                    segMaintain(pos);
                }
                if(*order == 'M'){ //make_same
                    scanf("%d",&x);
                    node[pos].setIt(x);
                    segMaintain(pos);
                }
                if(*order == 'R'){ //reverse
                    node[pos].revIt();
                    segMaintain(pos);
                }
                if(*order == 'G'){ //get_sum
                    if(tot == 0){
                        puts("0");
                        continue;
                   }
                    printf("%d\n",node[pos].info.sum);
                }
            }
        }
    }
    return 0;
}
