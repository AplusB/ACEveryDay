/* ***********************************************
Author        :guanjun
Created Time  :2016/8/21 20:16:08
File Name     :at003b.cpp
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
int a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	ll x;
	cin>>n;
	int mark=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			ans+=a[i]/2;
			if(a[i+1]>0)a[i+1]+=(a[i]%2);
		}
	}
	cout<<ans<<endl;
    return 0;
}
