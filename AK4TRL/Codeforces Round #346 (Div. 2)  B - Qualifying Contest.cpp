//给你n个人，然后有m个地区，每个地区将会选出分数最高的两个人,如果分数最高的不止两个人的话，输出？
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
struct node{
	int sorces;
	char a[15];
};
bool cmp(node A, node B){
	return A.sorces > B.sorces;
}
vector<node>g[10005];
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m;
	while(~scanf("%d%d",&n,&m)){
		node a;
		int index;
		for(int i = 0; i < n; ++i){
			scanf("%s %d %d",a.a,&index,&a.sorces);
			g[index].push_back(a);
		}
		for(int i = 1; i <= m; ++i)
			sort(g[i].begin(),g[i].end(),cmp);

		for(int i = 1; i <= m; ++i){
			if(g[i].size() > 2){
				if(g[i][1].sorces == g[i][2].sorces)
					puts("?");
				else
					printf("%s %s\n",g[i][0].a,g[i][1].a);
			}
			else
				printf("%s %s\n",g[i][0].a,g[i][1].a);
		}
	}

	return 0;
}
