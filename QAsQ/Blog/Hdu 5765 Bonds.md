# Hdu 5765 Bonds

丢[链接](https://async.icpc-camp.org/d/500-2016-multi-university-training-contest-c-bonds)

---

$check(mask)$就是用$bfs$的方式来检查$mask$是否联通

具体的，$done$ 是已经访问过的点集，$did$是可以访问的点集

首先找一个$mask$的点$start$加到$did$里

显然$done$是$did$的子集，每一次找到一个在$did$中并且不在$done$中的点$st$，把和st直接联通的在$mask$中的点加到$did$里面，把$st$加到$done$里面，最后的$done$就是和$start$联通的点集了

---

位运算大法好~

```CPP
#include<bits/stdc++.h>
using namespace std;

const int bit = 22;
const int maxn = 1<<bit;

int l[bit*bit],r[bit*bit];
int edge[bit];
int rev[maxn];

int cnt[maxn];
int lowbit(int x){
    return x & (-x);
}

bool check(int S){
    int done = 0;
    int did = lowbit(S);
    while(rev[lowbit(did^done)] != -1){
        int st = rev[lowbit(did ^ done)];
        done |= 1<<st;
        did |= edge[st] & S;
    }
    return done == S;
}

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    int icase = 1;
    memset(rev,-1,sizeof(rev));
    for(int i=0;i<bit;i++) rev[1<<i] = i;
    while(T-- && ~scanf("%d %d",&n,&m)){
        memset(edge,0,sizeof(edge));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++){
            scanf("%d %d",&l[i],&r[i]);
            edge[l[i]] |= 1<<r[i];
            edge[r[i]] |= 1<<l[i];
        }
        int bnd = (1<<n) - 1;
        int all = 0;
        for(int i=1;i<bnd;i++){
            if((i&1) && check(i) && check(bnd ^ i)){
                cnt[i]++,cnt[bnd^i]++;
                all++;
            }
        }
        for(int i=1;i<=bnd;i<<=1){
            for(int j=0;j<=bnd;j++){
                if(i&j)
                    cnt[i^j] += cnt[j];
            }
        }
        printf("Case #%d:",icase++);
        for(int i=0;i<m;i++){
            printf(" %d",all - cnt[(1<<l[i])|(1<<r[i])]);
        }
        puts("");
    }
    return 0;
```

