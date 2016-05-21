/* ***********************************************
Author        :guanjun
Created Time  :2016/5/12 21:20:37
File Name     :day5b.cpp
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
#define maxn 101000
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

int n,m,a[maxn];
int cnt[maxn];
int Left[maxn];
int Right[maxn];
int dp[maxn][25];
void RMQ_init(int*a){
	for(int i=0;i<n;i++)dp[i][0]=a[i+1];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)-1<n;i++){
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}
int RMQ(int l,int r){
	int k=0;
	while((1<<(k+1))<=r-l+1)k++;
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	while(cin>>n&&n){
		cin>>m;
		a[0]=INF;
		cle(cnt);
		int x=1,y=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=a[i-1]){
				cnt[i]=1;
				x=i;
			}
			else {
				cnt[i]=cnt[i-1]+1;
			}
			Left[i]=x;
		}
		for(int i=n;i>=1;i--){
			Right[i]=y;
			if(a[i-1]!=a[i])y=i-1;
		}
		RMQ_init(cnt);
		//cout<<RMQ(1,10)<<" "<<RMQ(1,1)<<endl;
		int ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(Left[x]==Left[y])ans=y-x+1;
			else if(Right[x]+1==Left[y])ans=max(y-Left[y]+1,Right[x]-x+1);
			else{
				int k=RMQ(Right[x],Left[y]-1);
				ans=max(max(Right[x]-x+1,y-Left[y]+1),k);
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}
