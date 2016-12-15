#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		int x1=0,x2=0;
		x1=min(a,b);
		a-=x1,b-=x1;
		x2=max(a/2,b/2);
		printf("%d %d\n",x1,x2);
	}
	return 0;
}
