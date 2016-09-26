# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
int pd ( int x1,int y1,int x2,int y2,int x,int y )
{
    if ( x >= x1 && x <= x2 ) {
        if ( y >= y1 && y <= y2 ) {
            return 1;
        }
    }
    return 0;

}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int m; cin>>m;
        printf("Case %d:\n",icase++);
        for ( int i = 0;i < m;i++ ) {
            int x,y; cin>>x>>y;
            if (pd(x1,y1,x2,y2,x,y)) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }
    return 0;
}
