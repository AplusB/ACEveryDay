#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	double a,b,c;
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		if(a+b+c-2*(max(max(a,b),c))>0) puts("YES");
		else puts("NO");
	}
	return 0;
} 
