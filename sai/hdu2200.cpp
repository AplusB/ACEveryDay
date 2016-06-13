#include<iostream>
#include<stdio.h>
using namespace std;

double c(double in,double out)
{
	double son=1.0,mot=1.0;
	for(double i=in;i>=2;i--)
	{
		son*=i;
	}
	for(double i=in;i>=1&&out>=2;i--)
	{
		mot*=out--;
	}
	return mot/son;
}

int main()
{
	double t;
	while(cin>>t)
	{
		double sum=0.0;
		for(int i=2;i<=t;i++)
		{
			sum+=c(i,t)*(i-1);
		}
		printf("%.0f\n",sum);
		//cout<<sum<<endl;
	}
	return 0;
}
