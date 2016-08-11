/* ***********************************************
Author        :guanjun
Created Time  :2016/8/11 12:36:48
File Name     :p806.cpp
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
#define maxn 100010
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
int n,m,d;
double c,v[maxn],x;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	cin>>t;
	while(t--){
		scanf("%d %lf",&n,&c);
		for(int i=1;i<=n;i++){
			scanf("%lf %lf %d",&v[i],&x,&d);
		}
		sort(v+1,v+1+n);
		scanf("%d",&m);
		double T;int k;
		for(int i=1;i<=m;i++){
			scanf("%lf %d",&T,&k);
			printf("%.3f\n",sqrt(2.*c*T+v[k]*v[k]));
		}
	}
    return 0;
}
