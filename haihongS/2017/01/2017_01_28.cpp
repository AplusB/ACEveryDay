#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const ll inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

char a1[maxn],a2[maxn];
int n;

struct II
{
	int ex;
	string ans;
};

II deal(char *x);

int main()
{
	while(~scanf("%d %s %s",&n,a1,a2))
	{
		II x1,x2;
		x1=deal(a1);
		x2=deal(a2);
		if(x1.ans[0]=='0') x1.ex=0;
		if(x2.ans[0]=='0') x2.ex=0;
		int flag=0;
		if(x1.ex==x2.ex && x1.ans==x2.ans) flag=1;
		if(flag)
			printf("YES 0.%s*10^%d\n",x1.ans.c_str(),x1.ex);
		else 
			printf("NO 0.%s*10^%d 0.%s*10^%d\n",x1.ans.c_str(),x1.ex,x2.ans.c_str(),x2.ex);
	}
	return 0;
}

II deal(char *x)
{
	string ans="";
	int pos=0,len=strlen(x);
	while(pos<len && x[pos]=='0') pos++;
	int ex=0,cnt=0;
	if(pos<len && x[pos]=='.')
	{
		pos++;
		while(pos<len && x[pos]=='0')
		{
			pos++;
			ex--;
		}
		while(pos<len)
		{
			ans+=x[pos];
			pos++,cnt++;
		}
		while(cnt<n)
		{
			ans+='0';
			cnt++;
		}
	}
	else
	{
		while(x[pos]!='.' && pos<len)
		{
			ans+=x[pos];
			pos++,cnt++,ex++;
		}
		pos++;
		while(pos<len)
		{
			ans+=x[pos];
			pos++,cnt++;
		}
		while(cnt<n)
		{
			ans+='0';
			cnt++;
		}
	}
	II now;
	now.ex=ex;
	now.ans=ans.substr(0,n);
	return now;
}
