/* ***********************************************
Author        :guanjun
Created Time  :2016/10/15 15:43:48
File Name     :timus1018.cpp
************************************************ */
#include <bits/stdc++.h>
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
	int y;
	int val;
};

vector<node>v[110];
int sz[110],n,m,num;
int dp[110][110];
void dfs(int u,int fa){
	num++;
	sz[u]=1;
	for(int i=0;i<v[u].size();i++){
		int y=v[u][i].y;
		if(y==fa)continue;
		dfs(y,u);
		sz[u]+=sz[y];
	}
	for(int i=0;i<v[u].size();i++){
		int y=v[u][i].y;
		int val=v[u][i].val;
		if(y==fa)continue;
		for(int j=sz[u];j>1;j--){
			for(int k=1;k<j;k++){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[y][k]+val);
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
    while(cin>>n>>m){
		num=0;
		int x,y,z;
		cle(sz);
		for(int i=1;i<n;i++){
			cin>>x>>y>>z;
			v[x].push_back({y,z});
			v[y].push_back({x,z});
		}
		cle(dp);
		dfs(1,-1);
	    cout<<dp[1][m+1]<<endl;
	}
    return 0;
}
