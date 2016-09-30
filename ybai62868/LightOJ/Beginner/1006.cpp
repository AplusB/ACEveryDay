# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
# define MAX 12345
typedef long long LL;
int n;
LL r[MAX];
LL cal( LL a, LL b, LL c, LL d, LL e, LL f )
{
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    r[4] = e;
    r[5] = f;
    for ( int i = 6;i <= n;i++ ) {
        r[i] = (r[i-1]+r[i-2]+r[i-3]+r[i-4]+r[i-5]+r[i-6])%10000007;
    }
    return r[n];
}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        LL a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
        cin>>n;
        LL res = cal(a,b,c,d,e,f);
        printf("Case %d: ",icase++);
        printf("%lld\n",res%10000007);
    }

    return 0;
}
