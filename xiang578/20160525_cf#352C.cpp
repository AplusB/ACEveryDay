/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
struct node
{
	double s;
	int n;
}tp;

double dis(double a1,double b1,double a2,double b2)
{
	double tmp=(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
	return sqrt(tmp);
}

vector<node>pa;
vector<node>pb;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    double tmp,a,b,ax,ay,bx,by,tx,ty,ans,t,ta,tb;
	scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
	scanf("%d",&n);
	tmp=0;
	pa.clear();
	pb.clear();
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&a,&b);
		t=dis(a,b,tx,ty);
		ta=dis(a,b,ax,ay);
		tb=dis(a,b,bx,by);
		tmp+=2*t;
		ta=ta-t;
		tb=tb-t;
		tp.n=i;
		tp.s=ta;
		if(pa.size()==0) pa.push_back(tp);
		else{
			if(pa.size()==1) pa.push_back(tp);
			else if(pa[1].s>tp.s) swap(pa[1],tp);
			if(pa[0].s>pa[1].s) swap(pa[0],pa[1]);
		}
		tp.n=i;
		tp.s=tb;
		if(pb.size()==0) pb.push_back(tp);
		else{
			if(pb.size()==1) pb.push_back(tp);
			else
			if(pb[1].s>tp.s) swap(pb[1],tp);
			if(pb[0].s>pb[1].s) swap(pb[0],pb[1]);
		}
		//printf("%lf %lf %lf\n",t,ta,tb);
	}
	//printf("%.10f\n",tmp);
	//printf("%lf %lf %lf %lf \n",pa[0].s,pa[1].s,pb[0].s,pb[1].s);
	if(pa[0].n==pb[0].n){
		if(pb.size()==1&&pa.size()==1)
		{
			ans=tmp+min(pa[0].s,pb[0].s);
			//ans=min(ans,min(tmp+pa[0].s,tmp+pb[0].s));
		}
		else
		{
			//printf("%lf %lf\n",pa[0].s+pb[1].s,pa[1].s+pb[0].s);
			ans=tmp+min(pa[0].s+pb[1].s,pa[1].s+pb[0].s);
			ans=min(ans,min(tmp+pa[0].s,tmp+pb[0].s));
		}
	}
	else
    {
        ans=tmp+pa[0].s+pb[0].s;
        ans=min(ans,min(tmp+pa[0].s,tmp+pb[0].s));
    }
	printf("%.12f\n",ans);
    return 0;
}
