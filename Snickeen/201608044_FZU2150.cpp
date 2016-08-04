//#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;
typedef int LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
template<typename T>inline void gt(T x){
	if(!x)return;
	gt(x/10);putchar(x%10+'0');
}

struct TT{
	LL a,b;
}v[5],tt,ss;
LL t,n,m,ans,res,cnt[3];
LL MOD=1e9+7;
char maze[13][13];
LL vis[13][13],dp[13][13],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
queue<TT> q;

void bfs(LL x,LL y){
	LL i,j,k,l;
	tt.a=x;tt.b=y;vis[x][y]=ans;q.push(tt);
	while(!q.empty()){
		ss=q.front();q.pop();
		for(i=0;i<4;i++){
			x=ss.a+dx[i];y=ss.b+dy[i];
			if(x<0||x>=n||y<0||y>=m)continue;
			if(maze[x][y]=='#'&&!vis[x][y]){tt.a=x;tt.b=y;vis[x][y]=ans;q.push(tt);}
		}
	}
}

void bfs2(LL x,LL y){
	LL i,j,k,l;res=1;
	tt.a=x;tt.b=y;dp[x][y]=1;q.push(tt);
	while(!q.empty()){
		ss=q.front();q.pop();
		for(i=0;i<4;i++){
			x=ss.a+dx[i];y=ss.b+dy[i];
			if(x<0||x>=n||y<0||y>=m)continue;
			if(maze[x][y]=='#'&&!dp[x][y]){
				tt.a=x;tt.b=y;q.push(tt);
				dp[x][y]=dp[ss.a][ss.b]+1;
				res=max(res,dp[x][y]);
			}
		}
	}
}

int main()
{
	LL ca=0,i,j,k,l;
	scanf("%d",&t);
	while(t--){
		CC(vis);CC(dp);CC(maze);ans=0;cnt[0]=cnt[1]=cnt[2]=MOD;
		scanf("%d%d",&n,&m);
		rep(i,0,n)scanf("%s",maze[i]);
		rep(i,0,n)rep(j,0,m)if(maze[i][j]=='#'&&!vis[i][j]){
			ans++;
			while(!q.empty())q.pop();
			bfs(i,j);
		}
		if(ans>2)ans=-1;
		else if(ans==1){
			ans=MOD;
			rep(i,0,n)rep(j,0,m)if(maze[i][j]=='#'){
				rep(k,0,n)rep(l,0,m)if(maze[k][l]=='#'){
					CC(dp);while(!q.empty())q.pop();
					tt.a=i;tt.b=j;q.push(tt);dp[i][j]=1;
					bfs2(k,l);
					ans=min(ans,res-1);
				}
			}
		}
		else if(ans==2){
			rep(i,0,n)rep(j,0,m)if(maze[i][j]=='#'){
				CC(dp);while(!q.empty())q.pop();
				bfs2(i,j);
				cnt[vis[i][j]]=min(res-1,cnt[vis[i][j]]);
			}
			ans=max(cnt[1],cnt[2]);
		}
		printf("Case %d: %d\n",++ca,ans);
	}
	return 0;
}

/*

1
5 5
.....
#####
.#.#.
##...
.###.

*/
