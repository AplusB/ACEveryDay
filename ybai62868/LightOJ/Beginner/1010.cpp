# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
int main(void)
{
    int icase = 1;
    int t; scanf("%d",&t);
    while ( t-- ) {
        int n,m; scanf("%d%d",&n,&m);
        int res = 0;
        if ( n > m ) swap(n,m);
        int black = n*m/2;
        int white = n*m-black;
        printf("Case %d: ",icase++);
        if ( n==1 ) res = m;
        else if ( n==2 ) {
            res = 2*(2*(m/4)+min(2,m%4));
        }
        res = max(res,max(black,white));
        printf("%d\n",res);
    }
    return 0;
}
