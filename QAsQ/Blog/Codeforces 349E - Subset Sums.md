# Codeforces 349E - Subset Sums

有$n(n\le 10^5)$个数，有$m$个下标的集合(集合的大小之和小于$10^5$)

维护两个操作

询问操作:$?\ k$      将下标在第k个集合内数求和输出

更新操作:$+\ k\ x$ 将下标在第k个集合内的数都$+x$

---

因为集合的大小之和小于$10 ^ 5$，不妨记集合的大小之和为S考虑将集合分类。将大小超过 $\sqrt S$的集合称之为大集合，大小小于$\sqrt S$的集合称之为小集合。显然大集合的个数小于$\sqrt{S}$

预处理每一个集合和每一个大集合的交集的大小。

考虑询问的时候，最后的答案是$(初始的数的和+小集合更新的贡献) +大集合更新的贡献$。

所以对于每个大集合维护这个大集合更新的$x$的和，预处理这个大集合中元素初始的和作为大集合的前两项的贡献。

先考虑更新操作

如果更新大集合，我们只维护这个集合更新的$x$的和。$O(1)$

如果更新小集合，我们遍历一遍小集合中的元素去更新，并且遍历所有的大集合更新该大集合维护的前两项的贡献。$O(2* \sqrt S) = O(\sqrt S)$

再考虑询问操作

如果询问小集合，可以遍历下标在小集合内的元素的和统计前两项。$O(\sqrt S)$

如果询问大集合，我们每次更新都维护了前两项。$O(1)$

对于所有的集合，大集合更新的贡献只需要遍历一遍大集合，使用之前维护的该集合和每一个大集合的交集的大小可以$O(\sqrt S)$的求解

这样我们就在$O(m \times \sqrt S)$的时间复杂度内做出了本题

---

*说了这么多其实本质就是分开大小集合的贡献去暴力而已*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
#define LL long long 

LL arr[maxn], stv[maxn];
vector<int> rev[maxn],seter[maxn],big;
bitset<maxn> hav[400];
LL add[maxn];
int ctb[maxn][400], id[maxn];

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=n;i++) scanf("%I64d",&arr[i]);

    int len, allsiz = 0;
    for(int i = 1;i<=m;i++){
        scanf("%d",&len);
        allsiz += len;
        id[i] = -1;
        add[i] = stv[i] = 0;
        int x;
        while(len--){
            scanf("%d",&x);
            seter[i].push_back(x);
            stv[i] += arr[x];
        }
    }
    int unit = (int)sqrt(allsiz * 1.0) + 1;
    for(int i = 1;i<=m;i++){
        if(seter[i].size() >= unit){
            id[i] = big.size();
            big.push_back(i);
            for(auto x : seter[i]){
                hav[id[i]][x] = 1;
                rev[x].push_back(id[i]);
            }
        }
    }
    memset(ctb,0,sizeof(ctb));
    for(int i = 1;i<=m;i++){
        for(auto x : seter[i]){
            for(auto loca : rev[x]){
                ctb[i][loca]++;
            }
        }
    }
    char ord[3];
    int k;
    LL v;
    while(q--){
        scanf("%s %d",ord,&k);
        if(*ord == '?'){
            LL ans = 0;
            if(id[k] == -1) for(auto x : seter[k]) ans += arr[x];
            else ans = stv[k];
            for(auto x : big){
                ans += add[x] * ctb[k][id[x]];
            }
            printf("%I64d\n",ans);
        }
        else{
            scanf("%I64d",&v);
            if(id[k] != -1) add[k] += v;
            else{
                for(auto x : seter[k]) arr[x] += v;
                for(auto x : big ){
                    stv[x] += v * ctb[k][id[x]];
                }
            }
        }
    }
    return 0;
}
```

