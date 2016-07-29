/*
  裸的dfs
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define CC(a) memset(a,0,sizeof(a))

int n,m,ans;
char maze[11][11],c[11];

void dfs(int y){
	int i,j,k,l,res=0;
	if(y>n)return ;
	if(m==0){
		ans++;
//		printf("%d %d\n",y,ans);
		return ;
	}
	for(i=0;i<n;i++){
		if(c[i])continue;
		if(maze[y][i]=='#'){
			m--;
			c[i]=1;
			dfs(y+1);
			m++;
			c[i]=0;
		}
	}
	dfs(y+1);
}

int main()
{
	int i,j,k,l;
	while(scanf("%d%d",&n,&m)&&(n!=-1&&m!=-1)){
		CC(maze);CC(c);ans=0;
		for(i=0;i<n;i++)scanf("%s",maze[i]);
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
