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


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans=0;
		int minn=10000;
		for(int i=0;i<n;i++)
		{
			int a,p;
			scanf("%d%d",&a,&p);
			minn=min(minn,p);
			ans+=a*minn;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
