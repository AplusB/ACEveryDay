#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;

vector<int> edge[maxn];
int dep[maxn],fa[maxn];

void getdep(int st,int Fa,int deep){
    dep[st] = deep,fa[st] = Fa;
    for(auto x : edge[st]){
        if(x == Fa) continue;
        getdep(x,st,deep+1);
    }
}

pair<int,int> getCtr(int n){
    int rot;
    getdep(1,0,0);
    rot = max_element(dep+1,dep+1+n) - dep;
    getdep(rot,0,0);
    rot = max_element(dep+1,dep+1+n) - dep;
    int far = dep[rot];
    for(int i = 0 ; i < far / 2 ; i ++)
        rot = fa[rot];
    return make_pair(rot,(far & 1) ? fa[rot] : rot);
}

const int mod = 1e9 + 7,seed = 17;
LL har[maxn];

LL getHar(int st,int fa){
    har[st] = seed;
    for(auto x : edge[st]){
        if(x == fa) continue;
        getHar(x,st);
    }
    sort(edge[st].begin(),edge[st].end(),[&](int x,int y){return har[x] < har[y];});
    for(auto x : edge[st]){
        if(x == fa) continue;
        har[st] = (har[st] + har[x]) ^ (har[st] * har[x]);
        har[st] %= mod; 
    }
    (har[st] *= har[st]) %= mod;
    return har[st];
}

int getans(int st,int fa){
    int ret = edge[st].size() < 4;
    int bef = -1;
    for(auto x : edge[st]){
        if(x == fa) continue;
        if(bef == -1 || har[bef] != har[x])
            ret += getans(x,st);
        bef = x;
    }
    return ret;
}

int calans(int n){
    pair<int,int> ctr = getCtr(n);
    getHar(ctr.first,ctr.second);
    getHar(ctr.second,ctr.first);
    int ret = getans(ctr.first,ctr.second)+ getans(ctr.second,ctr.first);
    return ret / (1+ (har[ctr.first] == har[ctr.second]));
}
int main(){
    int n;
    scanf("%d",&n);
    int l,r;
    for(int i = 1; i < n;i++){
        scanf("%d %d",&l,&r);
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    printf("%d\n",calans(n));
}
