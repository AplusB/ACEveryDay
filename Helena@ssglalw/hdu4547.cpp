#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 100005;

int vis[MAX_N];
int ans[MAX_N];
int ans_tar[MAX_N];//每组查询的目标目录
int indeg[MAX_N];
int depth[MAX_N];
map<string, int> name;
vector<int> G[MAX_N];//邻接表，边不带权
vector<int> query_tar[MAX_N];
vector<int> query_id[MAX_N];
int par[MAX_N];

int T;
int n, m;
int seq_num;//目录名的序列号，从1开始

void init(){
	seq_num = 1;
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	memset(ans_tar, 0, sizeof(ans_tar));
	memset(indeg, 0, sizeof(indeg));
	memset(depth, 0, sizeof(depth));
	name.clear();
	for(int i=0; i<MAX_N; i++){
		G[i].clear();
		query_tar[i].clear();
		query_id[i].clear();
		par[i] = i;
	}
}
int find(int x){
	return par[x]==x ? x : par[x] = find(par[x]);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return ;
	par[y] = x;
}

void dfs(int r, int l){
	//cout << "dfs " << r << endl;
	vis[r] = 1;
	depth[r] = l;
	for(int i=0; i<G[r].size(); i++){
		//cout << G[r][i] << endl;
		if(vis[G[r][i]]) continue;
		dfs(G[r][i], l+1);
		unite(r, G[r][i]);
	}
	for(int i=0; i<query_tar[r].size(); i++){
		if(!vis[query_tar[r][i]]) continue;
		int cur, tar;
		int ans_id = query_id[r][i];//这一查询所持的序列号
		int real_tar = ans_tar[ans_id];//这一个查询真正指定的target
		if(r == real_tar){//当前r是目标
			cur = query_tar[r][i];
			tar = real_tar;
		}else{//已访问过的那个点是目标
			cur = r;
			tar = real_tar;
		}
		//cout << "query " << cur << tar << endl;
		if(cur == tar) ans[ans_id] = 0;
		else{
			int ca = find(query_tar[r][i]);
			//cout << query_tar[r][i] << "ca = " << ca << endl;
			if(ca == tar) ans[ans_id] = depth[cur] - depth[ca];//从cur上升到ca, 亦步亦趋
			else ans[ans_id] = depth[cur] - depth[ca] + 1;//从ca下降到tar，一步到位
		}
	}
}

void lca(int r){
	//cout << "root " << r << endl;
	dfs(r, 0);
}

int main()
{
	freopen("4547.txt", "r", stdin);
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<n-1; i++){
			string c, p;
			cin>>c;
			int u = name[c];//不存在会自动插入并置value为0
			if(u==0){
				u = name[c] = seq_num++;
			}

			cin>>p;
			int v = name[p];
			if(v==0){
				v = name[p] = seq_num++;
			}
			G[u].push_back(v);
			G[v].push_back(u);
			indeg[u]++;//入度为0的是根目录
		}
		// for(map<string, int>::iterator iter = name.begin(); 
		// 	iter != name.end(); iter++){
		// 	cout << iter->first << iter->second << endl;
		// }
		for(int i=0; i<m; i++){
			string cur, tar;
			cin >> cur >> tar;
			int u = name[cur];
			int v = name[tar];
			query_tar[u].push_back(v);
			query_tar[v].push_back(u);
			query_id[u].push_back(i);//tar和id是同步记录的
			query_id[v].push_back(i);
			ans_tar[i] = v;//为辨谁是目标目录
		}
		for(map<string, int>::iterator iter = name.begin(); 
			iter != name.end(); iter++){
			int id = iter->second;
			if(indeg[id] == 0){
				lca(id);
				break;
			}
		}
		for(int i=0; i<m; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
