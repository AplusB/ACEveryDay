# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
# define MAX 212345
typedef long long LL;
int a[MAX];
int main(void)
{
    int n; scanf("%d",&n);
    for ( int i = 0;i < n;i++ ) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int res = 2000000000;
    int ans = 0;
    for ( int i = 0;i < n-1;i++ ) {
        res = min(res,abs(a[i]-a[i+1]));
    }
    for ( int i = 0;i < n-1;i++ ) {
        if ( res==abs(a[i]-a[i+1]) ) ans++;
    }
    printf("%d %d\n",res,ans);


    return 0;
}
