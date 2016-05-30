//水
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a,b;
int main() {
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	scanf("%d%d%d",&n,&a,&b);
	a=(a+b)%n;
	if (a<=0) a+=n;
	printf("%d\n",a);
	
	return 0;
}
