#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef int  LL;

const LL N=100000+5,M=700000+5;
LL MOD=1e9+7;
LL t,n,ans;

LL ff[N];

LL check(LL m)
{
	LL i,j,k=0;
	j=(LL)sqrt(m);
	for(i=1;i<=j;i++){
		if(m%i==0) k+=i,k+=m/i;
	}
	if(j*j==m) k-=j;
	return k-m;
}

int main()
{
	LL i,j,k,l,ans=0;
//	for(i=2;i<N;i++){
//		ff[i]=check(i);
//		if(i!=ff[i]&&ff[i]<=1e5&&check(ff[i])==i)cout<<i<<endl;
//		else ff[i]=0;
//	}
//	for(i=2;i<N;i++)ff[i]+=ff[i-1];
	int a[33]={220,284,1184,1210,2620,2924,5020,5564,6232,6368,
			10744,10856,12285,14595,17296,18416,63020,66928,66992,67095,
			69615,71145,76084,79750,87633,88730};
	cin>>t;
	while(t--){
		cin>>n;
		for(ans=i=0;i<26;i++)if(a[i]<=n)ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
