#pragma comment(linker,"/STACK:102400000,102400000") 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const int maxh = 1e6 + 5;
const int md = 1e6 + 3;
struct Edge{
	int v, next;
}E[maxn << 1];
int head[maxn], tol, n, k;
int vis[maxn], sz[maxn], mx[maxn], minSize, root;
LL mul1[maxn], mul2[maxn];
int ID[maxn], cnt;
LL val1[maxn], val2[maxn];
int hah[maxh], id[maxh], judge;

void add(int x, int y){
	if(hah[x] != judge){
		hah[x] = judge;
		id[x] = y;
	}else if(id[x] > y){
		id[x] = y;
	}
}

LL Inv(LL a){
	int k = md - 2;
	LL ans = 1;
	while(k){
		if(k & 1) ans = ans * a % md;
		a = a * a % md;
		k >>= 1;
	}
	return ans;
}

void init(){
	memset(head, -1, sizeof head);
	tol = 0;
	memset(hah, -1, sizeof hah);
	judge = 0;
}

void add_edge(int u, int v){
	E[tol].v = v;
	E[tol].next = head[u];
	head[u] = tol++;
}

void get_size(int u, int pre){
	sz[u] = 1;
	mx[u] = 0;
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre || vis[v]) continue;
		get_size(v, u);
		sz[u] += sz[v];
		if(sz[v] > mx[u]) mx[u] = sz[v];
	}
}

void get_root(int rt, int u, int pre){
	if(sz[rt] - sz[u] > mx[u]){
		mx[u] = sz[rt] - sz[u];
	}
	if(mx[u] < minSize){
		minSize = mx[u];
		root = u;
	}
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre || vis[v]) continue;
		get_root(rt, v, u);
	}
}

void get_mul(int u, int pre, LL x, LL y){
	mul1[cnt] = x;
	mul2[cnt] = y;
	ID[cnt++] = u;
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre || vis[v]) continue;
		get_mul(v, u, x * val1[v] % md, y * val2[v] % md);
	}
}

int flag, s, e;

void update(int u, int v){
	if(u > v) swap(u, v);
	if(!flag || u < s || u == s && v < e){
		flag = 1;
		s = u;
		e = v;
	}
}

void dfs(int u){
	minSize = n + 1;
	get_size(u, -1);
	get_root(u, u, -1);
	vis[root] = 1;
	add(val1[root], root);
	for(int i = head[root]; ~i; i = E[i].next){
		int v = E[i].v;
		if(vis[v]) continue;
		cnt = 0;
		get_mul(v, root, val1[v] % md, val2[v] * k % md);
		for(int j = 0; j < cnt; j++){
			if(hah[mul2[j]] == judge){
				update(ID[j], id[mul2[j]]);
			}
		}
		for(int j = 0; j < cnt; j++){
			add(mul1[j] * val1[root] % md, ID[j]);
		}
	}
	++judge;
	for(int i = head[root]; ~i; i = E[i].next){
		if(!vis[E[i].v]) dfs(E[i].v);
	}
}

int main(){
	while(scanf("%d%d", &n, &k) != EOF){
		init();
		for(int i = 1; i <= n; i++){
			scanf("%I64d", &val1[i]);
			val2[i] = Inv(val1[i]);
		}
		for(int i = 1; i < n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		flag = 0;
		dfs(1);
		if(!flag) puts("No solution");
		else printf("%d %d\n", s, e);
	}
	return 0;
}
