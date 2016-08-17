/* ***********************************************
Author        :guanjun
Created Time  :2016/8/17 13:55:10
File Name     :hdu5855.cpp
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
struct Edge{
	int from,to,cap,flow;
};
struct node{
	int n,m,s,t;//节点数 边数 源点 汇点
	vector<Edge>edges;
	vector<int>G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	void init(int n,int s,int t){
		this->n=n;
		this->s=s;
		this->t=t;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
		m=0;
	}
	void addEdge(int from,int to,int cap){
		edges.push_back({from,to,cap,0});
		edges.push_back({to,from,0,0});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool BFS(){
		memset(vis,0,sizeof vis);
		queue<int>que;
		que.push(s);
		d[s]=0;
		vis[s]=true;
		while(!que.empty()){
			int x=que.front();que.pop();
			for(int i=0;i<G[x].size();i++){
				Edge&e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=true;
					d[e.to]=d[x]+1;
					que.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int DFS(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		for(int& i=cur[x];i<G[x].size();i++){
			Edge& e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t){
		this->s=s;
		this->t=t;
		int flow=0;
		while(BFS()){
			memset(cur,0,sizeof cur);
			flow+=DFS(s,INF);
		}
		return flow;
	}
}ac;
struct Node{
	int cost,time;
}nod[300];

int shop[300][300];
int mon[300];
int TT,n,m,T,S,L;

int judge(int n,int m,int lim){
	T=n+m+1;
	S=0;
	int tot=0;
	ac.init(m+n+2,S,T);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=shop[i][0];j++)
			ac.addEdge(i,m+shop[i][j],INF);
		ac.addEdge(S,i,mon[i]);
		tot+=mon[i];
	}
	for(int i=1;i<=n;i++){
		if(nod[i].time<=lim){
			ac.addEdge(i+m,T,nod[i].cost);
		}
		else ac.addEdge(i+m,T,INF);
	}
	tot-=ac.Maxflow(S,T);
	return tot;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);

	cin>>TT;
	for(int t=1;t<=TT;t++){
		scanf("%d%d%d",&n,&m,&L);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&nod[i].cost,&nod[i].time);
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d",&mon[i],&shop[i][0]);
			for(int j=1;j<=shop[i][0];j++){
				scanf("%d",&shop[i][j]);
			}
		}
		int l=1,r=1000000000;
		int ans=0;
		while(l<r){
			int mid=(r+l)/2;
			ans=judge(n,m,mid);
			if(ans>=L){
				r=mid;
			}
			else l=mid+1;
		}
		ans=judge(n,m,l);
        printf("Case #%d: ",t);
        if(ans>=L)
            printf("%d %d\n",l,ans);
        else
            puts("impossible");
	}
    return 0;
}
