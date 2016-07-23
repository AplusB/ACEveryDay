# poj 2942  Knights of the Round Table
建补图找点双联通分量

对每一个分量二分染色，染色失败的打上标记

最后没有打上标记的点就是所求的点

---

重新学习了一下点双联通分量。并且学会了不用将边入栈的姿势

```cpp
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define LL long long 
const int maxn  = 1123;

stack<int> S;
vector<int> edge[maxn],Dcc[maxn];
int dfn[maxn],low[maxn];
int _cnt,Dccnt;

void init(){
    memset(low,-1,sizeof(low));
    memset(dfn,-1,sizeof(dfn));
    _cnt = 1;
    while(S.empty()==false){ 
        S.pop();
    }
    for(int i=0;i<maxn*2;i++){
        Dcc[i].clear();
    }
}

void tarjan(int st,int fa){
    low[st] = dfn[st] = _cnt++;
    S.push(st);
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){int x = *it;
        if(x == fa) continue;
        if(dfn[x] == -1){
            tarjan(x,st);
            low[st] = min(low[st],low[x]);
            if(low[x] >= dfn[st]){
                int top;
                do{
                    top = S.top();
                    S.pop();
                    Dcc[Dccnt].push_back(top);
                }while(top != x);
                Dcc[Dccnt].push_back(st);
                Dccnt++;
            }
        }
        else{
            low[st] = min(low[st],dfn[x]);
        }
    }
}

int getDccForest(int n){
    init();
    Dccnt = 1;
    for(int i=1;i<=n;i++)
        if(dfn[i]==-1)
            tarjan(i,0);
    return Dccnt-1;
}

void initEdge(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

bool Gro[maxn][maxn],is[maxn];

bool canin[maxn];
int cor[maxn];

bool dfs(int st,int co){
    cor[st] = co;
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){int x = *it;
        if(!is[x]) continue;
        if(cor[x] == -1){
            if(!dfs(x,co^1))
                return false;
        }
        else if(cor[x] == co){
            return false;
        }
    }
    return true;
}

bool color(int st){
    memset(is,0,sizeof(is));
    for(vector<int>::iterator it = Dcc[st].begin();it != Dcc[st].end();it++){int x = *it;
        is[x] = true;
    }
    memset(cor,-1,sizeof(cor));
    return dfs(*Dcc[st].begin(),0);
}

int main(){
    int m,n;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        initEdge(n);
        memset(Gro,0,sizeof(Gro));
        int l,r;
        while(m--){
            scanf("%d %d",&l,&r);
            Gro[l][r] = Gro[r][l] = true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i != j && Gro[i][j] == false){
                    edge[i].push_back(j);
                }
            }
        }
        int len = getDccForest(n);
        memset(canin,0,sizeof(canin));
        for(int i=1;i<=len;i++){
            if(!color(i)){
                for(vector<int>::iterator it = Dcc[i].begin();it != Dcc[i].end();it++){int x = *it;
                    canin[x] = true;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!canin[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

