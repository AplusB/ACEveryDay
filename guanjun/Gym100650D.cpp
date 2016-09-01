/* ***********************************************
Author        :guanjun
Created Time  :2016/9/1 13:44:56
File Name     :2005d.cpp
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
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int a[1100][1100];
int b[1100][1100];
int n,m;
void bfs1(int x,int y){
	int i,j;
	for(i=x+1;i<=n&&a[i][y]==0;i++)b[i][y]=1;
	for(i=y+1;i<=m&&a[x][i]==0;i++)b[x][i]=1;
	for(i=x-1;i>=1&&a[i][y]==0;i--)b[i][y]=1;
	for(i=y-1;i>=1&&a[x][i]==0;i--)b[x][i]=1;
	i=x+1;j=y+1;
	while(i<=n&&j<=m&&a[i][j]==0)b[i++][j++]=1;
	i=x-1;j=y-1;
	while(i>=1&&j>=1&&a[i][j]==0)b[i--][j--]=1;
	i=x+1;j=y-1;
	while(i<=n&&j>=1&&a[i][j]==0)b[i++][j--]=1;
	i=x-1;j=y+1;
	while(i>=1&&j<=m&&a[i][j]==0)b[i--][j++]=1;
}
int dir[8][2]={
	1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1
};
void bfs2(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(nx<=n&&ny<=m&&nx>=1&&ny>=1){
			b[nx][ny]=1;
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int x,y,t;
	int cas=0;
	while(cin>>n>>m&&(n&&m)){
		cle(a);cle(b);
		for(int i=1;i<=3;i++){
			cin>>t;
			for(int j=1;j<=t;j++){
				scanf("%d %d",&x,&y);
				a[x][y]=i;
				b[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1){
					bfs1(i,j);
				}
				else if(a[i][j]==2){
					bfs2(i,j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!b[i][j])ans++;
		printf("Board %d has %d safe squares.\n",++cas,ans);
	}
    return 0;
}
