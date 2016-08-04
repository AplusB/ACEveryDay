# 609E - Minimum spanning tree for each edge

给出一个带权图，对每个边求经过这条边的MST

---

先求一遍MST自然是极好的，然后对于在MST上的边，自然就是全局MST了

对于不在MST上的边，找到这个边两个端点在MST上的路径上最大权的边并去掉，然后加上询问的这条边的权就好了

```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 212345,maxm = 212345,max_log = 18;
const int ROOT = 1;
vector<pair<int,LL> >edge[maxn];
void Link(int st,int ed,LL v){
    edge[st].push_back(make_pair(ed,v));
}

int deep[maxn],fa[maxn][max_log];
int nofa[maxn];

struct Info{
    LL x;
    Info(LL x = 0):x(x){};
};

Info operator + (const Info a,const Info b){
    return Info(max(a.x,b.x));
}

Info info[maxn][max_log];

void dfs(int st,int Fa,int Deep=1){
    for(int i=1;i<max_log;i++)
        fa[st][i] = -1,info[st][i] = Info();
    fa[st][0] = Fa,deep[st] = Deep;
    for(auto x : edge[st]){
        if(x.first == Fa) continue;
        dfs(x.first,st,Deep+1);
        info[x.first][0] = Info(x.second);
    }
}
void init(int n){
    memset(fa,-1,sizeof(fa));
    dfs(ROOT,-1);
	for (int j = 1;j < max_log;j++){
		for (int i = 1;i <= n;i++){
			if (fa[i][j-1] != -1){
				fa[i][j] = fa[fa[i][j-1]][j-1];
				info[i][j] = info[i][j-1] + info[fa[i][j-1]][j-1];
			}
        }
    }
}

pair<int,Info> lca(int x,int y){
    Info ix,iy;
	if (deep[x] < deep[y]) swap(x,y);
	for (int i = max_log-1;i >= 0;i--){
		if (deep[fa[x][i]] >= deep[y]){
			ix = ix + info[x][i];
			x = fa[x][i];
		}
    }
	if (x == y) return make_pair(x,ix);
	for (int i = max_log-1;i >= 0;i--){
		if (fa[x][i] != fa[y][i]){
            ix = ix + info[x][i]; x = fa[x][i]; 
            iy = iy + info[y][i]; y = fa[y][i]; 
		}
    }
	return make_pair(fa[x][0], ix/*.rev()*/+info[x][0] + info[y][0] + iy);
}

struct Edge{
    int x,y;
    LL v,i;
    void init(int id){
        scanf("%d %d %I64d",&x,&y,&v);
        i = id;
    }
}edg[maxm];

struct Dsu{
    int arr[maxn];
    void init(int n){for(int i=0;i<=n;i++) arr[i] = i;}
    int fnd(int x){return x == arr[x] ? x : arr[x] = fnd(arr[x]);}
    bool join(int x,int y){
        x = fnd(x),y = fnd(y);
        if(x == y) return false;
        arr[x] = y;
        return true;
    }
}dsu;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        edg[i].init(i);
    }
    sort(edg,edg+m,[](Edge a,Edge b){return a.v < b.v;});
    dsu.init(n);
    LL all = 0;
    for(int i=0;i<m;i++){
        if(dsu.join(edg[i].x,edg[i].y)){
            all += edg[i].v;
            Link(edg[i].x,edg[i].y,edg[i].v);
            Link(edg[i].y,edg[i].x,edg[i].v);
        }
    }
    init(n);
    sort(edg,edg+m,[](Edge a,Edge b){return a.i < b.i;});
    for(int i=0;i<m;i++){
        printf("%I64d\n",all + edg[i].v - lca(edg[i].x,edg[i].y).second.x);
    }
    return 0;
}
```

