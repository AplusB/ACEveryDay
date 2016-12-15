#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char a[200],b[200];

int main()
{
	while(~scanf("%s %s",a,b))
	{
		if(strcmp(a,b)==0)
			printf("%s\n",a);
		else
			printf("1\n");
	}
	return 0;
}
