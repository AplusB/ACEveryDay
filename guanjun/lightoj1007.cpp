/* ***********************************************
Author        :guanjun
Created Time  :2016/6/10 19:35:28
File Name     :1007.cpp
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
#define maxn 5000100
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
int phi[maxn];
ull sum[maxn];
void phi_table(int n){
	for(int i=2;i<=n;i++)phi[i]=0;
	phi[1]=1;
	for(int i=2;i<=n;i++)if(!phi[i]){
		for(int j=i;j<=n;j+=i){
			if(!phi[j])phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
	sum[1]=0;
	for(int i=2;i<=maxn;i++){
		sum[i]=sum[i-1]+(ull)phi[i]*phi[i];
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    phi_table(maxn);
	int T,a,b;
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d%d",&a,&b);
		printf("Case %d: %llu\n",t,sum[b]-sum[a-1]);
	}
    return 0;
}
