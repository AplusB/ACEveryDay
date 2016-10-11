# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int r1,r2,c1,c2; cin>>r1>>c1>>r2>>c2;
        printf("Case %d: ",icase++ );
        int ans = 0;
        if ( (r1+c1)%2!=(r2+c2)%2 ) {
            puts("impossible");
        }
        else {
            if ( abs(r1-r2)==abs(c1-c2) ) {
                printf("1\n");
            }
            else {
                printf("2\n");
            }
        }
    }


    return 0;
}
