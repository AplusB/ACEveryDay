#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;
vector<int> edge[maxn];
stack<int> S;

int dfn[maxn],low[maxn],_cnt;
int bel[maxn];

void init(int n){
    while(S.empty()==false)
        S.pop();
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(bel,-1,sizeof(bel));
    _cnt = 1;
}

void dfs(int st,int fa=0){
    S.push(st);
    dfn[st] = low[st] = _cnt++;
    for(auto &x :edge[st]){
        if(x == fa) continue;
        if(dfn[x] == -1){
            dfs(x,st);
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

int fa[maxn];

#define LL long long 
const int mod = 1e9+7;

LL power(int n){
    LL ret = 1;
    LL x = 2;
    while(n){
        if(n&1) (ret *= x ) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return ret;
}

int cnt[maxn];


int main(){
    int n;
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        fa[i] = x;
    }
    int in,no;
    in = no = 0;
    LL ans = 1;
    for(int i=1;i<=n;i++){
        if(fa[i] != -1 && fa[fa[i]] == i){
            no--;
            fa[fa[i]] = -1;
            fa[i] = -1;
        }
        else{
            edge[i].push_back(fa[i]);
            edge[fa[i]].push_back(i);
        }
    }
    init(n);
    for(int i=1;i<=n;i++){
        if(dfn[i] == -1){
            dfs(i);
        }
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        cnt[bel[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(bel[i] == i){
            if(cnt[i] == 1) no++;
            else{
                (ans *= power(cnt[i])-2 ) %= mod;
            }
        }
    }
    (ans *= power(no)) %= mod;
    cout<<ans<<endl;
    return 0;
}
