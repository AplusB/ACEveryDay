#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=300+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		if(a==0 && b==0)
		{
			puts("NO");continue;
		}
		if(abs(a-b)>=2) puts("NO");
		else puts("YES");
	}
	return 0;
}
