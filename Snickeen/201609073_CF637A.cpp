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
typedef long long LL;
typedef double db;
#define repu(i,a,b) for(i=a;i<=b;i++)
const int maxn = 1000000+10;
const LL MOD=1e9+7;
LL t,n,m,ans,f[maxn];

vector<LL> v;

int main()
{
	LL i,j,k,l,r;
	cin>>n;
	repu(i,1,n){
		cin>>m,f[m]++;
		if(f[m]>t){
			t=f[m];
			ans=m;
		}
	}
	cout<<ans<<endl; 
	return 0;
}
