#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=20+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

char a[maxn][maxn];

int judge();

int main()
{
	memset(a,0,sizeof(a));
	while(~scanf("%s",a[0]))
	{
		for(int i=1;i<4;i++)
			scanf("%s",a[i]);
		int flag=0;
		for(int i=0;i<4;i++)
		{
			if(flag) break;
			for(int j=0;j<4;j++)
			{
				if(flag) break;
				if(a[i][j]=='.')
				{
					a[i][j]='x';
					flag=judge();
					a[i][j]='.';
				}
			}
		}
		if(flag) puts("YES");
		else puts("NO");

		memset(a,0,sizeof(a));
	}
	return 0;
}


int judge()
{
	int flag=0;
	for(int i=0;i<4;i++)
	{
		if(flag) break;
		for(int j=0;j<4;j++)
		{
			if(flag) break;
			if(a[i][j]=='x')
			{
				if(a[i][j+1]=='x' && a[i][j+2]=='x') flag=1;
				if(a[i+1][j]=='x' && a[i+2][j]=='x') flag=1;
				if(a[i+1][j+1]=='x' && a[i+2][j+2]=='x') flag=1;
				if(j>=2 && a[i+1][j-1]=='x' && a[i+2][j-2]=='x') flag=1;
			}
		}
	}
	return flag;
}
