# SPOJ SUBLEX

求字典序第k大字串

SAM的节点和转移所构成的是一个DAG，并且SAM从起点开始的每一条路径都是模式串的一个字串，根据这两个性质在SAM上dfs即可

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 91234*2 ,mlen = 26;
char tem[maxn];

struct Sam{
    int len[maxn],fa[maxn],nex[maxn][mlen];
    int siz[maxn];
    int _cnt,root,omg;
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
    void out(){
        for(int i=0;i<_cnt;i++){
            printf("id = %d fa = %d len = %d siz = %d: ",i,fa[i],len[i],siz[i]);
            for(int j=0;j<5;j++){
                printf("(%c,%2d) ",j + 'a',nex[i][j]);
            }
            puts("");
        }
    }
    void build(char *arr){
        init();
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
    void initDfs(int st = -1){
        if(st == -1){
            st = root;
            memset(siz,-1,sizeof(siz));
        }
        if(siz[st] != -1) return;
        siz[st] = 1;
        for(int i=0;i<mlen;i++){
            if(nex[st][i] != -1){
                initDfs(nex[st][i]);
                siz[st] += siz[nex[st][i]];
            }
        }
    }
    void dfs(int x,int st=-1,int len = 0){
        if(st == -1) st = root;
        if(x <= 1){
            tem[len] = 0;
            printf("%s\n",tem);
            return;
        }
        x--;
        for(int i=0;i<mlen;i++){
            int p = nex[st][i];
            if(p != -1){
                if(x > siz[p]) x -= siz[p];
                else{
                    tem[len] = 'a' + i;
                    dfs(x,p,len+1);
                    return;
                }
            }
        }
    }
}SAM;

char arr[maxn];

int main(){
    scanf("%s",arr);
    SAM.build(arr);
    SAM.initDfs();
    int T;
    scanf("%d",&T);
    int k;
    while(T-- && ~scanf("%d",&k)){
        SAM.dfs(k+1);
    }
    return 0;
}
```

