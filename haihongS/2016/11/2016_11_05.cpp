#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e4+8;
const ll mod=1e6+3;

char a[200];
int up,len,ok[60];
vector<int> aha;

int judge();
int dfs(int pos,int pre);

int main()
{
	freopen("joke.in","r",stdin);
	freopen("joke.out","w",stdout);
	while(~scanf("%s",a))
	{
		len=strlen(a);
		if(len<=9) up=len;
		else
			up=(len-9)/2+9;
		memset(ok,0,sizeof(ok));
		aha.clear();
		dfs(0,0);
		int go=aha.size()-1;
		for(int i=0;i<len;i++)
		{
			printf("%d",a[i]-'0');
			for(int j=go;j>=0;j--)
			{
				if(aha[j]==i) {printf(" ");break;}
			}
		}
		printf("\n");
	}
	return 0;
}

int dfs(int pos,int pre)
{
	if(pos==len) return judge();	
	if(pre==1)
	{
		if(dfs(pos+1,0))
		{
			aha.push_back(pos);
			return 1;
		}
	}
	else
	{
		int v=a[pos]-'0';
		if(v==0) return 0;
		if(ok[v]==0)
		{
			ok[v]=1;
			if(dfs(pos+1,0))
			{
				aha.push_back(pos);return 1;
			}
			ok[v]=0;
		}
		if(pos+1<len)
		{
			v=v*10+a[pos+1]-'0';
			if(v>up) return 0;
			if(ok[v]==0)
			{
				ok[v]=1;
				if(dfs(pos+1,1)) return 1;
				ok[v]=0;
			}
		}
	}
	return 0;
}

int judge()
{
	for(int i=1;i<=up;i++)
	{
		if(ok[i]==0)
			return 0;
	}
	return 1;
}
