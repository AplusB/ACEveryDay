/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,n,m,ans,x,y;

int main()
{
	LL i,j,k,l,u,v;
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	u=y-n+1;
	if(u<=0||u*u+n-1<x)return 0*puts("-1");
	printf("%I64d\n",u);
	while(--n)puts("1");
	return 0;
}
