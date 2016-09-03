# Hdu 5853 Jong Hyok and String

先给出n个模式串，然后有m个询问，每次询问对于一个字符串，和他$right$集相同的字符串的个数

既然都$right$集了，显然是一个$SAM$的题

对多串建立$SAM$然后将询问的字符串放在$SAM$上$run$就好了

要是转移到了$null$说明答案是0，否则答案就是$len[st] - len[fa[st]]$

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345 ,mlen = 26;
char tem[maxn];

struct Sam{
    int len[maxn*2],fa[maxn*2],nex[maxn*2][mlen];
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
    void build(char *arr){
        omg = root;
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
    int fnd(char *arr){
        int st = root;
        for(int i=0;arr[i];i++){
            if(nex[st][arr[i] - 'a'] == -1)
                return 0;
            st = nex[st][arr[i] - 'a'];
        }
        return len[st] - len[fa[st]];
    }
}SAM;

char arr[maxn];

int main(){
    int T,icase = 1;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        SAM.init();
        while(n--){
            scanf("%s",arr);
            SAM.build(arr);
        }
        printf("Case #%d:\n",icase++);
        while(m--){
            scanf("%s",arr);
            printf("%d\n",SAM.fnd(arr));
        }
    }
    return 0;
}
```

