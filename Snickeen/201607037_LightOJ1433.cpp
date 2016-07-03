/*
    题意：给定O.A.B三个点的坐标，求弧AB的最小长度
    思路：勾股定理，余弦定理，三角函数 
        一开始考虑的余弦，结果WA，原来想复杂了，思考了思考正弦才过，卡精度 
*/

//WA 想复杂了
/* 
#include<stdio.h>
#include<math.h>
typedef double db; 
int t,ca=0;
db ox,oy,ax,ay,bx,by,OA,OB,AB,ans;
db gg(db x,db y){return sqrt(x*x+y*y);}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        OA=gg(ax-ox,ay-oy);
        OB=gg(bx-ox,by-oy);
        AB=gg(ax-bx,ay-by);
        ans=(OA*OA+OB*OB-AB*AB)/(2*OA*OB);
        ans=sqrt(1-ans*ans);
        ans=asin(ans)*OA;
        printf("Case %d: %.9lf\n",++ca,ans);
    }
    return 0;
}
*/

#include<stdio.h>
#include<math.h>
typedef double db; 
int t,ca=0;
db ox,oy,ax,ay,bx,by,OA,OB,AB,ans;
db gg(db x,db y){return sqrt(x*x+y*y);}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        OA=gg(ax-ox,ay-oy);
        AB=gg(ax-bx,ay-by);
        ans=asin(AB/2/OA)*OA*2;
        printf("Case %d: %.9lf\n",++ca,ans);
    }
    return 0;
}
