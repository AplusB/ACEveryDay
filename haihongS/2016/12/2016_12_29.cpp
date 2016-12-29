#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e4+60;
const ll inf=2e9+9;

char a[maxn],b[maxn],cnt[maxn];

int main()
{
	while(~scanf("%s",a))
	{
		memset(cnt,0,sizeof(cnt));
		int len=strlen(a);
		int v=0,pos=0;
		for(int i=len-1;i>=0;i--)
		{
			cnt[a[i]-'0']++;
			v+=(a[i]-'0')*2;
			b[pos++]=v%10+'0';
			v/=10;
		}
		if(v!=0) b[pos++]=v+'0';
		for(int i=0;i<pos;i++)
		{
			cnt[b[i]-'0']--;
		}
		int flag=1;
		for(int i=0;i<10;i++)
		{
			if(cnt[i]!=0)
			{
				flag=0;break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
		for(int i=pos-1;i>=0;i--)
			printf("%c",b[i]);
	}
	return 0;
}
