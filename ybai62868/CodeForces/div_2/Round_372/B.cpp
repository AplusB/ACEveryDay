# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 123456
int a[MAX];
typedef long long LL;
int main(void)
{
    int n; cin>>n;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    sort(a,a+n);
    int cnt = unique(a,a+n)-a;
    if ( cnt > 3 ) cout<<"NO"<<endl;
    else if ( cnt < 3 ) cout<<"YES"<<endl;
    else{
        if ( a[0]+a[2]==a[1]*2 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}
