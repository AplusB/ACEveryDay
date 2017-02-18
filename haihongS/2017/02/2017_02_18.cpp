#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",n/2);
		if(n%2==0)
		{
			for(int i=0;i<n/2;i++)
			{
				if(i!=0) printf(" ");
				printf("2");
			}
			printf("\n");
		}
		else
		{
			int ok=0;
			for(int i=0;i<n/2-1;i++)
			{
				if(ok==1) printf(" ");
				ok=1;
				printf("2");
			}
			if(ok==1) printf(" ");
			printf("3\n");
		}
	}
	return 0;
}
