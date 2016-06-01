#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

int main()
{
	double x1,y1,x2,y2,r1,r2,ans,d;
	while(cin>>x1>>y1>>r1){
		cin>>x2>>y2>>r2;
		ans = 0;
		d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(d<=fabs(r1-r2)){
			ans = r1;
			if(r2<r1) ans = r2;
			ans = ans*ans*PI;
		} else if(d<(r1+r2)){
			double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d)); 
        	double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
        	ans=a1*r1*r1+a2*r2*r2-r1*r1*sin(a1)*cos(a1)-r2*r2*sin(a2)*cos(a2);    
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
