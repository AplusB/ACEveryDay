# include <cstdio>
# include <iostream>
using namespace std;
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        double v1,v2,v3,a1,a2; cin>>v1>>v2>>v3>>a1>>a2;
        printf("Case %d: ",icase++ );
        double t = max(v1/a1,v2/a2);
        double d = (v1*v1)/(2*a1)+(v2*v2)/(2*a2);
        printf("%.6lf %.6lf\n",d,t*v3);
    }


    return 0;
}
