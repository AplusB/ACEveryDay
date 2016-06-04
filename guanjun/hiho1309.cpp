/* ***********************************************
Author        :guanjun
Created Time  :2016/6/4 22:09:06
File Name     :hiho1309.cpp
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
int x[maxn];
int y[maxn];
set<int>s;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		s.insert(x[i]);
		s.insert(y[i]);
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	int l=1;
	int r=1;
	int ans=0,now=0;
	for(int i:s){
		while(l<=n&&i==x[l])l++,now++;
		while(r<=n&&i==y[r])r++,now--;
		ans=max(ans,now);
	}
	cout<<ans<<endl;
    return 0;
}
