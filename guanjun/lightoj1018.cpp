/* ***********************************************
Author        :guanjun
Created Time  :2016/6/22 20:44:30
File Name     :1018.cpp
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
#define maxn 1000010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

int dp[maxn],n,l[20][20];
struct node{
	int x,y;
}nod[20];
bool Gx(node a,node b,node c){
	//int tmp=(a.x*b.y-a.y*b.x)+(b.x*c.y-b.y*c.x)+(c.x*a.y-c.y*a.x);
	//if(tmp==0)return true;
	if((a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)==0)return true;
	return false;
}
int dfs(int s){
	if(dp[s]!=INF)return dp[s];
	int cnt=0;
	for(int i=0;i<n;i++)if(s&(1<<i))cnt++;
	if(cnt==0)return 0;
	if(cnt<=2)return 1;
	for(int i=0;i<n;i++){
		if(s&(1<<i)){
			for(int j=i+1;j<n;j++){
				if(s&(1<<j))
					dp[s]=min(dp[s],dfs(s-(s&l[i][j]))+1);
			}
			break;
		}
	}
	return dp[s];
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
		cin>>n;
		for(int i=0;i<n;i++)scanf("%d %d",&nod[i].x,&nod[i].y);
		for(int i=0;i<n;i++)l[i][i]=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				l[i][j]=(1<<i)|(1<<j);
				for(int k=0;k<n;k++){
					if(Gx(nod[i],nod[j],nod[k]))
						l[i][j]|=(1<<k);
					l[j][i]=l[i][j];
				}
			}
		}
		int top=1<<n;
		memset(dp,INF,sizeof dp);
		dp[0]=0;
		printf("Case %d: %d\n",t,dfs(top-1));
	}
    return 0;
}
