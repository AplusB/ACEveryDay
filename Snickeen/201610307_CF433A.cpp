//By Snickeen.
#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
int main()
{
	scanf("%d",&n);
	while(n--)scanf("%d",&m),m==100?u++:v++;
	if(u&1||((v&1)&&u<2))return 0*puts("NO");
	return 0*puts("YES");
}
