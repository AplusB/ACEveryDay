# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
typedef long long LL;
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        LL n; cin>>n;
        LL res1 = n, res2 = 2;
        printf("Case %d: ",icase++);
        if ( n&1 ) {
            cout<<"Impossible"<<endl;
            continue;
        }
        res1 = res1>>1;
        while ( res1%2==0 ) {
            res1 = res1 >> 1;
            res2 = res2 << 1;
        }
        cout<<res1<<" "<<res2<<endl;
    }
    return 0;
}
