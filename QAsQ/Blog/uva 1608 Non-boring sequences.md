# uva 1608 Non-boring sequences  

定一个一个串是boring的等价于是否存在一个独一无二（只出现一次）的元素

问给出的串是否所有的字串都不是boring的

----

对于整个串来说，如果所有的字符都不是独一无二的，那么显然就是boring了

如果出现了一个字符是独一无二的，不妨假设在第$k$个位置，那么所有包含这个元素的字串都不是boring的，还剩下的是哪些字串呢？假设这个字符串长$n$，那么剩下的其实就是被包含在$[1,k-1]$和$[k+1,n]$的字串。咦这不就分治了吗

-----

这样的话一个思路就出来了，每次从前往后找一个独一无二的字符，然后分治下去

----

但是如果每一个元素都是独一无二的话，这样的复杂度会退化到$O(n^2)$。我们需要换一个找独一无二的字符的方式。如果从两边往中间找的话，复杂度就不会退化了，最坏情况下（每次五一无二的字符都在中间），复杂度也是$O(nlogn)$ (想一想，为什么)

然后剩下的就是代码了

```cpp
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 212345;

struct Node{
    int v,id;
    void init(int i){
        id = i;
        scanf("%d",&v);
    }
}node[maxn];

bool cmp(Node a,Node b){
    if(a.v != b.v)
        return a.v < b.v;
    return a.id < b.id;
}
int l[maxn],r[maxn];

inline bool in(int st,int ed,int id){
    return l[id]<st && ed<r[id];
}

bool judge(int st,int ed){
    if(st >= ed)
        return true;
    for(int i=0;i<=(ed-st)/2;i++){
        if(in(st,ed,st+i))
            return judge(st,st+i-1) && judge(st+i+1,ed);
        if(in(st,ed,ed-i))
            return judge(st,ed-i-1) && judge(ed-i+1,ed);
    }
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            node[i-1].init(i);
        }
        sort(node,node+n,cmp);
        for(int i=0;i<n;i++){
            if(i==0 || node[i-1].v != node[i].v) l[node[i].id] = 0;
            else l[node[i].id] = node[i-1].id;
            if(i==n-1 || node[i].v != node[i+1].v) r[node[i].id] = n+1;
            else r[node[i].id] = node[i+1].id;
        }

        puts(judge(1,n)?"non-boring":"boring");
    }
    return 0;
}
```