/* ***********************************************
Author        :guanjun
Created Time  :2016/9/6 14:29:49
File Name     :timus1009.cpp
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
int n,k;
int dp[110][110];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    while(~scanf("%i %i",&n,&k)){

		for(int i=1;i<k;i++)dp[1][i]=1;
		dp[1][0]=0;
		int ans=0;

		for(int i=2;i<=n;i++){
			for(int j=0;j<k;j++){
				if(j==0)for(int t=1;t<k;t++)dp[i][j]+=dp[i-1][t];
				else for(int t=0;t<k;t++)dp[i][j]+=dp[i-1][t];
				//cout<<dp[2][j]<<endl;
			}
		}
		for(int i=0;i<k;i++)ans+=dp[n][i];
		cout<<ans<<endl;
	}
    return 0;
}
