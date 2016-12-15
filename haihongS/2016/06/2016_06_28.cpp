#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=300+9;
typedef long long ll;


int main()
{
	char num[50];
	while(~scanf("%s",num))
	{
		int a;
		scanf("%d",&a);
		int len=strlen(num);
		int hh,mm;
		hh=mm=0;
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(num[i]==':')
			{
				flag=1;continue;
			}
			if(flag==0)
				hh=hh*10+num[i]-'0';
			else if(flag==1)
				mm=mm*10+num[i]-'0';
		}
		int nh,nm;
		nh=nm=0;
		nh=a/60;
		nm=a%60;
		int jj=0;
		mm+=nm;
		if(mm>=60)
		{
			mm%=60;
			hh+=1;
		}
		hh+=nh;
		hh%=24;
		
		if(hh<=9)
			printf("0");
		printf("%d:",hh);
		if(mm<=9)
			printf("0");
		printf("%d\n",mm);
	}
	return 0;
}

