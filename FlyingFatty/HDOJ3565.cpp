#include<map>
#include<set>
#include<math.h>
#include<time.h>
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define ll rt<<1
#define rr rt<<1|1
#define LL long long
#define ULL unsigned long long
#define maxn 1050
#define maxnum 1000050
#define eps 1e-6
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define MOD 1000000007

bool vis[25][10][15];
int dp[25][10][15];
int digitlow[25],digitup[25];

int dfs(int pos,int state,int pre,bool lowbound,bool upbound){
	if (state==0&&pos<6) return -1;
	if (pos==0) return state==5?0:-1;
	if (lowbound&&upbound&&vis[pos][state][pre])
		return dp[pos][state][pre];
	int Min=lowbound?0:digitlow[pos];
	int Max=upbound?9:digitup[pos];
	int ret=-1,temp;
	for(int i=Min;i<=Max;i++)
		switch(state){
			case 0:temp=dfs(pos-1,(i==0?0:1),i,lowbound||i>Min,upbound||i<Max);
			if (temp!=-1)
				ret=max(ret,temp+i);
			break;
			case 1:
			if (i>pre){
				temp=dfs(pos-1,1,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
				temp=dfs(pos-1,2,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			break;
			case 2:
			if (i<pre){
				temp=dfs(pos-1,3,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			break;
			case 3:
			if (i<pre){
				temp=dfs(pos-1,3,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			if (i){
				temp=dfs(pos-1,4,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			break;
			case 4:
			if (i>pre){
				temp=dfs(pos-1,4,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
				temp=dfs(pos-1,5,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			break;
			case 5:
			if (i<pre){
				temp=dfs(pos-1,5,i,lowbound||i>Min,upbound||i<Max);
				if (temp!=-1)
					ret=max(ret,temp+i);
			}
			break;
		}
	if (lowbound&&upbound){
		vis[pos][state][pre]=true;
		dp[pos][state][pre]=ret;
	}
	return ret;
}

int calc(unsigned long long x,unsigned long long y){
	memset(digitlow,0,sizeof(digitlow));
	memset(digitup,0,sizeof(digitup));
	int len1=0,len2=0;
	while(x){
		digitlow[++len1]=x%10;
		x/=10;
	}
	while(y){
		digitup[++len2]=y%10;
		y/=10;
	}
	return dfs(len2,0,0,0,0);
}

int main(){
	//input;
	int T;
	unsigned long long x,y;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%I64u%I64u",&x,&y);
		int ans=calc(x,y);
		printf("Case %d: %d\n",Case,ans==-1?0:ans);
	}
	return 0;
}
