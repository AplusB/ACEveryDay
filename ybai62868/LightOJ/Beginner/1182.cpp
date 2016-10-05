# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
int cal ( int x )
{
    int cnt = 0;
    while ( x ) {
        if ( x%2==1 ) cnt++;
        x/=2;
    }
    return cnt;

}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int n; cin>>n;
        int res = cal(n);
        printf("Case %d: ",icase++);
        if ( res&1 ) puts("odd");
        else puts("even");
    }

}
