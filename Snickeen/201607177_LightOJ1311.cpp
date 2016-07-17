#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef double db;

int n,ca=0;
db v1,v2,v3,a1,a2,d,t;

int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        t=max(v1/a1,v2/a2);
        d=v1*v1/a1/2+v2*v2/a2/2;
        printf("Case %d: %.9lf %.9lf\n",++ca,d,t*v3);
    }
    return 0;
}
