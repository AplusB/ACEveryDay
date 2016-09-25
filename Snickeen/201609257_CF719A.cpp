#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans;
int f[111];
int main()
{
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i];
	if(f[n]==15)puts("DOWN");
	else if(f[n]==0)puts("UP");
	else if(n==1)return 0*puts("-1");
	else if(f[n-1]<f[n])puts("UP");
	else puts("DOWN");
	return 0;
}
