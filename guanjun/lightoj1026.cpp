/* ***********************************************
Author        :guanjun
Created Time  :2016/7/3 14:32:14
File Name     :1026.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 1<<30
#define maxn 10000+10
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

vector<int>vec[maxn];
typedef pair<int,int>pii;
vector<pii>edge;

int vis[maxn],dfn[maxn],low[maxn];
int cnt,root,n,m,ans;
bool cmp(pii a,pii b){
    if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
void dfs(int u,int fa){
	int i,v,son=0;
	vis[u]=1;
	dfn[u]=low[u]=cnt++;
	for(i=0;i<vec[u].size();i++){
		v=vec[u][i];
		if(vis[v]==1&&v!=fa)
			low[u]=min(low[u],dfn[v]);
		if(vis[v]==0){
			dfs(v,u);
			son++;
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				ans++;
				edge.push_back(make_pair(min(u,v),max(u,v)));
			}
		}
	}
	vis[u]=2;
}
void init(){
	edge.clear();
	for(int i=0;i<maxn;i++){
		vec[i].clear();
		vis[i]=0;
		low[i]=0;
		dfn[i]=0;
	}
	cnt=0;
	ans=0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	char c1,c2;
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++){
		printf("Case %d:\n",tt);
		cin>>n;
		init();
		int u,v,t;
		for(int i=1;i<=n;i++){
			cin>>u;
			cin>>c1>>t>>c2;
			for(int j=1;j<=t;j++){
				cin>>v;
				vec[u].push_back(v);
				vec[v].push_back(u);
			}
		}
		for(int i=0;i<n;i++){
			if(!vis[n]){
				root=i;
				dfs(root,-1);
			}
		}
		sort(edge.begin(),edge.end(),cmp);
		printf("%d critical links\n",ans);
		for(int i=0;i<ans;i++){
			printf("%d - %d\n",edge[i].first,edge[i].second);
		}
	}
    return 0;
}

