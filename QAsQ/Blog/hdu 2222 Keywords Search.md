# hdu 2222 Keywords Search

学过SAM回头才看懂AC自动机我真是太弱了

问模式串有多少个在给出的模式串中出现过

---

AC自动机模板题

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456,maxLen = 26;

int toid(char c){ return c - 'a'; }

queue<int> Q;

struct ACMA{
    int nex[maxn][maxLen],fail[maxn];
    int cnt[maxn];
    int _cnt,root;
    int newNode(){
        memset(nex[_cnt],fail[_cnt] = -1,sizeof(nex[_cnt]));
        cnt[_cnt] = 0;
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = newNode();
    }
    void insert(char *arr){
        int st = root;
        for(int i=0;arr[i];i++){
            int & stx = nex[st][toid(arr[i])]; 
            if(stx == -1) stx = newNode();
            st = stx;
        }
        cnt[st]++;
    }
    void build(){
        while(Q.empty()==false) Q.pop();
        fail[root] = root;
        int st;
        for(int i=0;i<maxLen;i++){
            if((st = nex[root][i]) != -1){
                fail[st] = root;
                Q.push(st);
            }
        }
        while(Q.empty()==false){
            st = Q.front(),Q.pop();
            for(int i=0;i<maxLen;i++){
                if(nex[st][i] != -1){
                    int fst = fail[st],son = nex[st][i];
                    while(fst != root && nex[fst][i] == -1)
                        fst = fail[fst];
                    fail[son] = nex[fst][i] == -1 ? root : nex[fst][i]; 
                    Q.push(son);
                }
            }
        };
    }
    void out(){
        for(int i=0;i<_cnt;i++){
            printf("%d  ",i);
            printf("fail = %2d cnt = %d ",fail[i],cnt[i]);
            for(int j=0;j<26;j++){
                if(nex[i][j] != -1)
                printf("(%c:%3d)",j+'a',nex[i][j]);
            }
            puts("");
        }
    }
    int cal(char *arr){
        int ret = 0;
        int st = root;
        for(int i=0;arr[i];i++){
            while(st != root && nex[st][toid(arr[i])] == -1)
                st = fail[st];
            if(nex[st][toid(arr[i])] != -1) st = nex[st][toid(arr[i])];
            int tem = st;
            while(tem != root){
                ret += cnt[tem];
                cnt[tem] = 0;
                tem = fail[tem];
            }
        }
        return ret;
    }
}acma;

char arr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        acma.init();
        while(n--){
            scanf("%s",arr);
            acma.insert(arr);
        }
        acma.build();
        scanf("%s",arr);
        printf("%d\n",acma.cal(arr));
    }
    return 0;
}
```



> $fail$指向的是当前状态在字典树中出现的最长的后缀，因为随着长度的减少出现的概率会变大。