#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=5e5+200;
const double eps=1e-9;
const ll inf=2e15+9;

char mapp[20][20],r[20][20],c[20][20],grid[20][20],go[20][20];
int flag;

int dfs(int x,int y);
int judge();
int get_g(int x,int y);

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		if(cas>1) printf("\n");
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		memset(grid,0,sizeof(grid));

		for(int i=0;i<9;i++)
		{
			scanf("%s",mapp[i]);
			for(int j=0;j<9;j++)
			{
				r[i][mapp[i][j]-'0']=1;
				c[j][mapp[i][j]-'0']=1;
				int gg=get_g(i,j);
				grid[gg][mapp[i][j]-'0']=1;
			}
		}
		printf("Scenario #%d:\n",cas++);
		flag=0;
		dfs(0,0);

	}
	return 0;
}

int get_g(int x,int y)
{
	if(x<=2)
	{
		if(y<=2) return 1;
		else if(y<=5) return 2;
		else return 3;
	}
	else if(x<=5)
	{
		if(y<=2) return 4;
		else if(y<=5) return 5;
		else return 6;
	}
	else
	{
		if(y<=2) return 7;
		else if(y<=5) return 8;
		else return 9;
	}
}

int judge()
{
	flag=1;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d",go[i][j]);
		printf("\n");
	}
	return 0;
}

int dfs(int x,int y)
{
	if(flag==1) return 0;
	if(x==9 && y==0)
	{
		judge();
		return 0;
	}
	int nx=x+(y+1)/9,ny=(y+1)%9;
	if(mapp[x][y]!='0')
	{
		go[x][y]=mapp[x][y]-'0';
		dfs(nx,ny);
	}
	else
	{
		int gg=get_g(x,y);
		for(int i=1;i<10;i++)
		{
			if(r[x][i]==0 && c[y][i]==0 && grid[gg][i]==0)
			{
				r[x][i]=c[y][i]=1;
				go[x][y]=i;
				grid[gg][i]=1;
				dfs(nx,ny);
				
				if(flag==1) return 0;
				go[x][y]=0;
				r[x][i]=c[y][i]=grid[gg][i]=0;
			}
		}
	}
	return 0;

}
