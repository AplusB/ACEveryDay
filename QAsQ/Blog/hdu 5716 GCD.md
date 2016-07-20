# hdu 5716 GCD

一句题面，询问区间GCD和区间GCD等于所询问的区间GCD的区间个数

---

区间GCD满足区间加法，所以线段树搞搞就好了

---

关于第二个询问，需要实现预处理GCD 为x的区间的个数

具体的，考虑固定左端点的情况，不难发现gcd是随着区间长度的增加而递减的，形象的来说就是一些线段（不妨设为(g,length),其中g代表的是左端点固定时候右端点在这个线段中时的区间gcd,length代表这个线段的长度），需要支持的操作是取出线段,更新线段的g,合并g相同的线段

考虑**从右往左枚举左端点**，不妨设新加入的左端点的值为v,对于现在的每一个线段的g都更新为 gcd(g,v)，并且另外加入一个(v,1)的线段，合并g相同的线段

----

大概就是这样，具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long 

const int maxn = 112345;

int arr[maxn];

map<int,LL> M;
map<int,int> seg,tseg;


void init(int n){
    M.clear();
    seg.clear(),tseg.clear();
    for(int st = n;st >= 1;st--){
        tseg.clear();
        for(auto x : seg){
            int gcd = x.first;
            tseg[__gcd(arr[st],gcd)]+=x.second;
        }
        seg = tseg;
        seg[arr[st]]++; 
        for(auto x : seg){
            M[x.first] += x.second;
        }
    }
}

int info[maxn*4];

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) / 2;

void init(Now){
    if(l == r){
        info[o] = arr[l];
        return;
    }
    Mid;
    init(lson),init(rson);
    info[o] = __gcd(info[o<<1],info[o<<1|1]);
}

int ql,qr,n;

int query(Now){
    if(ql <= l && r <= qr){
        return info[o];
    }
    Mid;
    int al = -1,ar = -1;
    if(ql <= m) al = query(lson);
    if(m+1<=qr) ar = query(rson);
    if(al == -1) return ar;
    if(ar == -1) return al;
    return __gcd(al,ar);
}

int query(int l,int r){
    ql = l,qr = r;
    return query(root);
}
int main(){
    int T,icase = 1;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init(n);
        init(root);
        int m,l,r;
        printf("Case #%d:",icase++);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&l,&r);
            int ans = query(l,r);
            printf("%d %I64d\n",ans,M[ans]);
        }
    }
    return 0;
}
```

