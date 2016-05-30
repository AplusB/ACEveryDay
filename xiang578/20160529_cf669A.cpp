#include<bits/stdc++.h>
using namespace std;

int n;
int main()
{
	scanf("%d",&n);
	//if(n==1||n==2) printf("%d")
	if(n%3==0) printf("%d\n",2*(n/3));
	else printf("%d\n",2*(n/3)+1);
	return 0;
}
