#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,sum,x,y,a,b;
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%I64d",&n);m=n;
	while(m--){
		scanf("%I64d%I64d",&a,&b);
		sum+=a*a+b*b;
		x+=a;y+=b;
	}
	printf("%I64d\n",n*sum-x*x-y*y);
//	cout<<n*sum-x*x-y*y<<endl;
	return 0;
}
