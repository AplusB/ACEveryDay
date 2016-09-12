# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123456
int a[MAX],b[MAX];
int main(void)
{
    int n; cin>>n;
    for ( int i = 1;i <= n;i++ ) cin>>a[i];
    b[n] = a[n];
    for ( int i = n-1;i >= 1;i-- ) {
        b[i] = a[i]+a[i+1];
    }
    for ( int i = 1;i <= n;i++ ) cout<<b[i]<<" ";
    cout<<endl;

    return 0;
}
