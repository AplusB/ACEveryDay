#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define PI acos(-1.0)
using namespace std;
int main()
{
	int t;
	double r1,r2,r3,a,b,c,a1,b1,c1,s1,s2;
	scanf("%d",&t);
	int l=1;
	while(t--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a=r1+r2;
		b=r1+r3;
		c=r2+r3;
		c1=acos((a*a+b*b-c*c)/(2*a*b));
		b1=acos((a*a+c*c-b*b)/(2*a*c));
		a1=acos((b*b+c*c-a*a)/(2*b*c));
		s1=0.5*a*b*sin(c1);
		s2=PI*r1*r1*(c1/(2*PI))+PI*r2*r2*(b1/(2*PI))+PI*r3*r3*(a1/(2*PI));
		printf("Case %d: %lf\n",l++,s1-s2);
	}
	return 0;
}
