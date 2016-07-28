/* ***********************************************
Author        :guanjun
Created Time  :2016/7/28 15:51:43
File Name     :p410.cpp
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
int d[maxn];
int a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,n,cnt;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int len=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
			else {
				a[i]-=cnt;
				int pos=lower_bound(d,d+len,a[i])-d;
				if(pos==len){
					d[len++]=a[i];
				}
				else d[pos]=a[i];
			}
		}
		printf("Case #%d: %d\n",t,len+cnt);
	}
    return 0;
}
