/* ***********************************************
Author        :guanjun
Created Time  :2016/6/15 18:50:31
File Name     :1012.cpp
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
struct node{
	int x,y;
};
char mp[1100][1100];
int sx,sy;
int n,m;
int dir[4][2]={1,0,0,1,0,-1,-1,0};
int vis[1100][1100];
int bfs(){
	queue<node>q;
	cle(vis);
	node u={
		sx,sy
	};
	int ans=0;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		ans++;
		q.pop();
		node v;
		for(int i=0;i<4;i++){
			v.x=u.x+dir[i][0];
			v.y=u.y+dir[i][1];
			if(v.x<=n&&v.x>=1&&v.y<=m&&v.y>=1&&mp[v.x][v.y]=='.'&&!vis[v.x][v.y]){
				vis[v.x][v.y]=1;
				q.push(v);
			}
		}
	}
	return ans;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				if(mp[i][j]=='@')sx=i,sy=j;
			}
		}
		printf("Case %d: %d\n",t,bfs());
	}
    return 0;
}
