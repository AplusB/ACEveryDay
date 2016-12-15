#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e5+9;
typedef long long ll;
int num[20];

int gcd(int x,int y);

int main()
{
	for(int i=1;i<=10;i++)
	{
		num[i]=i;
	}
	int ans=num[1];
	for(int i=2;i<=10;i++)
	{
		ans=ans*num[i]/gcd(num[i],ans);
	}
	ll n;
	while(~scanf("%lld",&n))
	{
		printf("%lld\n",n/(ll)(ans));
	}
	return 0;
}

int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

