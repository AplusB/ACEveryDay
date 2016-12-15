#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn=5e4+9;
const int inf=2e9+9;
const int mod=1000;

char num[2000];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%s",num);
		scanf("%d",&m);
		int len=strlen(num);
		int pos=-1;
		for(int j=1;j<len;j++)
		{
			if(num[j]=='0') continue;
			if(pos==-1) pos=j;
			else if(num[j]<num[pos])
				pos=j;
		}
		if(pos!=-1 && m>0 && num[pos]<num[0])
		{
			char tmp=num[0];
			num[0]=num[pos];
			num[pos]=tmp;
			m--;
		}
		for(int i=1;i<len;i++)
		{
			if(num[i]=='0') continue;
			if(m<=0) break;
			int loca=i;
			for(int j=i+1;j<len;j++)
			{
				if(num[j]<num[loca])
					loca=j;
			}
			if(num[loca]<num[i])
			{
				m--;
				char tmp=num[loca];
				num[loca]=num[i];
				num[i]=tmp;
			}
		}// ss
		printf("%s\n",num);
	}
	return 0;
}
