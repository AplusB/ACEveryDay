#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<complex>
using namespace std;
typedef int LL;
typedef double db;
#define repu(i,a,b) for(i=a;i<=b;i++)
const int maxn = 1000000+10;
const LL MOD=1e9+7;
const double PI = acos(-1.0);
LL t,n,m,ans;
LL f[105];
double fans;

int main()
{
	LL i,j,k,l,r;
	cin>>n;l=r=0;
	repu(i,1,n)cin>>f[i];
	sort(f+1,f+n+1);
	for(i=1;i<=n;i+=2)l+=f[i]*f[i];
	for(i=2;i<=n;i+=2)r+=f[i]*f[i];
	if(n&1)fans=PI*(l-r);
	else fans=PI*(r-l);
	cout<<fixed<<setprecision(9)<<fans<<endl;
	return 0;
}
