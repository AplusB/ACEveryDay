

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int MAXN=1100;

const int N=1e5+10;


int main()
{
	int n,m;
	cin>>n>>m;
	int sum=0,flag;
	if(n>2)
        flag=1;
	else if(m>2)
        flag=0;
	if(n<2&&m<2)
	{
        puts("0");
	    return 0;
	}
	if(n<=2&&m<=2)
    {
        puts("1");
        return 0;
    }
	while(1)
	{
		if(flag==1)
		{
			n-=2;
			m+=1;
			sum+=1;
			if(n>2)
			flag=1;
			else
			flag=0;
		}
		else
		{
			m-=2;
			n+=1;
			sum+=1;
			if(m>2)
			flag=0;
			else
			flag=1;
		}
		if(n<=2&&m<=2)
		{
			sum+=1;
			break;
		}
	}
	cout<<sum<<endl;
}


