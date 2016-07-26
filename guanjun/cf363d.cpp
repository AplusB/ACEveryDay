/* ***********************************************
Author        :guanjun
Created Time  :2016/7/24 21:22:13
File Name     :1.cpp
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
#define maxn 200100
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
int a[maxn];
int fa[maxn];
void init(){
	for(int i=0;i<maxn;i++)
		fa[i]=i;
}
int findfa(int x){
	if(x==fa[x])return x;
	else return fa[x]=findfa(fa[x]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n;
    while(cin>>n){
		init();
		int root=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==i)root=i;
		}
		//cout<<root<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i==root)continue;
			int x=findfa(i);
			int y=findfa(a[i]);
			if(x==y){
				if(root==0)root=i;
				a[i]=root;
				ans++;
			}
			else fa[x]=y;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
	}
    return 0;
}
