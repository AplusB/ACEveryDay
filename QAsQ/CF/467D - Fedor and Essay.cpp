#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 112345;
vector<int> edge[maxn];
vector<int> dcc[maxn];  
  
int dfn[maxn],low[maxn],_cnt;  
int bel[maxn];  
  
stack<int> S;  
  
void initer(int n){  
    for(int i=0;i<=n;i++){  
        dcc[i].clear();  
    }  
    memset(dfn,-1,sizeof(dfn));  
    memset(low,-1,sizeof(low));  
    memset(bel,-1,sizeof(bel));  
    _cnt = 0;  
    while(S.empty()==false){  
        S.pop();  
    }  
}  
  
  
void dfs(int st){  
    dfn[st] = low[st] = _cnt++;  
    S.push(st);  
    for(auto x : edge[st]){
        if(dfn[x] == -1){  
            dfs(x);  
            low[st] = min(low[st],low[x]);  
        }  
        else if(bel[x] == -1){  
            low[st] = min(low[st],dfn[x]);  
        }  
    }  
    if(low[st] == dfn[st]){  
        while(S.top() != st){  
            bel[S.top()] = st;  
            dcc[st].push_back(S.top());
            S.pop();  
        }  
        dcc[st].push_back(st);
        bel[st] = st;  
        S.pop();  
    }  
}  
  
void Link(int st,int ed){
    edge[st].push_back(ed);
}

void Low(string & s){
    for(auto & c : s){
        if(isupper(c))
            c = c - 'A' + 'a';
    }
}

map<string,int> M;
string lis[maxn];
int len = 1;

int getid(string & v){
    Low(v);
    int & id = M[v];
    if(id != 0) return id;
    id = len,lis[len] = v;
    len++;
    return id;
}

int inp[maxn];

LL cntr(string & v){
    LL cnt = 0;
    for(auto c : v){
        if(c == 'r')
            cnt++;
    }
    return cnt;
}

LL ar[maxn],al[maxn];
bool vis[maxn];

void dfser(int st){
    if(vis[st]) return;
    vis[st] = true;
    ar[st] = cntr(lis[st]),al[st] = lis[st].size();
    for(auto x : dcc[st]){
        LL bar = cntr(lis[x]),bal = lis[x].size();
        if(bar < ar[st] || (bar == ar[st] && bal < al[st])){
            ar[st] = bar,al[st] = bal;
        }
    }
    for(auto ve : dcc[st]){
        for(auto ed : edge[ve]){
            int x = bel[ed];
            if(x != st){
                dfser(x);
                LL bar = ar[x],bal = al[x];
                if(bar < ar[st] || (bar == ar[st] && bal < al[st])){
                    ar[st] = bar,al[st] = bal;
                }
            }
        }
    }
}

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    string v;
    for(int i=0;i<n;i++){
        cin>>v;
        inp[i] = getid(v);
    }
    int m;
    string u;
    cin>>m;
    while(m--){
        cin>>u>>v;
        Link(getid(u),getid(v));
    }
    initer(len);
    for(int i=1;i<len;i++){  
        if(dfn[i] == -1){  
            dfs(i);  
        }  
    }  

    LL ra = 0,la = 0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        int st = bel[inp[i]];
        dfser(st);
        ra += ar[st],la += al[st];
    }
    cout<<ra<<" "<<la<<endl;
    return 0;
}
