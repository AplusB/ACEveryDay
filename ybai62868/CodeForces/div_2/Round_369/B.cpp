# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <cmath>
using namespace std;
# define MAX 521
typedef long long LL;
LL a[MAX][MAX];
int main(void)
{
    int n; cin>>n;
    if ( n==1 ) {
        printf("1\n");
    }
    else {
        int ans = 0;
        int px = 0, py = 0;
        for ( int i = 0;i < n;i++ ) {
            for ( int j = 0;j < n;j++ ) {
                cin>>a[i][j];
                if ( a[i][j]==0 ) {
                    px = i;
                    py = j;
                }
            }
        }
        if ( px==0 ) px++;
        else px--;
        LL temp = 0;
        for ( int j = 0;j < n;j++ ) {
            temp+=a[px][j];
        }
        LL sum = temp;
       // cout<<sum<<endl;
        for ( int i = 0;i < n;i++ ) {
            temp-=a[i][py];
        }
        if ( temp <= 0 ) {
            ans = -1;
            cout<<ans<<endl;
            return 0;
        }
        for ( int i = 0;i < n;i++ ) {
            for ( int j = 0;j < n;j++ ) {
                if ( a[i][j]==0 ) {
                    a[i][j] = temp;
                }
            }
        }
        LL res = 0;
        for ( int i = 0;i < n;i++ ) {
            res = 0;
            for ( int j = 0;j < n;j++ ) res+=a[i][j];
            if ( res!=sum ) ans = -1;
        }
        for ( int j = 0;j < n;j++ ) {
            res = 0;
            for ( int i = 0;i < n;i++ ) res+=a[i][j];
            if ( res!=sum ) ans = -1;
        }
        res = 0;
        for ( int i = 0;i < n;i++ ) {
            res+=a[i][i];
        }
        if ( res!=sum ) ans = -1;
        res = 0;
        for ( int i = 0;i < n;i++ ) {
            res+=a[i][n-i-1];
        }
        if ( res!=sum ) ans = -1;
        if ( ans==-1 ) cout<<ans<<endl;
        else cout<<temp<<endl;
    }
    return 0;
}
