/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,n,m,ans;
LL f[5][5],v[5];

int main()
{
	LL i,j,k,l,ca=0;
	for(i=1;i<4;i++)for(j=1;j<4;j++)cin>>f[i][j],v[i]+=f[i][j];
	m=max(v[1],max(v[2],v[3]))+1;
	for(i=1;i<4;i++)f[i][i]=m-v[i];
	n=(v[2]-f[1][1]-f[3][3])/2;
	for(i=1;i<4;i++)f[i][i]+=n;
	for(i=1;i<4;i++){
		for(j=1;j<4;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
