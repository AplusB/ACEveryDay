/*
By Snickeen
*/
#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
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
typedef long long  LL;
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
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VL vector<LL>
#define VII vector<PII >
#define VLL vector<PLL >
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define FF first
#define SS second

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
 
const LL MAXN=2e6+10;
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

LL f[111],g[300000],cnt[555][555];
LL dx[]={-1,0,0,1},dy[]={0,-1,1,0};
char a[555][555],vis[555][555];
queue<PLL> q;
PLL x,y;

void bfs(){
	LL i,j,k,l;
	while(q.size()){
		x=q.front();q.pop();
		for(i=0;i<4;i++){
			j=x.FF+dx[i];
			l=x.SS+dy[i];
			if(a[j][l]!='.'|| !t)continue;
			q.push({j,l});
			a[j][l]='F';
			t--;
		}
	}
}

LL bfs_pre(LL u,LL v,LL id){
	LL i,j,k,l;
	q.push({u,v});
	cnt[u][v]=id;
	while(q.size()){
		x=q.front();q.pop();
		repu(i,0,3){
			u=x.FF+dx[i];
			v=x.SS+dy[i];
			if(a[u][v]=='.'&&cnt[u][v]==0){
				cnt[u][v]=id;
				q.push({u,v});
			}
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u=0,v,w,x,y;
	MST(a,'#');
	cin>>n>>m>>t;
	repu(i,1,n){
		cin>>a[i]+1;
		a[i][m+1]='#';
	}
	repu(i,1,n)repu(j,1,m)if(a[i][j]=='.'&&cnt[i][j]==0)bfs_pre(i,j,++ans);
	repu(i,1,n)repu(j,1,m)g[cnt[i][j]]++;g[0]=0;
	repu(i,1,ans){
		if(g[i]>u)u=g[i],v=i;
		ca+=g[i];
	}
	repu(i,1,n)repu(j,1,m)if(cnt[i][j]!=v&&a[i][j]=='.')a[i][j]='X';
	t=ca-t;
	
	repu(i,1,n){
		repu(j,1,m){
			if(a[i][j]!='.')continue;
			if(t>0){
				q.push({i,j});
				a[i][j]='F';t--;
				bfs();
			}
			break;
		}
		if(t<=0)break;
	}
	
	repu(i,1,n){
		repu(j,1,m)
			cout<<(a[i][j]=='F'?'.':(a[i][j]=='.'?'X':'#'));
		cout<<endl;
	}
	return 0;
}

