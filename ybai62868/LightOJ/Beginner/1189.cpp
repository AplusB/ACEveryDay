# include <cstdio>
# include <iostream>
using namespace std;
typedef long long LL;
# define MAX 12345
LL a[MAX];
int res[MAX];
void init()
{
    a[0] = 1;
    for ( int i = 1;i <= 20;i++ ) a[i] = a[i-1]*i;
}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    init();
    while ( t-- ) {
        LL n; cin>>n;
        int cnt = 0;
        for ( int i = 20;i >= 0;i-- ) {
            if ( n >= a[i] ) {
                n-=a[i];
                res[++cnt] = i;
            }
        }
        printf("Case %d: ",icase++);
        if ( n ) {
            puts("impossible");
        }
        else{
            for ( int i = cnt; i >= 2;i-- ) {
                printf("%d!+",res[i]);
            }
            printf("%d!\n",res[1]);
        }
    }


    return 0;
}
