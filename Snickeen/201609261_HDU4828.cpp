#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL maxn=2e6+10;
const LL MOD=1e9+7; 
LL t,n,m,ans;
LL c[maxn],ny[maxn];

int main()
{
	LL i,j,k,l,ca=0;
	c[0]=c[1]=1;ny[1]=1;
	for(i=2;i<maxn;i++)
		ny[i]=ny[MOD%i]*1LL*(MOD-MOD/i)%MOD;
	for(i=2;i<maxn;i++)
		c[i]=c[i-1]*(4*i-2)%MOD*ny[i+1]%MOD; 
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case #"<<++ca<<":\n"<<c[n]<<endl;
	}
	return 0;
}
