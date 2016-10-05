/* ***********************************************
Author        :guanjun
Created Time  :2016/9/8 15:30:01
File Name     :spoj_XMAX.cpp
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

bool cmp(ll a,ll b){
    return a>b;
}
ll a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n,cmp);
		int row=1;
		for(int i=60;i>=0;i--){
			for(int j=row;j<=n;j++){
				if(a[j]&(1LL<<i)){
					swap(a[row],a[j]);
					for(int k=1;k<=n;k++){
						if((a[k]&(1LL<<i))&&(k!=row)){
							a[k]=a[k]^a[row];
						}
						//puts("YES");
					}
					row++;
				}
			}
		}
		ll ans=0LL;
		for(int i=1;i<=n;i++){
		//	cout<<a[i]<<endl;
			ans^=a[i];
		}
		cout<<ans<<endl;
	}
    return 0;
}
