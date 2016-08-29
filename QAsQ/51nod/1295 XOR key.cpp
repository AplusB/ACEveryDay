#include<bits/stdc++.h>
using namespace std;

const int maxn = 51234,bnd = 32;

struct Node{
    int cnt,son[2];
}node[maxn*bnd*2];
int _cnt,root[maxn];

int newnode(){ 
    node[_cnt].cnt= 0;
    node[_cnt].son[0] = node[_cnt].son[1] = -1;
    return _cnt++; 
}
void init(){ _cnt = 0; root[0] = newnode(); }

int arr[maxn],num[bnd];
void ins(int x){ 
    for(int i=0;i<bnd;i++) 
        num[i] = (x>>i) & 1;
    reverse(num,num+bnd);
}

int inser(int o,int pos){
    if(pos > bnd) return -1;
    int st = newnode();
    node[st].cnt = node[o].cnt+1;
    node[st].son[num[pos]^1] = node[o].son[num[pos]^1];
    node[st].son[num[pos]] = inser(node[o].son[num[pos]],pos+1);
    return st;
}

void build(int n){
    for(int i=1;i<=n;i++){
        ins(arr[i]); 
        root[i] = inser(root[i-1],0);
    }
}

int ans;

int gcnt(int st,int p){
    if(st == -1 || node[st].son[p] == -1) return 0;
    return node[node[st].son[p]].cnt;
}
int gnex(int st,int p){
    if(st == -1) return -1;
    return node[st].son[p];
}
void query(int pos,int l,int r){
    if(pos >= bnd) return;
    int nex = 1 ^ num[pos];
    if(gcnt(r,nex) - gcnt(l,nex) == 0)
        nex ^= 1;
    ans = ans * 2 + (nex ^ num[pos]);
    query(pos+1,gnex(l,nex),gnex(r,nex));
}

int que(int v,int l,int r){
    ins(v);
    ans = 0;
    query(0,l,r);
    return ans;
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        init();
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        build(n);
        int l,r,x;
        while(m--){
            scanf("%d %d %d",&x,&l,&r);
            l++,r++;
            printf("%d\n",que(x,root[l-1],root[r]));
        }
    }
    return 0;
}
