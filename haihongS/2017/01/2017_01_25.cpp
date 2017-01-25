#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;

int flag[maxn];

int main()
{
	int m,n,k;
	while(~scanf("%d%d%d",&m,&n,&k))
	{
		while(k--)
		{
			stack<int> aha;
			while(!aha.empty()) aha.pop();
			memset(flag,0,sizeof(flag));
			int ok=1,cnt=0;
			for(int i=0;i<n;i++)
			{
				int x;
				scanf("%d",&x);
				if(ok==0) continue;
				for(int i=1;i<=x;i++)
				{
					if(flag[i]==0)
					{
						flag[i]=1;
						aha.push(i);
						cnt++;
					}
				}
				if(aha.empty() || aha.top()!=x || cnt>m)
				{
					ok=0;continue;
				}
				aha.pop();
				cnt--;
			}
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
