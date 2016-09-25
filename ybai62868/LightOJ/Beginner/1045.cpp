# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
# define MAX 1234567
double Lg[MAX];
void init()
{
    for ( int i = 1;i < MAX;i++ ) {
        Lg[i] = Lg[i-1]+log(i);
    }
}
int main(void)
{
    int icase = 1;
    init();
    int t; cin>>t;
    while( t-- ) {
        int n,b; cin>>n>>b;
        int ans = int(Lg[n]/log(b));
        ans++;
        printf("Case %d: ",icase++);
        printf("%d\n",ans);
    }


    return 0;
}
