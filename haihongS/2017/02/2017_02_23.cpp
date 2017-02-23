#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll inf = 2e9 + 9;

typedef pair<double,double> P;

int a[maxn],flag[maxn];
map<int,int> aha;
vector<int> go;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		aha.clear();
		go.clear();
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			aha[a[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(aha[i]==0) go.push_back(i);
		}
		int pos=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]<=n && flag[a[i]]==0)
			{
				flag[a[i]]=1;continue;
			}
			a[i]=go[pos++];
		}

		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");

	}
	return 0;
}
