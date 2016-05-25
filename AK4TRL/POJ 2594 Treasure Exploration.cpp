//*不正经的一道二分匹配.题目允许重点出现,即在匈牙利算法基础上可对已覆盖点进行增广扩充，寻找增广路
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
int G[505][505];
int cx[505], cy[505];//cx[i]->最大匹配中与xi匹配的Y顶点，cy同理
int vis[505];
int path(int u){
	for(int v = 0; v < n; ++v){
		if(G[u][v] && !vis[v]){
			vis[v] = 1;
			if(cy[v] == -1 || path(cy[v])){
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int MaxMatch(){
	int res = 0;
	memset(cx,-1,sizeof cx);
	memset(cy,-1,sizeof cy);
	for(int i = 0; i < n; ++i){
		if(cx[i] == -1){
			memset(vis,0,sizeof vis);
			res += path(i);
		}
	}
	return res;
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m),n + m){
		memset(G,0,sizeof G);
		int u, v;
		for(int i = 0; i < m; ++i)
			scanf("%d%d",&u,&v), G[--u][--v] = 1;

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(i != j && G[i][k] && G[k][j])
						G[i][j] = 1;

		int ans = n - MaxMatch();
		if(ans == 0)
			ans = 1;
		cout << ans << endl;
	}

	return 0;
}
