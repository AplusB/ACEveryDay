# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
# define MAX 112345
# define inf 0x3f3f3f3f
int main(void)
{
    int n,m; cin>>n>>m;
    int ans1 = 1, ans2 = n;
    while ( m-- )
    {
        int x,y; cin>>x>>y;
        if ( x>y ) swap(x,y);
        ans1 = max(ans1,x);
        ans2 = min(ans2,y);
    }
    cout<<max(0,ans2-ans1)<<endl;
    return 0;
}
