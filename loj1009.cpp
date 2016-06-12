/* ***********************************************
Author        :guanjun
Created Time  :2016-6-12 15:28:00
File Name     :1009.cpp
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
#define maxn 20100
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

vector<int>edge[maxn];
int vis[maxn];
int a,b;
void init(){
	cle(vis);
	a=b=0;
	for(int i=0;i<maxn;i++)edge[i].clear();
}
void dfs(int u,int k){
	vis[u]=k;
	if(k==1)a++;
	if(k==2)b++;
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(!vis[v]){
			dfs(v,3-k);
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,n,x,y;
	cin>>T;
	for(int t=1;t<=T;t++){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int ans=0;
		for(int i=1;i<maxn;i++){
			if(vis[i]==0&&edge[i].size()){
				a=0;b=0;
				dfs(i,1);
				ans+=max(a,b);
			}
		}
		
		printf("Case %d: %d\n",t,ans);
	}
    return 0;
}
