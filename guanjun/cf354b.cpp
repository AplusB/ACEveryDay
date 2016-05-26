/* ***********************************************
Author        :guanjun
Created Time  :2016/5/26 0:15:51
File Name     :cf354b.cpp
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
double a[20][20];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    double n,t;
	while(cin>>n>>t){
		a[1][1]=t-1.0;
		int ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(j==1){
					if(a[i-1][j]>0)a[i][j]=a[i-1][j]/2.0;
					if(a[i][j]>=1.0)ans++;
					a[i][j]-=1;
				}
				else if(j==i){
					if(a[i-1][j-1]>0)a[i][j]=a[i-1][j-1]/2.0;
					if(a[i][j]>=1.0)ans++;
					a[i][j]-=1;			
				}
				else{
					if(a[i-1][j]>0)a[i][j]+=a[i-1][j]/2.0;
					if(a[i-1][j-1]>0)a[i][j]+=a[i-1][j-1]/2.0;
					if(a[i][j]>=1.0)ans++;
					a[i][j]-=1;
				}
			}
		}
		if(a[1][1]>=0)ans++;
		cout<<ans<<endl;
	}
    return 0;
}
