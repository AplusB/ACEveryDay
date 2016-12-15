#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e4+100;

int sg(int x)
{
	if(x%4==0)
		return x-1;
	if(x%4==3)
		return x+1;
	return x;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			ans^=sg(x);
		}
		if(ans==0)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}
