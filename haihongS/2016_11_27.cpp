#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

int v[15];

int main()
{
	v[0]=2;
	v[1]=7;
	v[2]=2;
	v[3]=3;
	v[4]=3;
	v[5]=4;
	v[6]=2;
	v[7]=5;
	v[8]=1;
	v[9]=2;
	char x[10];
	while(~scanf("%s",x))
	{
		int ans=v[x[0]-'0']*v[x[1]-'0'];
		printf("%d\n",ans);
	}

	return 0;
}
