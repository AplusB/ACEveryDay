#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

string a;
int n;

int judge(char x);
int go(int pos);
void deal(int pos);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>a;
		scanf("%d",&n);
		while(n--)
		{
			int len=a.size();
			int now=go(len-1);
			if(now==0) a[len-1]++;
			else deal(len-1);
			printf("%s\n",a.c_str());
		}
		printf("\n");
	}
	return 0;
}

int go(int pos)
{
	for(int i=pos;i>=0;i--)
	{
		if(judge(a[i])) return 1;
	}
	return 0;
}

void deal(int pos)
{
	for(int i=pos;i>=0;i--)
	{
		if(judge(a[i]))
		{
			if(a[i]=='z')
			{
				a[i]='a';
				if(i==0 || go(i-1)==0) 
					a.insert(i,"a");
					//a='a'+a;
				else deal(i-1);
			}
			else if(a[i]=='Z')
			{
				a[i]='A';
				if(i==0 || go(i-1)==0)
					a.insert(i,"A");
					//a='A'+a;
				else deal(i-1);
			}
			else if(a[i]=='9')
			{
				a[i]='0';
				if(i==0 || go(i-1)==0) 
					a.insert(i,"1");
					//a='1'+a;
				else deal(i-1);
			}
			else a[i]++;
			return ;
		}
	}
}

int judge(char x)
{
	if('a'<=x && x<='z') return 1;
	if('A'<=x && x<='Z') return 1;
	if('0'<=x && x<='9') return 1;
	return 0;
}
