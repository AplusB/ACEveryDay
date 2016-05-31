/*
    最小生成树prim算法
*/

//#include<bits/stdc++.h>

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

struct TT{
	int edge,d,flag;
};TT tt[1];
int n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
char aa[11];

int ff[111][111],dd[111],vis[111];

int main(){
//	FIN;FOUT;
	while(~scanf("%d",&n)){
		CC(ff);CC(dd);CC(vis);
		repu(i,1,n)repu(j,1,n)in(ff[i][j]);
		repu(i,1,n){dd[i]=ff[1][i];}
		repu(i,1,n){
			mmin=(1<<29);
			repu(j,1,n){if(!vis[j]&&dd[j]<mmin){mmin=dd[j];r=j;}}
			vis[r]=1;
			repu(j,1,n){if(!vis[j]&&ff[r][j]<dd[j])dd[j]=ff[r][j];}
		}
		repu(i,1,n)dd[0]+=dd[i];
		printf("%d\n",dd[0]);
	}
	return 0;
}
