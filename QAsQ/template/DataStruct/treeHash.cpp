#define LL long long 
const int mod = 100000007;
const int maxn = 112345;
const int seed = 17;

struct Tree{
    vector<int> edge[maxn];
    LL Har[maxn];
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
    void init(int n){
        for(int i = 0 ; i <= n;i++) 
            edge[i].clear();
    }
    void build(int n){
        init(n);
        int l , r;
        for(int i = 1; i < n;i++){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
    }
};
