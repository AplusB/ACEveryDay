# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
# define MAX 123
# define inf 0x3f3f3f3f
int a[MAX];
int main(void)
{
    int n; cin>>n;
    int i;
    for ( i = 1;i <= n;i++ )
    {
        cin>>a[i];
        if ( a[i]-a[i-1] > 15 ) break;
    }
    cout<<min(a[i-1]+15,90)<<endl;
    return 0;
}
