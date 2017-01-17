#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=2e5+9;

map<string,int> aha;

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		aha.clear();
		string ok;
		for(int i=0;i<n;i++)
		{
			cin>>ok;
			aha[ok]++;
		}
		int cnt=0;
		for(int i=0;i<m;i++)
		{
			cin>>ok;
			if(aha[ok]!=0) cnt++;
		}
		int flag;
		if(cnt%2==0)
		{
			if(n-cnt<=m-cnt) flag=0;
			else flag=1;
		}
		else
		{
			if(n-cnt>=m-cnt) flag=1;
			else flag=0;
		}

		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

