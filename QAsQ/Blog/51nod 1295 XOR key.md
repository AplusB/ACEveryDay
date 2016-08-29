# 51nod 1295 XOR key

给出$n$个数$a_1,a_2...a_n(0\le a_i \le 10^9)$，$m$次询问

每次询问给出一个区间$[l,r]$和一个整数$x$,询问$\max\limits_{l\le i \le r} \{a_i \oplus a_i\}$

----

考虑不带区间询问的如何解决

我们可以将每个数按照从高位到低位插入到一个字典树中去，每次询问按照当前位在字典树上贪心即可

---

考虑本题每次询问的是一个区间的数，可以考虑用可持久数据结构解决

仿照主席树的做法，建立一个可持久字典树。

每次询问将$root_r ,root_{l-1}$这两个字典树相减，即可解决本题

---

代码也很简洁

```cpp
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
```

