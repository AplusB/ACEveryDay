/* ***********************************************
Author        :guanjun
Created Time  :2016/6/6 18:42:59
File Name     :1002.cpp
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
int edge[510][510];
int w[510][510];
int vis[510],lowcost[510];
int n,m,k;
int dis[maxn];
void prime(){
	memset(dis,-1,sizeof dis);
	dis[k]=0;
	cle(vis);
	vis[k]=1;
	for(int i=0;i<n;i++){
		lowcost[i]=edge[k][i];
	}
	int Min,x;
	while(1){
		Min=INF;
		for(int i=0;i<n;i++){
			if(lowcost[i]<Min&&!vis[i]){
				Min=lowcost[i],x=i;
			}
		}
		if(Min==INF)break;
		vis[x]=1;
		dis[x]=Min;
		for(int i=0;i<n;i++){
			if(!vis[i]&&max(dis[x],edge[x][i])<lowcost[i]){
				lowcost[i]=max(edge[x][i],dis[x]);
			}
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,x,y,z;
	cin>>T;
	for(int t=1;t<=T;t++){
		printf("Case %d:\n",t);
		memset(edge,INF,sizeof edge);
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(z<edge[x][y]){
				edge[x][y]=z;
				edge[y][x]=z;
			}
		}
		cin>>k;
		prime();
		for(int i=0;i<n;i++){
			if(dis[i]==-1)puts("Impossible");
			else printf("%d\n",dis[i]);
		}
	}
    return 0;
}
