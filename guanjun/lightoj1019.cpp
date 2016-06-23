/* ***********************************************
Author        :guanjun
Created Time  :2016/6/23 22:58:19
File Name     :1019.cpp
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
int dis[200][200];
int n,m;
int lowcost[2000];
int vis[2000];
int dij(){
	cle(vis);
	vis[1]=1;
	memset(lowcost,INF,sizeof lowcost);
	for(int i=1;i<=n;i++)lowcost[i]=dis[1][i];
	lowcost[1]=0;
	int k,Min;
	for(int i=2;i<=n;i++){
		Min=INF;
		for(int j=1;j<=n;j++){
			if(lowcost[j]<Min&&!vis[j])Min=lowcost[j],k=j;
		}
		if(Min==INF)break;
		vis[k]=1;
		for(int j=1;j<=n;j++){
			if(lowcost[j]>lowcost[k]+dis[k][j]&&!vis[j])
				lowcost[j]=lowcost[k]+dis[k][j];
		}
	}
	return lowcost[n];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,x,y;
	ll z;
	cin>>T;
	for(int t=1;t<=T;t++){	
		cin>>n>>m;
		memset(dis,INF,sizeof dis);
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			if(dis[x][y]>z)dis[y][x]=dis[x][y]=z;
		}
		int ans=dij();
		if(ans==INF){
			printf("Case %d: Impossible\n",t);
		}
		else printf("Case %d: %d\n",t,ans);
		
	}
    return 0;
}
