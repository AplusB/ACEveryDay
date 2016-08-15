/* ***********************************************
Author        :guanjun
Created Time  :2016/8/14 9:42:21
File Name     :cf311c.cpp
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
    bool operator()(int a,int b){
        return a>b;
	}
};
multiset<int,cmp>s;
vector<int>v[maxn];
int vis[maxn];
int x[maxn];
int y[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	cin>>n;
	int sum=0,Min=INF,Max=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&y[i]);
		v[x[i]].push_back(y[i]);
		sum+=y[i];
		s.insert(y[i]);
		Min=min(Min,x[i]);
		Max=max(Max,x[i]);
	}
	if(n==2){
		if(x[1]==x[2])cout<<0<<endl;
		else cout<<min(y[1],y[2])<<endl;return 0;
	}
	int ans=INF;
	for(int i=Max;i>=Min;i--){
		int m=v[i].size();
		if(m>0&&!vis[i]){
			vis[i]=1;
			int tmp=0,tmp2=0;
			for(int j=0;j<m;j++){
				auto pos=s.find(v[i][j]);
				s.erase(pos);
				tmp+=v[i][j];
			}
			int cnt=0;
			for(auto x:s){
				if(cnt==m-1)break;
				tmp+=x;
				cnt++;
			}
			ans=min(ans,sum-tmp);
		}
	}
	if(ans==INF){
		cout<<0<<endl;
	}
	else cout<<ans<<endl;
    return 0;
}
