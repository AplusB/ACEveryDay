#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=1000000;


int main()
{
	string aha;
	cin>>aha;
	int len=aha.length();
	int ld=0;
	int flag=0;
	int a,b;
	a=b=0;
	for(int i=0;i<len;i++)
	{
		if(aha[i]=='.')
		{
			flag=1;continue;
		}
		if(aha[i]=='e')
		{
			flag=2;continue;
		}
		if(flag==0) a=aha[i]-'0';
		else if(flag==2) b=b*10+aha[i]-'0';
		else ld++;	
	}
	if(a==0 && ld==1 && aha[2]=='0')
	{
		printf("0\n"); return 0;
	}
	if(ld>b)
	{
		if(ld==1 && b==0 && aha[2]=='0')
		{
			printf("%d\n",a);return 0;
		}
		printf("%d",a);
		int i=2;
		for(;i<2+b;i++)
			printf("%d",aha[i]-'0');
		printf(".");
		for(;i<len;i++)
		{
			if(aha[i]=='e') break;
			printf("%d",aha[i]-'0');
		}
		printf("\n");
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			if(i==0 && aha[i]=='0') continue;
			if(aha[i]=='.') continue;
			if(aha[i]=='e') break;
			printf("%d",aha[i]-'0');
		}
		for(int i=0;i<b-ld;i++)
			printf("0");
		printf("\n");
	}
	return 0;
}
