/* ***********************************************
Author        :guanjun
Created Time  :2016/6/25 19:26:27
File Name     :1021.cpp
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
ll dp[(1<<16)+10][20];
int a[20];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int T,base,k;
	char s[20];
	cin>>T;
	for(int t=1;t<=T;t++){
		cle(dp);
		dp[0][0]=1;
		scanf("%d%d%s",&base,&k,s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]>='0'&&s[i]<='9')
				a[i]=s[i]-'0';
			else a[i]=s[i]-'A'+10;
		}
		int sz=1<<len;
		for(int i=0;i<sz;i++){
			for(int r=0;r<len;r++){
				if(((1<<r)&i)==0){
					for(int j=0;j<k;j++){
						dp[i|(1<<r)][(j*base+a[r])%k]+=dp[i][j];
					}
				}
			}
		}
		printf("Case %d: %lld\n",t,dp[sz-1][0]);
	}
    return 0;
}
