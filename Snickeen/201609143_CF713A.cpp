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
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
LL f[111];
map<LL,LL> ma;
string s;
LL get(LL k){
	LL i,j,res=0;
	for(i=1;i<65&&k;i++){
		f[i]=k%10;
		f[i]&=1ll;
		k/=10;
	}
	for(i-=1;i>0;i--){
		res=res*10+f[i];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v;
	cin>>n;
	repu(i,1,n){
		cin>>s>>m;
		u=get(m);
		if(s[0]=='+')ma[u]++;
		else if(s[0]=='-')ma[u]--;
		else cout<<ma[u]<<endl;
	}
	return 0;
}
