#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod = 1000000007;
const int maxn = 112345;

vector<pair<int,LL> >edge[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

void Link(int st,int ed,LL v){
    edge[st].push_back(make_pair(ed,v));
}

LL dis[maxn];
bool vis[maxn];
queue<int> Q;

void spfa(int st){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    while(Q.empty()==false)
        Q.pop();
    vis[st] = true,dis[st] = 0;
    Q.push(st);
    while(Q.empty()==false){
        st = Q.front();
        Q.pop();
        vis[st] = false;
        for(vector<pair<int,LL> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
            int ed = it->first;
            LL v = it->second;
            if(dis[st] + v < dis[ed]){
                dis[ed] = dis[st] + v;
                if(vis[ed] == false){
                    vis[ed] = true;
                    Q.push(ed);
                }
            }
        }
    }
}

int ind[maxn];
LL cnt[maxn];

LL topo(int n){
    memset(ind,0,sizeof(ind));
    for(int st=1;st<=n;st++){
        for(vector<pair<int,LL> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
            int ed = it->first;
            LL v = it->second;
            if(dis[st] + v == dis[ed]){
                ind[ed]++;
            }
        }
    }
    while(Q.empty()==false){
        Q.pop();
    }
    for(int i=1;i<=n;i++){
        if(ind[i] == 0)
            Q.push(i);
    }
    memset(cnt,0,sizeof(cnt));
    cnt[1] = 1;
    while(Q.empty()==false){
        int st = Q.front();
        Q.pop();
        for(vector<pair<int,LL> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
            int ed = it->first;
            LL v = it->second;
            if(dis[st] + v == dis[ed]){
                cnt[ed] += cnt[st];
                cnt[ed] %= mod;
                ind[ed]--;
                if(ind[ed]==0)
                    Q.push(ed);
            }
        }
    }
    return cnt[n];
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        init(n);
        int st,ed;
        LL v;
        while(m--){
            scanf("%d %d %lld",&st,&ed,&v);
            Link(st,ed,v);
        }
        spfa(1);
        printf("%lld\n",topo(n));
    }
    return 0;
}
