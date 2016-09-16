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
 
const LL MAXN=1e5+5;
LL MOD=1e9+7,inf=0x3f3f3f3f;
LL t,n,m,ans;
LL a,b,c,d,e,f,cnt[5];
LL dx[]={1,-1,0,0},dy[]={0,0,1,-1};

LL Length(LL x,LL y){return x*x+y*y;}
LL get(LL x,LL y,LL x2,LL y2){return Length(x-x2,y-y2);}
LL check(LL a,LL b,LL c,LL d,LL e,LL f){
	cnt[1]=get(a,b,c,d);
	cnt[2]=get(a,b,e,f);
	cnt[3]=get(c,d,e,f);
	sort(cnt+1,cnt+4);
	if(cnt[1]+cnt[2]==cnt[3]&&cnt[1])return 1;
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,x,y,u,v;
	cin>>a>>b>>c>>d>>e>>f;
	ans=check(a,b,c,d,e,f);
	if(ans)return cout<<"RIGHT"<<endl,0;
	repu(i,0,3)ans+=check(a+dx[i],b+dy[i],c,d,e,f);if(ans)return cout<<"ALMOST"<<endl,0;
	repu(i,0,3)ans+=check(a,b,c+dx[i],d+dy[i],e,f);if(ans)return cout<<"ALMOST"<<endl,0;
	repu(i,0,3)ans+=check(a,b,c,d,e+dx[i],f+dy[i]);if(ans)return cout<<"ALMOST"<<endl,0;
	cout<<"NEITHER"<<endl;
	return 0;
}
