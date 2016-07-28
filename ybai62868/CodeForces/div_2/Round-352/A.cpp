# include <cstdio>
# include <iostream>
using namespace std;
int main(void)
{
    int t,s,x; cin>>t>>s>>x;
    int flag = 0;
    if ( t==x ) {
        puts("YES");
        return 0;
    }
    for ( int i = 1;;i++ ) {
        if ( t+s*i==x||t+s*i+1==x  ) {
            flag = 1;
            break;
        }
        else if (  t+s*i > x ||  t+s*i+1 > x ) {
            break;
        }
    }
    if ( flag ) puts("YES");
    else puts("NO");

    return 0;
}
