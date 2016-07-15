/* ***********************************************
Author        :guanjun
Created Time  :2016/7/15 9:48:04
File Name     :hdu4857.cpp
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
#define maxn 30010
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
vector<int>v[maxn];
vector<int>ans;
int in[maxn],n,m;
void topsort(){
	priority_queue<int>q;
	for(int i=1;i<=n;i++){
		if(in[i]==0)q.push(i);
	}
	int num=0;
	while(!q.empty()){
		int u=q.top();q.pop();
		ans.push_back(u);
		for(int i=0;i<v[u].size();i++){
			int x=v[u][i];
			in[x]--;
			if(in[x]==0){
				q.push(x);
			}
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)v[i].clear();
		cle(in);
		ans.clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[y].push_back(x);
			in[x]++;
		}
		topsort();
		for(int i=ans.size()-1;i>=0;i--){
			printf("%d%c",ans[i],i==0?10:' ');
		}
	}
    return 0;
}
