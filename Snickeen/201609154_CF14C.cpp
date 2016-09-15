#include <bits/stdc++.h>
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
#define PLL pair<long long,long long>
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
 
const LL maxn=5e2+5;
LL t,n,m,q,ans;
LL MOD=1e9+7,inf=0x3f3f3f3f;
db eps=1e-5;
map<LL,LL> x,y;
struct Point{
	LL x,y;
}f[11];
typedef Point Vector;
Vector v[11];

LL cmp(Point a,Point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

LL check(LL a,LL b){
	LL i,j,k=0,l;
	repu(i,1,8){
		if(f[i].x==a&&f[i].y==b)k++;
	}
	return k==2;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,xmin,xmax,ymin,ymax;
	xmin=ymin=1e18;xmax=ymax=-1e18;
	repu(i,1,8){
		cin>>f[i].x>>f[i].y;
		xmin=min(xmin,f[i].x);
		xmax=max(xmax,f[i].x);
		ymin=min(ymin,f[i].y);
		ymax=max(ymax,f[i].y);
	}
	ans=0;ans+=check(xmin,ymin);ans+=check(xmax,ymin);ans+=check(xmin,ymax);ans+=check(xmax,ymax);
//	cout<<ans<<" "<<xmin<<" "<<xmax<<" "<<ymin<<" "<<ymax<<endl;
	if(ans!=4||xmin==xmax||ymin==ymax)return cout<<"NO"<<endl,0;
	for(i=1;i<8;i+=2){
		j=(i+1)/2;
		v[j].x=abs(f[i].x-f[i+1].x),v[j].y=abs(f[i].y-f[i+1].y);
		if((v[j].x==0&&v[j].y==0)||(v[j].x!=0&&v[j].y!=0))return cout<<"NO"<<endl,0;
	}
	sort(v+1,v+5,cmp);
	if(v[1].x!=v[2].x||v[1].y!=v[2].y||v[3].x!=v[4].x||v[3].y!=v[4].y)return cout<<"NO"<<endl,0;
	if(v[2].x==v[3].x&&v[2].y==v[3].y)return cout<<"NO"<<endl,0;
	cout<<"YES"<<endl;
	return 0;
}
