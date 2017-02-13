#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;


int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		char s[200];
		scanf("%s",s);
		int len=strlen(s);
		int g,t;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='G') g=i;
			else if(s[i]=='T') t=i;
		}
		int flag=0,step;
		if(g<t) step=k;
		else step=-k;
		for(int i=g;i<len && i>=0;i+=step)
		{
			if(s[i]=='#') break;
			if(s[i]=='T')
			{
				flag=1;break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
		
	}
	return 0;
}
