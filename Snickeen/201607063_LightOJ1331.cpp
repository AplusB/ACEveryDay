/*
    题意：给定三个圆的半径，求三个圆围成的中间部分的面积
    思路：海伦公式，余弦定理 
*/
#include<stdio.h>
#include<math.h>
typedef double db;

db sum(db a,db b,db c){db p=(a+b+c)/2.0;return sqrt(p*(p-a)*(p-b)*(p-c));}
db gg(db a,db b,db c){return acos((a*a+b*b-c*c)/(2*a*b));}

int main()
{
    int t,ca=0;db r1,r2,r3,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        ans=sum(r1+r2,r2+r3,r1+r3);
        ans-=r1*r1*gg(r1+r2,r1+r3,r2+r3)/2;
        ans-=r2*r2*gg(r2+r1,r2+r3,r1+r3)/2;
        ans-=r3*r3*gg(r3+r1,r3+r2,r1+r2)/2;
        printf("Case %d: %.9lf\n",++ca,ans);
    }
    return 0;
}
