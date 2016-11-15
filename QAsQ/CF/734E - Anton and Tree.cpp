#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;
int bel[maxn];
int fnd(int x){
    return x == bel[x] ? bel[x] : bel[x] = fnd(bel[x]);
}
void join(int x,int y){
    x = fnd(x),y = fnd(y);
    if(x != y) 
        bel[x] = y;
}

int color[maxn];

vector<int> edge[maxn];
int l[maxn],r[maxn];

int dep[maxn];
void getdep(int st,int fa,int deep){
    dep[st] = deep;
    for(auto x : edge[st]){
        if(x == fa) continue;
        getdep(x,st,deep+1);
    }
}

int getst(int n){
    for(int i = 1; i <= n;i++) if(bel[i] == i) return i;
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n;i++){
        scanf("%d",&color[i]);
        edge[i].clear();
        bel[i] = i;
    }
    for(int i = 1 ; i < n ; i++){
        scanf("%d %d",&l[i],&r[i]);
        if(color[l[i]] == color[r[i]]){
            join(l[i],r[i]);
        }
    }
    for(int i = 1; i < n;i++){
        int bl = fnd(l[i]),br = fnd(r[i]);
        if(bl == br) continue;
        edge[bl].push_back(br);
        edge[br].push_back(bl);
    }
    memset(dep,0,sizeof(dep));
    getdep(getst(n),0,1);
    int rot = max_element(dep+1,dep+1+n) - dep;
    memset(dep,0,sizeof(dep));
    getdep(rot,0,1);
    int ans = *max_element(dep+1,dep+1+n);
    printf("%d\n",ans / 2);
    return 0;
}
