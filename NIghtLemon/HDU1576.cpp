#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	long long a,b,t;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&a,&b);
		t = 0;
		while((t-a)%9973) t+=b;
		printf("%I64d\n",t/b);
	}
	return 0;
}
