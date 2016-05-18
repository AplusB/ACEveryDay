//**很明显的一道二分匹配，题目要求求出每个人‘m’都要找到一间房子‘H’住下。全部人走一步要花费1金币，求最小花费
//**KM算法能求出完美匹配下的最大权匹配。
//**这样，若我们建图时将边变成变成负值，这样就可以求出图在负值状态下的最大值，然后我们再将结果*-1，得出的结果就是需要的最小花费。
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n, m;
int hcnt, mcnt;
int match[205], lx[205], ly[205];
int visy[205], visx[205], slack[205];
struct node{
	int x, y;
}man[205], house[205];
int G[205][205];
bool dfs(int x){
	visx[x] = 1;
	for(int i = 1; i <= hcnt; ++i){
		if(!visy[i]){
			int tmp = lx[x] + ly[i] - G[x][i];
			if(!tmp){
				visy[i] = 1;
				if(!match[i] || dfs(match[i])){
					match[i] = x;
					return 1;
				}
			}
			else if(slack[i] > tmp)
				slack[i] = tmp;
		}
	}
	return 0;
}
void KM(){
	memset(match,0,sizeof match);
	memset(lx,-0x3f3f3f3f,sizeof lx);
	memset(ly,0,sizeof ly);
	for(int i = 1; i <= mcnt; ++i)
		for(int j = 1; j <= hcnt; ++j)
			if(lx[i] < G[i][j])
				lx[i] = G[i][j];

	for(int i = 1; i <= mcnt; ++i){
		memset(slack,100,sizeof slack);
		while(1){
			memset(visx,0,sizeof visx);
			memset(visy,0,sizeof visy);
			if(dfs(i)) break;
			int minn = 0x3f3f3f3f;
			for(int j = 1; j <= hcnt; ++j)
				if(!visy[j] && slack[j] < minn)
					minn = slack[j];
			for(int j = 1; j <= mcnt; ++j)
				if(visx[j])
					lx[j] -= minn;
			for(int j = 1; j <= hcnt; ++j){
				if(visy[j])
					ly[j] += minn;
				else
                    slack[j] -= minn;
			}
		}
	}
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m;
	while(~scanf("%d%d",&n,&m)){
		if(!n && !m) break;
		memset(G,0,sizeof G);
		hcnt = mcnt = 1;
		getchar();
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				char c;
				scanf("%c",&c);
				if(c == 'H')
					house[hcnt].x = i, house[hcnt++].y = j;
				else if(c == 'm')
					man[mcnt].x = i, man[mcnt++].y = j;
			}
			getchar();
		}

		for(int i = 1; i <= mcnt; ++i)//build GRAPH
			for(int j = 1; j <= hcnt; ++j)
				G[i][j] = -(abs((double)man[i].x - (double)house[j].x) + abs((double)man[i].y - (double)house[j].y));

		KM();
		int ans = 0;
		for(int i = 1; i <= hcnt; ++i)
			ans += G[match[i]][i];
		printf("%d\n",-ans);
	}

	return 0;
}
