#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=4000+900;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int cnt=0;
		int last=-1;
		while(n--)
		{
			char op[5];
			scanf("%s",op);
			if(op[0]=='S')
			{
				cnt++;
				last=-1;
			}
			else if(op[0]=='C')
			{
				int v;
				scanf("%d",&v);
				if(v==1) cnt++;
				last=v;
			}
			else if(op[0]=='B')
			{
				int v;
				scanf("%d",&v);
				if(v==1) cnt++;
				last=v;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

