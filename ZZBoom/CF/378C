#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

#define N 520

bool vis[N][N];
char ma[N][N];
int n,m,k;

void DFS(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||vis[x][y]||ma[x][y]=='#')
		return;
	
	vis[x][y]=1; 
	//一直搜到底啊 
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);
	
	
	if(!k)
		return;
	
	ma[x][y]='X';
	--k;
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++)
		scanf("%s",ma[i]);
	
	int flag=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]=='.')
			{
				DFS(i,j);
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	
	for(int i=0;i<n;i++)
		printf("%s\n",ma[i]);
	
	
} 





