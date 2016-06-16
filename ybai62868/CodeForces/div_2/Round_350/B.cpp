# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 112345
typedef long long LL;
int a[MAX];
LL sum[MAX];
int main(void)
{
    int n,k; cin>>n>>k;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    int t = 1;
    while ( k > t )
    {
        k-=t;
        t++;
    }
    cout<<a[k-1]<<endl;
    return 0;
}
