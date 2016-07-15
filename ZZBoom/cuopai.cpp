// hdoj 1465
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

const int N=1e3+10;

LL a[25];

void INIT()
{
	int i;
	a[2]=1;
	a[3]=2;
	for(i=4;i<=20;i++){
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	}
}

int main()
{
	int n;
	INIT();
	while(~scanf("%d",&n))
	{
		cout<<a[n]<<endl;
	}
		
	return 0;
}
