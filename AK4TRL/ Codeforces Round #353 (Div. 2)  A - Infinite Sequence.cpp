#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c!=0)
	{
		if((b-a)%c==0 && (b-a)/c>=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
	{
		if(a==b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
