#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int dc[105];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,v;
		double w;
		cin>>n>>v>>w;
		for(int i=1;i<=n;i++)
		{
			cin>>dc[i];
		}
		sort(dc+1,dc+n+1);

		double temp=0.0,p=0.0;
		int vm=0;
		int sum=0;
		dc[0]=0;

		for(int i=1;i<=n;i++)
		{
			sum+=dc[i];
			if(sum*1.0/i<=w)
			{
				temp=sum;
				vm=i;
			}
			else break;
		}
		if(vm!=0)
			p=temp*1.0/vm*0.01;
		cout<<vm*v<<" ";
		printf("%.2lf\n",p);
	}
	return 0;
}
