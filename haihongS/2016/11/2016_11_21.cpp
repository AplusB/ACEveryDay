#include <iostream>
#include <cstdio>

using namespace std;

char a[2000];

int main()
{
	while(~scanf("%s",a))
	{
		int len=strlen(a);
		int v=0;
		for(int i=0;i<len;i++)
		{
			v+=a[i]-'0';
		}
		if(v%3==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
