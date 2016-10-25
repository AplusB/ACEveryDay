# Hdu 4416 Good Article Good sentence

给出一个的字符串$A,|A| \le 100,000$，$n$个字符串，分别为$B_i,\sum\limits_{i=1}^n|B_i| \le 100,000$，求$A$中没有在任何一个$B_i$中出现的字串的个数。

---

对$A$建立$SAM$，将每一个$B_i$都放在$SAM$上运行，记录$SAM$中的每个节点对应的Bi中最长的匹配长度。

对于$SAM$中的每个节点，如果这个节点存在一个子节点在上一步被运行到，那么这个节点对最后的结果没有贡献。

否则如果这个节点没有被运行，那么这个节点所表示的字串都会被记录贡献。

否则这个节点被记录到了一个最长匹配位置，不妨设为$malen$，那么这个节点的贡献就是$len - malen$

具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 112345 ,mlen = 26;

struct Sam{
    vector<int> edge[maxn*2];
    int len[maxn*2],fa[maxn*2],nex[maxn*2][mlen];
    int malen[maxn*2];
    bool full[maxn * 2];
    int _cnt,root,omg;

    int newNode(int L = 0){
        len[_cnt] = L;
        memset(nex[_cnt],fa[_cnt] = -1,sizeof(nex[_cnt]));
        malen[_cnt] = 0;
        edge[_cnt].clear();
        full[_cnt] = false;
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = omg = newNode();
    }
    void extend(int x){
        int ox = newNode(len[omg]+1);
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
    void build(char *arr){
        init();
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
    void run(char *arr){
        int st = root;
        int lener = 0;
        for(int i = 0;arr[i];i++){
            int x = arr[i] - 'a';
            if(nex[st][x] != -1){
                st = nex[st][x];
                lener++;
            }
            else{
                while(st != -1 && nex[st][x] == -1)
                    st = fa[st];
                if(st == -1){
                    st = root;
                    lener = 0;
                }
                else{
                    lener = len[st]+1;
                    st = nex[st][x];
                }
            }
            malen[st] = max(malen[st],lener);
        }
    }
    LL dfs(int st){
        LL ret = 0;
        for(auto x : edge[st]){
            ret += dfs(x);
        }
        if(st != root && !full[st]){
            if(malen[st]){
                ret += len[st] - malen[st];
                full[fa[st]] = true;
            }
            else{
                ret += len[st] - len[fa[st]];
            }
        }
        else{
            full[fa[st]] = true;
        }
        return ret;
    }
    LL getans(){
        for(int i = 1;i<_cnt;i++) edge[fa[i]].push_back(i);
        return dfs(root);
    }
    void out(){
        for(int i = 0; i<_cnt;i++){
            printf("id = %d len = %d fa = %2d malen[i] = %d ",i,len[i],fa[i],malen[i]);
            for(int j = 0;j<mlen;j++){
                if(nex[i][j] != -1){
                    printf("%c -> %d ",j+'a',nex[i][j]);
                }
            }
            puts("");
        }
    }
}SAM;

char arr[maxn];

int main(){
    int T,icase = 1;
    int n;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        scanf("%s",arr);
        SAM.init();
        SAM.build(arr);
        while(n--){
            scanf("%s",arr);
            SAM.run(arr);
        }
       // SAM.out();
        printf("Case %d: %I64d\n",icase++,SAM.getans());
    }
}
```

