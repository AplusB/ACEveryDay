//#include<bits/stdc++.h>
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
 
const LL maxn=1e3+10;
LL MOD=1e9+7,inf=0x1f1f1f1f,mod=998244353;
db eps=1e-5;
LL t,n,m,q,ans,cnt[11];
LL d1x[]={-2,-2,-2,-1,-1,-1,0,0,0},d1y[]={-2,-1,0,-2,-1,0,-2,-1,0},
	d2x[]={0,0,0,1,1,1,2,2,2},d2y[]={0,1,2,0,1,2,0,1,2};
struct NODE{
	LL a,b,x,y;
};
map<PLL,LL> ma;
NODE tt;

bool check(LL a,LL b){
	if(a<1||a>n||b<1||b>m)return 1;
	return 0;
}

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v;
	cin>>n>>m>>q;
	cnt[0]=(n-2)*(m-2);
	repu(i,1,q){
		cin>>u>>v;
		repu(j,0,8){
			tt.a=u+d1x[j];
			tt.b=v+d1y[j];
			tt.x=u+d2x[j];
			tt.y=v+d2y[j];
			if(check(tt.a,tt.b)||check(tt.x,tt.y))continue;
			k=ma[mp(tt.a,tt.b)]++;
			cnt[k]--;
			cnt[k+1]++;
		}
	}
	repu(i,0,9)cout<<cnt[i]<<endl;
	return 0;
}
