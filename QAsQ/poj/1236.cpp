#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long

const int maxn = 123;
//Directed
vector<int> edge[maxn];
stack<int> S;

void Link(int st,int ed){
    edge[st].push_back(ed);
}

int dfn[maxn],low[maxn],_cnt;
int bel[maxn];

void init(int n){
    for(int i=0;i<n;i++){
        edge[i].clear();
    }
    while(S.empty()==false)
        S.pop();
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(bel,-1,sizeof(bel));
    _cnt = 1;
}

void dfs(int st){
    S.push(st);
    dfn[st] = low[st] = _cnt++;
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = *it;
        if(dfn[x] == -1){
            dfs(x);
            low[st] = min(low[st],low[x]);
        }
        else if(bel[x] == -1){
            low[st] = min(low[st],dfn[x]);
        }
    }
    if(low[st] == dfn[st]){
        while(S.top()!=st){
            bel[S.top()] = st;
            S.pop();
        }
        bel[st] = st;
        S.pop();
    }
}

bool jud(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(bel[i] == i)
            cnt++;
    }
    return cnt==1;
}


int ind[maxn],outd[maxn];;

int main(){
    int n;
    while(~scanf("%d",&n)){
        init(n);
        int x;
        for(int i=1;i<=n;i++){
            while(~scanf("%d",&x) && x){
                Link(i,x);
            }
        }
        for(int i=1;i<=n;i++){
            if(bel[i]==-1){
                dfs(i);
            }
        }
        if(jud(n)){
            puts("1\n0");
            continue;
        }
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        for(int i=1;i<=n;i++){
            for(vector<int>::iterator it = edge[i].begin();it!=edge[i].end();it++){
                if(bel[i] != bel[*it]){
                    ind[bel[*it]]++;
                    outd[bel[i]]++;
                }
            }
        }
        int in,out;
        in = out = 0;
        for(int i=1;i<=n;i++){
            if(bel[i] == i){
                if(ind[i] == 0) in++;
                if(outd[i]== 0) out++;
            }
        }
        printf("%d\n%d\n",in,max(in,out));
    }
    return 0;
}
