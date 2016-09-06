# SPOJ NSUBSTR

给出一个长$25 \times 10 ^ 4$ 的字符串，定义$f(x)$为所有的长$x$的子串中出现次数最多的那个的出现次数，求$f(1),f(2)...f(strlen)$

---

首先对输入的字符串建立$SAM$

然后对于每一个节点所对应的$[min,max]$这个区间，用$right$去更新这个区间的$max$，这样最后的结果就是需要输出的答案。可以用线段树来更新

有没有更简单的写法呢？可以简单的看出$F(x)$这个函数是单调不升的

如此一来我们可以用每个节点的$right$去更新这个节点的$max$这个点，然后扫一遍求一个后缀最大值，就是答案了

具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 251234 ,mlen = 26;
int val[maxn];

struct Sam{
    int len[maxn*2],fa[maxn*2],nex[maxn*2][mlen];
    int siz[maxn*2];
    int _cnt,root,omg;
    vector<int> edge[maxn];
    int newNode(int L = 0){
        len[_cnt] = L;
        memset(nex[_cnt],fa[_cnt] = -1,sizeof(nex[_cnt]));
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = omg = newNode();
    }
    void extend(int x){
        int ox = newNode(len[omg]+1);
        siz[ox]++;
        while(omg != -1 && nex[omg][x] == -1){
            nex[omg][x] = ox;
            omg = fa[omg];
        }
        if(omg == -1) fa[ox] = root;
        else{
            int omgx = nex[omg][x];
            if(len[omgx] == len[omg]+1) fa[ox] = omgx;
            else{
                int mgx = newNode(len[omg]+1);
                for(int i=0;i<mlen;i++)
                    nex[mgx][i] = nex[omgx][i];
                fa[mgx] = fa[omgx];
                fa[omgx] = fa[ox] = mgx;
                while(omg != -1 && nex[omg][x] == omgx)
                    nex[omg][x] = mgx,omg = fa[omg];
            }
        }
        omg = ox;
    }
    void dfs(int st = -1){
        if(st == -1) st = root;
        for(auto x : edge[st]){
            dfs(x);
            siz[st] += siz[x];
        }
    }
    void build(char *arr){
        init();
        memset(siz,0,sizeof(siz));
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
    void solve(int n){
        for(int i=0;i<_cnt;i++) edge[i].clear();
        for(int i=0;i<_cnt;i++) 
            if(fa[i] != -1) 
                edge[fa[i]].push_back(i);
        dfs();
        memset(val,0,sizeof(val));
        for(int i=0;i<_cnt;i++){
            if(i == root) continue;
            val[len[i]] = max(val[len[i]],siz[i]);
        }
        for(int i=n-1;i>=0;i--)
            val[i] = max(val[i],val[i+1]);
    }
}SAM;

char arr[maxn];

int main(){
    while(~scanf("%s",arr)){
        SAM.build(arr);
        int len = strlen(arr);
        SAM.solve(len);
        for(int i=1;i<=len;i++)
            printf("%d\n",val[i]);
    }
    return 0;
}
```

