/*
    题意：给定梯形四条边，求面积
    思路：根据海伦公式求出高，然后求面积 
*/

#include<bits/stdc++.h>
using namespace std;
typedef double db;

int t,ca=0,n;

db get(db a,db b,db c){
    db p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    int i,j,k,l;
    db a,b,c,d,h,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        h=get(fabs(a-c),b,d);
        h=h*2/fabs(a-c);
        ans=(a+c)*h/2.0;
        printf("Case %d: %.12lf\n",++ca,ans);
    }
    return 0;
}
