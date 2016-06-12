# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <set>
using namespace std;
# define inf 0x3f3f3f3f
# define MAX 123456
typedef long long LL;
int cnt[26];
int main(void)
{
    int n; cin>>n;
    string str; cin>>str;
    if ( n > 26 )
    {
        cout<<-1<<endl;
        return 0;
    }
    int len = (int)set<char>(str.begin(),str.end()).size();
    cout<<n-len<<endl;
    return 0;
}
