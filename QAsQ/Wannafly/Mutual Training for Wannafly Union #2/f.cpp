#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
vector<pair<int,LL>> edge[maxn];

void Link(int st,int ed,int v){
    edge[st].push_back(make_pair(ed,v));
    edge[ed].push_back(make_pair(st,v));
}

bool vis[maxn],use[maxn];
LL dis[maxn];
queue<int> Q;

void spfa(int st){
    memset(use,0,sizeof(use));
    dis[st] = 0;
    Q.push(st);
    while(Q.empty()==false){
        int st = Q.front();
        vis[st] = false;
        Q.pop();
        for(auto it : edge[st]){
            int ed = it.first;
            LL v = it.second;
            if(dis[st] + v <= dis[ed]){
                use[ed] = true;
                dis[ed] = dis[st] + v;
                if(vis[ed] == false){
                    vis[ed] = true;
                    Q.push(ed);
                }
            }
        }
    }
}

bool vir[maxn];

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int s,e;
    LL v;
    memset(vir,0,sizeof(vir));
    while(m--){
        scanf("%d %d %I64d",&s,&e,&v);
        Link(s,e,v);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int ans = 0;
    while(k--){
        scanf("%d %I64d",&s,&v);
        ans += vis[s];
        if(vis[s] == false) vis[s] = true, Q.push(s);
        vir[s] = true;
        dis[s] = min(dis[s],v);
    }
    dis[1] = 0;
    spfa(1);
    for(int i = 2; i <= n ; i ++){
        ans += vir[i] && use[i];
    }
    printf("%d\n",ans);
    return 0;
}
