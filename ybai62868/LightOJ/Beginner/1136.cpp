# include <cstdio>
# include <iostream>
using namespace std;
int cal( int n )
{
    return n/3*2+(n%3==2?1:0);
}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int cnt = 0;
        int a,b; cin>>a>>b;
        printf("Case %d: ",icase++ );
        printf("%d\n",cal(b)-cal(a-1));
    }

    return 0;
}
