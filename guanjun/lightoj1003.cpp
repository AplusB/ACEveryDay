/* ***********************************************
Author        :guanjun
Created Time  :2016/6/7 20:22:01
File Name     :1003.cpp
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
vector<int>edge[maxn];
int m,num;
map<string,int>mp;
int in[maxn];
bool topsort(){
	int cnt=0;
	queue<int>q;
	for(int i=1;i<=num;i++)if(in[i]==0)q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		cnt++;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i];
			in[v]--;
			if(in[v]==0){
				q.push(v);	
			}
		}
	}
	if(cnt<num)return false;
	return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	string s1,s2;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>m;
		num=0;mp.clear();cle(in);
		for(int i=0;i<maxn;i++)edge[i].clear();
		for(int i=1;i<=m;i++){
			cin>>s1>>s2;
			if(!mp[s1])mp[s1]=++num;
			if(!mp[s2])mp[s2]=++num;
			edge[mp[s1]].push_back(mp[s2]);
			in[mp[s2]]++;
		}
		printf("Case %d: %s\n",t,topsort()?"Yes":"No");
	}
    return 0;
}
