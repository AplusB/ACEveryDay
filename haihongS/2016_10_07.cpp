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
#include <set>

using namespace std;
typedef long long ll;
const int maxn=50+2;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int n,m;
char mapp[maxn][maxn];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int flag[maxn][maxn];

struct II
{
	int cnt,id,x,y;
}num[maxn*maxn],inn[maxn*maxn];

void change(int x,int y);
int cmp(II x,II y);
int count(int x,int y);
void dfs(int x,int y,int f);
int main()
{
	int k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		//init
		memset(flag,0,sizeof(flag));

		for(int i=0;i<n;i++)
			scanf("%s",mapp[i]);
		int gx[2]={0,n-1},gy[2]={0,m-1};
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x=gx[i],y=j;
				if(mapp[x][y]=='*') continue;
				if(flag[x][y]!=0) continue;
				flag[x][y]=-1;
				dfs(x,y,-1);
			}
		}
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				int y=gy[i],x=j;
				if(mapp[x][y]=='*') continue;
				if(flag[x][y]!=0) continue;
				flag[x][y]=-1;
				dfs(x,y,-1);
			}
		}
		int pos=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mapp[i][j]=='*') continue;
				if(flag[i][j]!=0) continue;
				flag[i][j]=1;
				inn[pos].x=i,inn[pos].y=j;
				dfs(i,j,1);
				pos++;
			}
		}
		memset(flag,0,sizeof(flag));
		for(int i=0;i<pos;i++)
		{
			int x=inn[i].x,y=inn[i].y;
			num[i].cnt=count(x,y);
			num[i].x=x,num[i].y=y;
		}
		sort(num,num+pos,cmp);
		int del=pos-k;
		int ans=0;
		for(int i=0;i<del;i++)
		{
			int x=num[i].x,y=num[i].y;
			ans+=num[i].cnt;
			change(x,y);
		}
		printf("%d\n",ans);
		for(int i=0;i<n;i++)
		{
			printf("%s\n",mapp[i]);
		}


	}
	return 0;
}

void change(int x,int y)
{
	mapp[x][y]='*';
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if(mapp[nx][ny]=='*') continue;
		change(nx,ny);
	}
}

int cmp(II x,II y)
{
	return x.cnt<y.cnt;
}

int count(int x,int y)
{
	int now=1;
	flag[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if(mapp[nx][ny]=='*') continue;
		if(flag[nx][ny]==1) continue;
		now+=count(nx,ny);
	}
	return now;
}

void dfs(int x,int y,int f)
{
	flag[x][y]=f;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if(mapp[nx][ny]=='*') continue;
		if(flag[nx][ny]!=0) continue;
		dfs(nx,ny,f);
	}
}
