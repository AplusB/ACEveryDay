# include <cstdio>
# include <iostream>
using namespace std;
int bl[3],tr[3];
int bbl[3],ttr[3];
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int n; cin>>n;
        for ( int i = 0;i < 3;i++ ) cin>>bl[i];
        for ( int i = 0;i < 3;i++ ) cin>>tr[i];
        for ( int i = 0;i < n-1;i++ ) {
            for ( int j = 0;j < 3;j++ ) cin>>bbl[j];
            for ( int j = 0;j < 3;j++ ) cin>>ttr[j];
            for ( int j = 0;j < 3;j++ ) {
                bl[j] = max(bl[j],bbl[j]);
                tr[j] = min(tr[j],ttr[j]);
            }
        }
        int res = 1;
        int flag = 0;
        for ( int i = 0;i < 3;i++ ) {
            if ( bl[i] > tr[i] ) flag = 1;
            res*=(tr[i]-bl[i]);
        }
        printf("Case %d: ",icase++ );
        if ( flag==0 ) printf("%d\n",res);
        else printf("0\n");
    }
    return 0;
}
