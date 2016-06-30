/* ***********************************************
Author        :guanjun
Created Time  :2016/6/30 23:24:27
File Name     :1025.cpp
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
ll dp[100][100];
char s[100];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%s",s+1);
		int n=strlen(s+1);
		cle(dp);
		for(int len=1;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
				if(s[i]==s[j])dp[i][j]+=dp[i+1][j-1]+1;
			}
		}
		printf("Case %d: %lld\n",t,dp[1][n]);
	}
    return 0;
}
