#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VL vector<long long>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
 
template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
template<typename T>inline void gt(T x){
	if(!x)return;
	gt(x/10);putchar(x%10+'0');
}
 
const LL MAXN=2e5+10;
LL t,n,m,ans,u,v;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

VLL e;
struct NODE{
	LL n,i;
	bool operator < (const NODE &a) const {
		return (abs(n)>abs(a.n))||(abs(n)==abs(a.n)&&i>a.i);
	} 
};
priority_queue<NODE> q; 
NODE node;

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0;
	cin>>n>>m>>t;
	repu(i,1,n){
		cin>>node.n;
		ca^=(node.n<0LL);
		node.i=i;
		q.push(node);
	}
	if(!ca){
		node=q.top();
		l=node.n>=0?1:-1;k=l;
		while(m&&k==l){
			node=q.top();q.pop();
			node.n+= node.n<0?t:-t;
			m--;
			k=node.n<0?-1:1;
			q.push(node);
		}
	}
	//cout<<m<<endl;
	while(m){
		node=q.top();q.pop();
		node.n+=node.n<0?-t:t;
		m--;
		q.push(node);
	}
	while(!q.empty()){
		node=q.top();q.pop();
		e.pb(mp(node.i,node.n));
	}
	sort(all(e));
	for(auto &x:e)cout<<x.second<<" "; 
	return 0;
}
