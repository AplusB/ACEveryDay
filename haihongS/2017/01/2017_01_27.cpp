#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;

int a[maxn];
map<int,int> aha;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		aha.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			aha[a[i]]++;
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(aha[a[i]]==1)
			{
				flag=1;
				printf("%d\n",a[i]);
				break;
			}
		}
		if(flag==0) printf("None\n");
	}
	return 0;
}
