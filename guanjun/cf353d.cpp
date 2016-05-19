/* ***********************************************
Author        :guanjun
Created Time  :2016/5/19 9:14:01
File Name     :cf353d.cpp
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
#define maxn 100100
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
int a[maxn],ans,n;
set<int>s;
map<int,int>l;
map<int,int>r;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s.insert(a[1]);
	for(int i=2;i<=n;i++){
		auto it=s.lower_bound(a[i]);
		if(l[*it]==0&&it!=s.end()){
			ans=*it;//左孩子
			l[*it]=a[i];
		}
		else{//右孩子
			it--;
			ans=*it;
			r[*it]=a[i];
		}
		s.insert(a[i]);
		printf("%d\n",ans);
	}
    return 0;
}
/*
5
4 1 5 3 2
*/
