#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
typedef int LL;
typedef double db;

const int maxn = 100000+10;
LL t,n,m,ans;
struct Point {
	double x,y;
	Point (double _x=0,double _y=0):x(_x),y(_y){}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p){return Vector(A.x*p,A.y*p);}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}

double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}

Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

Point get(Point A,Point B,Point C){
	Vector v1=C-B;
	double a1=Angle(A-B,v1);
	v1=Rotate(v1,a1/3);
	
	Vector v2=B-C;
	double a2=Angle(A-C,v2);
	v2=Rotate(v2,-a2/3);// 负数表示顺时针旋转 
	
	return GetLineIntersection(B,v1,C,v2); 
}

int main()
{
	LL i,j,k,l,r;
	Point A,B,C,D,E,F;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf %lf%lf %lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		D = get(A,B,C);
		E = get(B,C,A);
		F = get(C,A,B);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
	}
	return 0;
}
