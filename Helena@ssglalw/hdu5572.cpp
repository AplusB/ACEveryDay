#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int cmp(double x){
	return x < -eps ? -1 : (x>eps);
}

double pow2(double x){
	return x * x;
}

double mySqrt(double x){
	return sqrt(max((double)0, x));
}

struct Vec
{
	double x, y;
	Vec(){}
	Vec(double xx, double yy):x(xx), y(yy){}

	Vec& operator=(const Vec& v){
		x = v.x;
		y = v.y;
		return *this;
	}

	double norm(){
		return sqrt(pow2(x) + pow2(y));
	}
	//返回单位向量
	Vec unit(){
		return Vec(x, y) / norm();
	}
	//判等
	friend bool operator==(const Vec& v1, const Vec& v2){
		return cmp(v1.x - v2.x)==0 && cmp(v1.y - v2.y)==0;
	}

	//+, -, 数乘
	friend Vec operator+(const Vec& v1, const Vec& v2){
		return Vec(v1.x + v2.x, v1.y + v2.y);
	}
	friend Vec operator-(const Vec& v1, const Vec& v2){
		return Vec(v1.x - v2.x, v1.y - v2.y);
	}
	friend Vec operator*(const Vec& v, const double c){
		return Vec(c*v.x, c*v.y);
	}
	friend Vec operator*(const double c, const Vec& v){
		return Vec(c*v.x, c*v.y);
	}
	friend Vec operator/(const Vec& v, const double c){
		return Vec(v.x/c, v.y/c);
	}
};

int T;
int ans;
Vec O, A, V, B, C, B1;
int R;

//点乘
double dot(const Vec v1, const Vec v2){
	return v1.x*v2.x + v1.y*v2.y;
}
//叉乘的模长
double product(const Vec v1, const Vec v2){
	return v1.x*v2.y - v1.y*v2.x;
}

//点p到直线v1,v2的投影
Vec project(Vec& v1, Vec& v2, Vec& p){
	Vec v = v2 - v1;
	return v1 + v * dot(v, p-v1) / dot(v, v);
}
//点p关于直线v1,v2的对称点
Vec mirrorPoint(Vec& v1, Vec& v2, Vec& p){
	Vec c = project(v1, v2, p);
	return (double)2*c - p;
}

//判断点p是否在线段v1,v2上
bool onSeg(Vec& v1, Vec& v2, Vec& p){
	if(cmp(product(p-v1, v2-v1))==0 && cmp(dot(p-v1, p-v2))<=0)
		return true;
	return false;
}

bool calc_C(){
	//将AC表示为关于t的参数方程
	//则与圆的方程联立得到关于t的一元二次方程, a,b,c为一般式的三个系数
	double a = pow2(V.x) + pow2(V.y);
	double b = 2*V.x*(A.x - O.x) + 2*V.y*(A.y - O.y);
	double c = pow2(A.x - O.x) + pow2(A.y - O.y) - pow2(R);
	double delta = pow2(b) - 4*a*c;
	if(cmp(delta) <= 0) return false;
	else{
		double t1 = (-b - mySqrt(delta))/(2*a);
		double t2 = (-b + mySqrt(delta))/(2*a);
		double t;
		if(cmp(t1) >= 0) t = t1;
		if(cmp(t2) >= 0 && t2 < t1) t = t2;//取较小的那个，即为离A近的那个交点
		C.x = A.x + V.x*t;
		C.y = A.y + V.y*t;
		return true; //有交点
	}
}

int main()
{
	freopen("5572.txt", "r", stdin);
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%lf%lf%d", &O.x, &O.y, &R);
		scanf("%lf%lf%lf%lf", &A.x, &A.y, &V.x, &V.y);
		scanf("%lf%lf", &B.x, &B.y);
		if(calc_C()){
			if(onSeg(A, C, B)) ans = 1;
			else{
				//printf("has intersection (%lf, %lf)\n", C.x, C.y);
				B1 = mirrorPoint(O, C, B);
				Vec A1 = mirrorPoint(O, C, A);

				//printf("B1 (%lf, %lf)\n", B1.x, B1.y);
				if(A==A1 && onSeg(C, B, A))
					ans = 1;
				else if(onSeg(C, B, A1))
					ans = 1;
				else ans = 0;
			}
		}else{//运动方向不变，则AB与V同向才可碰到B
			//printf("no intersection\n");
			Vec temp = B - A;
			if(temp.unit() == V.unit())
				ans = 1;
			else ans = 0;
		}
		printf("Case #%d: %s\n", ca, ans ? "Yes" : "No");
	}
	return 0;
}