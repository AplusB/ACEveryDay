/* ***********************************************
Author        :guanjun
Created Time  :2016/7/15 16:11:53
File Name     :USETC149.cpp
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
struct node{
	int x,y;
	int dis;
};
bool cmp(int a,int b){
    return a>b;
}
int n,m;
char mp[60][60];
int sx,sy,ex,ey;
int vis[60][60];
int dir[4][2]={1,0,0,1,0,-1,-1,0};
map<pair<int,int>,pair<int,int> >mpp;
int bfs(){
	cle(vis);
	node u={sx,sy,0};
	vis[sx][sy]=1;

	queue<node>q;
	q.push(u);
	while(!q.empty()){
		u=q.front(),q.pop();
		if(u.x==ex&&u.y==ey)return u.dis;
		node v;
		for(int i=0;i<4;i++){
			int nx=u.x+dir[i][0];
			int ny=u.y+dir[i][1];
			//cout<<v.x<<" "<<v.y<<endl;
			if(!vis[nx][ny]&&mp[nx][ny]!='#'&&nx<=n&&nx>=1&&ny<=m&&ny>=1){
				char c=mp[nx][ny];

				if(c<='z'&&c>='a'){
					v.x=mpp[{nx,ny}].first;
					v.y=mpp[{nx,ny}].second;
					v.dis=u.dis+1;
					q.push(v);
				}
				else{
					v.x=nx;v.y=ny;
					v.dis=u.dis+1;
					q.push(v);
				}
				vis[nx][ny]=1;
			}
		}
	}
	return -1;
}
vector<pair<int,int> >v[60];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int t;
	char c;
	cin>>t;
	while(t--){
		mpp.clear();
		for(int i=0;i<=55;i++)v[i].clear();

		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='L')sx=i,sy=j;
				if(c=='Q')ex=i,ey=j;
				if(c<='z'&&c>='a'){
					v[int(c-'a')].push_back({i,j});
				}
				mp[i][j]=c;
			}
		}
		for(int i=0;i<26;i++){
			if(v[i].size()==2){
				mpp[{v[i][0].first,v[i][0].second}]={v[i][1].first,v[i][1].second};
				mpp[{v[i][1].first,v[i][1].second}]={v[i][0].first,v[i][0].second};
			}
		}
		cout<<bfs()<<endl;
	}
    return 0;
}
