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
typedef long long  LL;
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
 
const LL MAXN=5e5+10;
LL t,n,m,ans,tot;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

char a[MAXN];

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r,ca=0,u=0,v=0,w;
	cin>>n;
	if(n<4)return cout<<"NO",0;
	cout<<"YES"<<endl; 
	if(n==4){
		cout<<"1 * 2 = 2\n";
		cout<<"2 * 3 = 6\n";
		cout<<"4 * 6 = 24\n"; 
	}
	else if(n==5){
		cout<<"3 * 5 = 15\n";
		cout<<"2 * 4 = 8\n";
		cout<<"15 + 8 = 23\n";
		cout<<"1 + 23 = 24\n";
	}
	else {
		cout<<"5 - 2 = 3\n";
		cout<<"3 - 3 = 0\n";
		cout<<"0 * 1 = 0\n";
		repu(i,7,n)cout<<"0 * "<<i<<" = 0\n";
		cout<<"0 + 4 = 4\n";
		cout<<"4 * 6 = 24\n";
	}
	return 0;
}

