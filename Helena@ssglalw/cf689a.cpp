#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
int i, j;

int n;
char str[10];

struct Point
{
	int x, y;
	Point(){}
	Point(int xx, int yy):x(xx), y(yy){}
	Point operator=(Point p){
		x = p.x;
		y = p.y;
		return *this;
	}
}points[10];

struct Dir
{
	int x, y;
	Dir(){}
	Dir(int xx, int yy):x(xx), y(yy){}
	Dir operator=(Dir p){
		x = p.x;
		y = p.y;
		return *this;
	}
};

Dir move[10];

Dir get_dir(Point p1, Point p2){
	return Dir(p2.x-p1.x, p2.y-p1.y);
}

bool out(Point p){
	if(p.x < 0 || p.x > 3) return true;
	if(p.y <0 || p.y > 2) return true;
	if(p.x == 3 && p.y != 1) return true;
	return false;
}

bool valid(int m){//以m为起点，走同样路线，检验终点合法性
	Point cur = points[m];
	REP(n-1){
		cur.x += move[i].x;
		cur.y += move[i].y;
		//printf("cur %d %d\n", cur.x, cur.y);
		if(out(cur)) return false;
	}
	return true;
}

int main()
{
	//按键-坐标映射
	points[0] = Point(3, 1);
	REP(3){
		for(j=0; j<3; j++){
			points[i*3+j+1] = Point(i, j);
			//printf("point %d = (%d, %d)\n", i*3+j+1, i, j);
		}
	}

	FREAD("689a.txt");
	while(~RINT(n)){
		RSTR(str);
		//PSTR(str);
		REP(n-1){
			int prev = str[i]-'0';
			int next = str[i+1]-'0';
			//printf("%d %d\n", prev, next);
			move[i] = get_dir(points[prev], points[next]);
			//printf("%d %d\n", move[i].x, move[i].y);
		}
		bool ans = 1;
		REP(10){//枚举起点：0-9
			if(i == str[0]-'0') continue;
			//printf("test %d\n", i);
			if(valid(i)){
				ans = 0;
				break;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
