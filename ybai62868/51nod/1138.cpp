# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
int main(void)
{
    int n; cin>>n;
    int flag = 0;
    int limit = sqrt(2*n+0.5);
    for ( int i = limit;i >= 2;i-- )
    {
        if ( (n-i*(i-1)/2)%i==0 )
        {
            flag = 1;
            cout<<(n-i*(i-1)/2)/i<<endl;
        }
    }
    if ( flag==0 ) puts("No Solution");
    return 0;
}
