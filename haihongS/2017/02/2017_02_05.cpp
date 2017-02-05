#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=300+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

char a[maxn][maxn],ans[maxn],b[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		int len=300;
		cin.get();
		for(int i=0;i<n;i++)
		{
			gets(b);
			int tmp=strlen(b);
			len=min(len,tmp);
			for(int j=0;j<tmp;j++)
				a[i][j]=b[tmp-j-1];
		}
		int pos=0,flag=1;
		while(flag && pos<len)
		{
			char now=a[0][pos];
			for(int i=1;i<n;i++)
			{
				if(a[i][pos]!=now)
				{
					flag=0;break;
				}
			}
			if(flag)
				ans[pos++]=now;
		}
		if(strlen(ans)!=0) flag=1;
		if(flag)
		{
			int now=strlen(ans);
			for(int i=now-1;i>=0;i--) printf("%c",ans[i]);
			printf("\n");
		}
		else puts("nai");
	}
	return 0;
}
