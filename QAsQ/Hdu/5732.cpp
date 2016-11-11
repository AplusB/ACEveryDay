#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
#define Deag
const int mod = 100000007;
const int seed = 17;

char inp[15],onp[15];

struct Tree{
    vector<int> edge[maxn];
    LL Har[maxn];
    string anw[maxn], rip[maxn];
    void done(int st,int fa){
        if(fa == 0) _cnt = 0;
        anw[_cnt++] = rip[st]; 
        for(auto x : edge[st]){
            if(x == fa) continue;
            done(x,st);
        }
    }
    int siz[maxn];
    LL dfsh(int st,int fa){
        Har[st] = seed;
        siz[st] = 1;
        for(auto x : edge[st]){
            if(x == fa) continue;
            dfsh(x,st);
            siz[st] += siz[x];
        }
        sort(edge[st].begin(),edge[st].end(),[&](int x,int y){return Har[x] < Har[y];});
        for(auto x : edge[st]){
            if(x == fa) continue;
            (Har[st] *= Har[x] )%= mod;
            (Har[st] ^= Har[x] )%= mod;
        }
        (Har[st] += siz[st]) %= mod;
        (Har[st] *= Har[st]) %= mod;
        return Har[st];
    } 
    int dep[maxn],fa[maxn];
    void getdep(int st,int Fa,int Dep){
        dep[st] = Dep,fa[st] = Fa;
        for(auto x : edge[st]){
            if(x == fa[st]) continue;
            getdep(x,st,Dep+1);
        }
    }
    int ctr[2];
    void getCtr(int n){
        getdep(1,0,0);
        ctr[0] = max_element(dep+1,dep+1+n) - dep;
        getdep(ctr[0],0,0);
        ctr[0] = max_element(dep+1,dep+1+n) - dep;
        int fdep = dep[ctr[0]];
        for(int i = 0; i < fdep/2; i++) 
            ctr[0] = fa[ctr[0]];
        ctr[1] = ctr[0];
        if(fdep & 1) ctr[1] = fa[ctr[1]];
    }
    map<string,int> id;
    int _cnt;
    void init(int n){
        for(int i = 0 ; i <= n;i++) 
            edge[i].clear();
        id.clear();
        _cnt = 1;
    }
    int toid(string v){
        if(id.find(v) != id.end()) return id[v];
        rip[_cnt] = v;
        return id[v] = _cnt++;
    }
    void input(int n){
        init(n);
        int l , r;
        for(int i = 1; i < n;i++){
            scanf("%s %s",inp,onp);
            l = toid(inp),r = toid(onp); 
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
    }
}X,Y;

void solve(){
    for(int i = 0 ; i < 2; i ++){
        for(int j = 0 ; j < 2;j ++){
            if(X.dfsh(X.ctr[i],0) == Y.dfsh(Y.ctr[j],0)){
                X.done(X.ctr[i],0);
                Y.done(Y.ctr[j],0);
                return;
            }
        }
    }
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        X.input(n);
        Y.input(n);
        X.getCtr(n);
        Y.getCtr(n);
        solve();
        for(int i = 0 ; i < n ; i++)
            printf("%s %s\n",X.anw[i].c_str(),Y.anw[i].c_str());
    }
    return 0;
}
