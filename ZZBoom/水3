//hdoj 3782

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	
	int n;
	while(~scanf("%d",&n))
	{
		if(!n)
			break;
		
		int ans=0;
		while(n!=1)
		{
			if(n%2)
				n=(3*n+1)/2;
			else
				n/=2;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

 
