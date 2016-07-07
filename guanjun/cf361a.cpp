/* ***********************************************
Author        :guanjun
Created Time  :2016/7/7 22:40:13
File Name     :cf361.cpp
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
int a[maxn];
int b[4][3]={
	1,2,3,
	4,5,6,
	7,8,9,
	INF,0,INF
};
map<int,pair<int,int> >mp;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			mp[b[i][j]]={i,j};
		//	cout<<b[i][j]<<endl;
		}
	}
	vector<pair<int,int> >v;
	int t=1;
	for(int i=2;i<=n;i++){
		int x=mp[a[i]].first-mp[a[t]].first;
		int y=mp[a[i]].second-mp[a[t]].second;
		v.push_back({x,y});
		t=i;
	}
	int ans=0;
	int m=v.size();
	for(int i=0;i<m;i++){
	//	cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(b[i][j]==INF)continue;
			int k;
			int ox=i;
			int oy=j;
			for(k=0;k<m;k++){
				int x=ox+v[k].first;
				int y=oy+v[k].second;
				if(x>=4||y>=3||x<0||y<0)break;
				if(b[x][y]==INF)break;
				ox=x;
				oy=y;
			}
			if(k==m)ans++;

		}
	}
	//cout<<ans<<endl;
	if(ans>1)puts("NO");
	else puts("YES");

    return 0;
}
