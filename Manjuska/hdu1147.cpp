#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const double eps=1e-14;  
const int maxn=1e5+10;  
struct node{  
    double x1,y1,x2,y2;  
    int w;  
}e[maxn],f[maxn];  
double cross(double x1,double y1,double x2,double y2)  
{  
    return x1*y2-x2*y1;  
}  
int find(node a,node b) //判断是否相交  
{  
    double c[4];  
    c[0]=cross(a.x2-a.x1,a.y2-a.y1,b.x1-a.x1,b.y1-a.y1);  
    c[1]=cross(a.x2-a.x1,a.y2-a.y1,b.x2-a.x1,b.y2-a.y1);  
    c[2]=cross(b.x2-b.x1,b.y2-b.y1,a.x1-b.x1,a.y1-b.y1);  
    c[3]=cross(b.x2-b.x1,b.y2-b.y1,a.x2-b.x1,a.y2-b.y1);  
    if(c[0]*c[1]<=0&&c[2]*c[3]<=0)return 1;  
    return 0;  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        if(n==0)break;  
        int i,j,k,p,q;  
        for(i=0;i<n;i++)  
        {  
            scanf("%lf%lf%lf%lf",&e[i].x1,&e[i].y1,&e[i].x2,&e[i].y2);  
            e[i].w=i+1;  
        }  
        p=0;  
        for(i=0;i<n;i++)  
        {  
            q=0;  
            for(j=0;j<p;j++)  
                if(!find(e[i],f[j]))f[q++]=f[j];  
            f[q++]=e[i];  
            p=q;  
        }  
        printf("Top sticks: %d",f[0].w);  
        for(i=1;i<p;i++)  
            printf(", %d",f[i].w);  
        printf(".\n");  
    }  
    return 0;  
} 
