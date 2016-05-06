//按照训练指南白书上模版写的新姿势，更好理解
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8; //1e-10会WA，注意调整精度，过大过小都不行
int dcmp(double x){
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}
double mySqrt(double x){
	return sqrt(max((double)0, x));
}

struct Point
{
	double x, y;
	Point(double x=0, double y=0):x(x), y(y){}
	Point& operator = (Point p){
		x = p.x;
		y = p.y;
		return *this;
	}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B){ return Vector(A.x + B.x, A.y + B.y);}
Vector operator - (Point A, Point B){ return Vector(A.x - B.x, A.y - B.y);}
Vector operator * (Vector A, double p){ return Vector(A.x * p, A.y * p);}
Vector operator / (Vector A, double p){ return Vector(A.x / p, A.y / p);}

double dot(Vector A, Vector B){ return A.x * B.x + A.y * B.y;}
double length(Vector A){ return mySqrt(dot(A, A));}
double cross(Vector A, Vector B){ return A.x * B.y - A.y * B.x;}

struct Line
{
	Point p;
	Vector v;
	Line(Point p, Vector v):p(p), v(v){}
	Point getPoint(double t){
		return Point(p.x + v.x*t, p.y + v.y*t);
	}
};

struct Circle
{
	Point c;
	double r;
	Circle(Point c, double r):c(c), r(r){}
};

int getLineCircleIntersection(Line L, Circle C, Point& P){ //返回t较小的那个点
	double a = L.v.x;
	double b = L.p.x - C.c.x;
	double c = L.v.y;
	double d = L.p.y - C.c.y;

	double e = a*a + c*c;
	double f = 2*(a*b + c*d);
	double g = b*b + d*d - C.r*C.r;

	double delta = f*f - 4*e*g;

	if(dcmp(delta) <= 0) return 0;

	double t = (-f - mySqrt(delta)) / (2*e);
	P = L.getPoint(t);
	return 1;
}

bool onRay(Point A, Line L){//点A在射线L(p,v)上，不含端点
	Vector w = A - L.p;
	if(dcmp(cross(w, L.v))==0 && dcmp(dot(w, L.v))>0) return true;
	return false;
}

bool onSeg(Point A, Point B, Point C){//点A在线段BC上
	return dcmp(cross(B-A, C-A))==0 && dcmp(dot(B-A, C-A))<0;
}

Point project(Point A, Line L){
	return L.p + L.v * (dot(L.v, A - L.p)/dot(L.v, L.v));
}
Point mirrorPoint(Point A, Line L){
	Vector D = project(A, L);
	//printf("project: %lf, %lf\n", D.x, D.y);
	return D + (D - A);
}

int main()
{
	int T;
	int ans = 0;
	double R;
	Point O, A, B;
	Vector V;
	freopen("5572.txt", "r", stdin);
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%lf%lf%lf", &O.x, &O.y, &R);
		scanf("%lf%lf%lf%lf", &A.x, &A.y, &V.x, &V.y);
		scanf("%lf%lf", &B.x, &B.y);
		Line LA = Line(A, V);
		Circle yuanO = Circle(O, R);
		Point C;
		if(getLineCircleIntersection(LA, yuanO, C)){
			if(onSeg(B, A, C)) ans = 1;
			else{
				Line OC = Line(O, Vector(C.x - O.x, C.y - O.y));
				Point A1 = mirrorPoint(A, OC);
				// printf("%lf, %lf\n", C.x, C.y);
				// printf("%lf, %lf\n", A1.x, A1.y);
				Line CB = Line(C, Vector(B.x - C.x, B.y - C.y));
				
				if(onRay(A1, CB)){
					 ans = 1;

				}
				else ans = 0;
			}
		}else{
			if(onRay(B, LA)) ans = 1;
			else ans = 0;
		}
		printf("Case #%d: %s\n", ca, ans ? "Yes" : "No");
	}

	return 0;
}