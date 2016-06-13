# Ural 1303 Minimal Coverage

在至多$1e5$条线段(端点范围$|l,r|\le50000$)中选出一些使得这些线段能覆盖$[0,m]$(可以重叠覆盖)

如果选不出来输出No solution,如果能选出来要求选出的线段条数最小，并且输出选出的线段

----

还是比较简单的一个dp

记$dp_x$为能覆盖$[0,x]$的最少的线段集合的大小

对于一个点为$l,r$的线段，$dp$状态的转移为

$dp_x =min(dp_i)+1(l\le i \le r)$

只要把线段按照右端点排序就可以满足无后效性

-----

剩下的就是代码了

```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node{
    int l,r,id;
    void init(int i,int L,int R){
        l = L,r = R;
        id = i;
    }
};
const int maxn = 112345;
Node node[maxn];

int dp[maxn*2],pr[maxn*2],val[maxn*2];
int msp[maxn*2],mlen;

int local(int x){
    if(x < 0) return -1;
    return x = lower_bound(msp,msp+mlen,x) - msp;
}
int main(){
    int m;
    scanf("%d",&m);
    int n = 0,l,r;
    mlen = 0;
    while(scanf("%d %d",&l,&r) && (l||r)){
        node[n].init(n,l,r);
        msp[mlen++] = l;
        msp[mlen++] = r;
        n++;
    }
    msp[mlen++] = m;
    msp[mlen++] = 0;
    sort(msp,msp+mlen);
    mlen = unique(msp,msp+mlen) - msp;
    m = local(m);
    int start = local(0);
    sort(node,node+n,[](Node a,Node b){return a.r < b.r;});
    memset(dp,0x3f,sizeof(dp)); 
    memset(pr,-1,sizeof(pr));
    memset(val,-1,sizeof(val));
    dp[start] = 0;
    for(int i=0;i<n;i++){
        int st,ed;
        st = max(start,local(node[i].l));
        ed = min(m,local(node[i].r));
        int id,v;
        id = -1,v = INF;
        for(int k=st;k<=ed;k++){
            if(dp[k] < v){
                v = dp[k],id = k;
            }
        }
        v++;
        if(dp[ed] > v){
            dp[ed] = v,pr[ed] = id,val[ed] = node[i].id;
        }
    }
    if(dp[m] == INF){
        puts("No solution");
    }
    else{
        vector<Node> ans;
        sort(node,node+n,[](Node a,Node b){return a.id < b.id;});
        int ed = m;
        while(val[ed] != -1){
            ans.push_back(node[val[ed]]);
            ed = pr[ed];
        }
        sort(ans.begin(),ans.end(),[](Node a,Node b){return a.l < b.l;});
        printf("%d\n",ans.size());
        for(auto x : ans){
            printf("%d %d\n",x.l,x.r);
        }
    }
    return 0;
}
```



