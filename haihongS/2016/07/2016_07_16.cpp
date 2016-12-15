#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=500+9;
const int inf=2e9+9;

int num[1008];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)	
			scanf("%d",&num[i]);
		int flag;
		if(n==1)
		{
			if(num[0]==1) flag=1;
			else flag=0;
		}
		else
		{
			int cnt=0;
			for(int i=0;i<n;i++)
				if(num[i]==0)
					cnt++;
			if(cnt!=1)
				flag=0;
			else
				flag=1;
		}
		if(flag==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
