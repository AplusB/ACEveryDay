/* ***********************************************
Author        :guanjun
Created Time  :2016/5/24 9:22:36
File Name     :hdu1392.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
int n,top;

struct point{
	int x,y;
}p[maxn],sta[maxn];

bool cmp(point a,point b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int cross(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int graham(){
	sort(p,p+n,cmp);
	int top=0;
	for(int i=0;i<n;i++){
		while(top>1&&cross(sta[top-2],sta[top-1],p[i])<=0)top--;
		sta[top++]=p[i];
	}
	int t=top;
	for(int i=n-2;i>=0;i--){
		while(top>t&&cross(sta[top-2],sta[top-1],p[i])<=0)top--;
		sta[top++]=p[i];
	}
	if(n>1)top--;
	return top;
}
double dis(point a,point b){
	return sqrt(1.0*((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    while(cin>>n&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		top=graham();
		double sum=0;
		for(int i=1;i<=top;i++){
			sum+=dis(sta[i],sta[i-1]);
		}
		if(n==1)puts("0.00");
		else if(n==2)printf("%.2f\n",dis(p[0],p[1]));
		else printf("%.2f\n",sum);
	}
    return 0;
}
