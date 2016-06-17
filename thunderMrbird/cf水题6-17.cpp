#include<bits/stdc++.h>
int n,i,j,x;
int main()
{
	scanf("%d",&n);
	for (i=0;i<=1000;i++)
	for (j=0;j<=10000;j++)
	{
		x=n-i*1234567-j*123456;
		if (x<0) break;
		if (x%1234==0) 
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
