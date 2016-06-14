# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
# define MAX 55555
# define inf 0x3f3f3f3f
int a[MAX];
int main(void)
{
    int n; cin>>n;
    int l; cin>>l;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    int ans1 = 0;
    for ( int i = 0;i < n;i++ )
    {
         ans1 = max(ans1,min(a[i],l-a[i]));
    }
    int ans2 = 0;
    for ( int i = 0;i < n;i++ )
    {
        ans2 = max(ans2,max(a[i],l-a[i]));
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
