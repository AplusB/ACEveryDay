# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int a,b,c; cin>>a>>b>>c;
        printf("Case %d: ",icase++);
        if ( a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a ) {
            puts("yes");
        }
        else {
            puts("no");
        }
    }


    return 0;
}
