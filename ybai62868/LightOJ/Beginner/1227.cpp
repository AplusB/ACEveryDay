# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 33
int a[MAX];
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int n,p,q; cin>>n>>p>>q;
        for ( int i = 0;i < n;i++ ) cin>>a[i];
        sort(a,a+n);
        int cnt = 0;
        int res = 0;
        for ( int i = 0;i < n;i++ ) {
            if ( q<=0 ) break;
            if ( a[i] <= q && cnt < p ) {
                cnt++;
                q-=a[i];
            }
        }
        printf("Case %d: ",icase++ );
        printf("%d\n",cnt);
    }

}
