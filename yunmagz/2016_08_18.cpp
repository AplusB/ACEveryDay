//poj2365 - Rope
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <Stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
#define pi 3.1415926535897932384626
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int N = 105;
struct point {
    double x;
    double y;
}p[N], Stack[N];

bool isZero(double x) {
    return (x > 0 ? x : -x) < eps;
}

double dis(point A, point B) {
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double crossProd(point A, point B, point C) {
    return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
}

//以最左下的点为基准点，其他各点（逆时针方向）以极角从小到大的排序规则
int cmp(const void *a, const void *b) {
    point *c = (point *)a;
    point *d = (point *)b;
    double k = crossProd(p[0], *c, *d);//极角大小转化为求叉乘
    if (k<eps || isZero(k) && dis(p[0], *c)>dis(p[0], *d)) return 1;
    return -1;
}
double Graham(int n) {
    double x = p[0].x;
    double y = p[0].y;
    int mi = 0;
    for (int i=1; i<n; ++i) {//找到最左下的一个点
        if (p[i].x<x || (p[i].x==x && p[i].y<y)) {
            x = p[i].x;
            y = p[i].y;
            mi = i;
        }
    }
    point tmp = p[mi];
    p[mi] = p[0];
    p[0] = tmp;
    qsort(p+1, n-1, sizeof(point), cmp);
    p[n] = p[0];
    Stack[0] = p[0];
    Stack[1] = p[1];
    Stack[2] = p[2];
    int top = 2;
    for (int i=3; i<=n; ++i) {//加入一个点后,向右偏拐或共线，则上一个点不在凸包内，则--top，该过程直到不向右偏拐或没有三点共线的点
        while (crossProd(Stack[top-1], Stack[top], p[i])<=eps && top>=2) --top;
        Stack[++top] = p[i];//在当前情况下符合凸包的点，入栈
    }
    double len=0;
    for(int i=0;i<top;i++) len+=dis(Stack[i],Stack[i+1]);
    return len;
}
int main()
{
    int n;
    double r;
    while(cin>>n>>r){
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        if(n==1)
            printf("%.2f\n",pi*r*2);
        else if(n==2)
            printf ("%.2f\n",dis(p[0],p[1])*2+pi*r*2);
        else printf ("%.2f\n",Graham(n)+pi*r*2);
    }
    return 0;
}
