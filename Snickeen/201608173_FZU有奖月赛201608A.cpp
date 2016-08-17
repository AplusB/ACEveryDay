//#include<bits/stdc++.h>
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
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second

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

const LL N=1005;
struct NODE{
	LL x,y,z;
}tt;
LL t,n,m,ans;
LL MOD=1e9+7;

LL qp(LL x,LL b){
	LL res=1;
	while(b){
		if(b&1)res=res*x%MOD;
		b>>=1;
		x=x*x%MOD;
	}
	return res;
}

LL C(LL p,LL q){
	LL i,j,k,l,res=1,cnt=1;
	q=min(q,p-q);
	for(i=p,j=1;j<=q;j++,i--){
		res=res*i%MOD;
		cnt=cnt*j%MOD;
	}
	k=res*qp(cnt,MOD-2)%MOD;
//	cout<<res<<" "<<cnt<<" "<<k<<endl;
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r,ca=0,T,a,d;
	while(cin>>a>>d>>m>>i){
		if(i==1){
			cout<<a<<endl;
			continue;
		}
		ans=a*C(m+i-1,i-1)%MOD+d*C(m+i-1,i-2)%MOD;
		ans=(ans%MOD+MOD)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
