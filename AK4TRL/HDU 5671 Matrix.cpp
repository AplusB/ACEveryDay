#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;
#define inputt int t; std::cin >> t;
int n, m, q, G[1005][1005], pos1[1005], pos2[1005], sumn[1005], summ[1005];
void init(){
	for(int i = 1; i <= n; ++i)
		pos1[i] = i;
	for(int i = 1; i <= m; ++i)
		pos2[i] = i;
	for(int i = 1; i <= n; ++i)
		sumn[i] = 0;
	for(int i = 1; i <= m; ++i)
		summ[i] = 0;
}
int main(){
#ifdef hantai
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	//inputt;
	int t;
	while(~scanf("%d",&t)){
		while(t--){
			std::scanf("%d%d%d",&n,&m,&q);
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= m; ++j)
					std::scanf("%d",&G[i][j]);
			}
			init();

			for(int i = 0; i < q; ++i){
				int flag, x, y;
				std::scanf("%d%d%d",&flag,&x,&y);
				if(flag == 1)
					std::swap(pos1[x],pos1[y]);
				else if(flag == 2)
					std::swap(pos2[x],pos2[y]);
				else if(flag == 3)
					sumn[pos1[x]] += y;
				else if(flag == 4)
					summ[pos2[x]] += y;
			}

			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= m; ++j)
					std::printf(j < m? "%d ":"%d\n",G[pos1[i]][pos2[j]] + sumn[pos1[i]] + summ[pos2[j]]);
			}
		}
	}

	return 0;
}
