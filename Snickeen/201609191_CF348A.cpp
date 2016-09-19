#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
using namespace std;
typedef long long LL;

const LL MAXN = 3e5+10;
LL t,n,m,ans;
LL f[MAXN];

LL check(LL x){
	LL i,res=0;
	for(i=1;i<=n;i++){
		res+=x-f[i];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i],ans=max(ans,f[i]);
	l=ans;r=1e10;
	while(l<r){
		m=l+(r-l)/2;
		if(check(m)<m){
			l=m+1;
		}
		else r=m;
	}
	ans=l;
	cout<<ans<<endl;
	return 0;
}
