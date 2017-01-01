#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e2+60;
const ll inf=2e9+9;


void deal(int x);

int main()
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		printf("#");
		deal(a);
		deal(b);
		deal(c);
		printf("\n");

	}
	return 0;
}

void deal(int x)
{
	int aha[10];
	int pos=0;
	while(x)
	{
		aha[pos++]=x%13;
		x/=13;
	}
	if(pos<=2)
	{
		for(int i=0;i<2-pos;i++) printf("0");
	}
	for(int i=pos-1;i>=0;i--)
	{
		if(aha[i]>=10) printf("%c",'A'+aha[i]-10);
		else printf("%d",aha[i]);
	}
}
