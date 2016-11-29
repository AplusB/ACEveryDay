#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

vector<int> aha[5];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<5;i++)
			aha[i].clear();
		for(int i=1;i<=n;i++)
		{
			int v;
			scanf("%d",&v);
			aha[v].push_back(i);
		}
		int ans=aha[1].size();
		ans=min(ans,(int)aha[2].size());
		ans=min(ans,(int)aha[3].size());
		printf("%d\n",ans);
		int v1=0,v2=0,v3=0;
		for(int i=0;i<ans;i++)
		{
			printf("%d %d %d\n",aha[1][v1],aha[2][v2],aha[3][v3]);
			v1++,v2++,v3++;
		}
	}
	return 0;
}
