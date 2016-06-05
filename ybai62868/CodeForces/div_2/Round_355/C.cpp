
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int gedit( char c )
{
    if ( c>='0'&&c<='9' ) return c-'0';
    if ( c>='a'&&c<='z' ) return c-'a'+36;
    if ( c>='A'&&c<='Z' ) return c-'A'+10;
    if ( c=='-' ) return 62;
    if ( c=='_' ) return 63;
}
int main(void)
{
    string str; cin>>str;
    int len = str.length();
    LL ans = 1;
    for ( int i = 0;i < len;i++ )
    {
        int p = gedit(str[i]);
        for ( int j = 0;j < 6;j++ )
        {
            if ( (p>>j)&1 == 0 )
            if ( ((p>>j)&1) == 0 )
            {
                ans = ans*3%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
