#include<iostream>
using namespace std;

int main()
{
	int h,u,d;
	while(cin>>h>>u>>d,(h+u+d))
	{
		int temp=(h-u)/(u-d);
		int ans=temp*2;
		int p=temp*(u-d);

		while(p+u<h)
		{
			p+=u;
			ans++;
			temp-=d;
			ans++;
		}

		if(p<h)
		{
			ans+=1;
		}

		cout<<ans<<endl;
	}
	return 0;
}
