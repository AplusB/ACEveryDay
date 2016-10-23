/*
By Snickeen
*/
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
#define VL vector<LL>
#define VII vector<PII >
#define VLL vector<PLL >
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define FF first
#define SS second

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
 
const LL MAXN=2e6+10;
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

struct NODE{
	LL c;
	bool operator < (const NODE& a) const {
		return c>a.c;//||(c==a.c&&t>a.t);
	}
};
priority_queue<NODE> q;

NODE tt;
VLL f;

LL cmp(PLL a,PLL b){
	if(a.FF!=b.FF) return a.FF>b.FF;
	else return a.SS<b.SS;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v,w;
	cin>>n;
	cin>>t>>w;
	rep(i,1,n){
		cin>>u>>v;
		if(u>t)q.push({v-u+1});
		else f.pb({u,v});
	}
	k=q.size();
	ca=ans=k+1;
	sort(all(f),cmp);
	l=f.size();
	i=0;
	while(1){
		if(k==0){
			ans=1;
			break;
		}
		v=q.top().c;
		if(t>=v){
			q.pop();k--;
			t-=v;
			ca--;
			for(i;i<l;i++){
				if(f[i].FF>t){
					q.push({f[i].SS-f[i].FF+1});
					k++;
					ca++;
				}
				else break;
			}
			ans=min(ca,ans);
		}
		else {
			ca=k+1;
			ans=min(ca,ans);
			break;
		}
		//cout<<v<<"*"<<t<<"*"<<ca<<"*"<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
