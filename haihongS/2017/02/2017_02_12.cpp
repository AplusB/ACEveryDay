#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int main()
{
	int n,h;
	while(~scanf("%d%d",&n,&h))
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			ans+=1;
			if(x>h) ans+=1;
		}
		printf("%d\n",ans);
			
	}
	return 0;
}
