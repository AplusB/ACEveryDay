//预处理一发，第10000个素数是104729，>1e5&&<1e6

#include<cstdio>
#include<math.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N=1e4+10;

LL a[1000010]; 
bool isPrime[1000010];
void sushu()
{
	fill(isPrime, isPrime + 1000001, true);
    for(int i = 2; i <= 1000000; ++i)
    {
        if(!isPrime[i])
            continue;
        for(int j = i + i; j <= 1000000; j += i)
        {
            isPrime[j]=false;
        }
    }
    int num=0;
    for(int i=2;i<=1000000;i++)
	{
		if(isPrime[i])
			a[++num]=(LL)i;
	}
	printf("%lld\n",a[10000]);
}
int main()
{
	int t;
	sushu();
	scanf("%d",&t);

	while(t--)
	{
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]*a[n]-n);
	}
	return 0;
}

