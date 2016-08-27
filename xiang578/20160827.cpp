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
const double eps=1e-6;
int n,k;
double l,v1,v2;

int get(double t,double m)
{
    int p=n-1;
    double car=m,peo=m/v2*v1,nt=m/v2,T,L,x,tmp;
    while(p!=0)
    {
        tmp=(car-peo)/(v1+v2);
        nt+=tmp;
        peo+=tmp*v1;
        //printf("%lf %lf ",nt,t);
        if(nt>t) break;
        T=t-nt;
        L=l-peo;
        x=(L-v1*T)/(v2-v1);
        car=peo+x*v2;
        peo=peo+x*v1;
        nt+=x;
        if(nt>t) break;
        p--;
    }
    //printf("%d\n",p);
    if(p==0) return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k);
    if(n==k)
    {
        printf("%.10f\n",l/v2);
    }
    else
    {
        if(n%k==0) n=n/k;
        else n=n/k+1;
        double M,L=0,R=l,ans=1e9+10,t;
        while(fabs(R-L)>eps)
        {
            M=(L+R)/2;
            t=M/v2+(l-M)/v1;
            //printf("%lf %lf %lf ",L,R,t);
            if(get(t,M)==1)
            {
                ans=min(ans,t);
                L=M;
            }
            else
            {
                R=M;
            }
        }
        printf("%.10f\n",ans);
    }
    return 0;
}
