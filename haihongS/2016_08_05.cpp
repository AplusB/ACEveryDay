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
const int maxn=2e6+100;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp%8==0)
				ans^=(tmp-1);
			else if(tmp%8==7)
				ans^=(tmp+1);
			else
				ans^=tmp;
		}
		if(ans)
			printf("First player wins.\n");
		else
			printf("Second player wins.\n");
	}
	return 0;
}
