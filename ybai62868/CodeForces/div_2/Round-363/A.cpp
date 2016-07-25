# include <cstdio>
# include <iostream>
# include <string>
# include <set>
using namespace std;
# define MAX 212345
# define inf 0x3f3f3f3f
int a[MAX];
string str;
set<int>s;
int main(void)
{
    int n; cin>>n;
    cin>>str;
    int ans = inf;
    int flag = 0;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    for ( int i = 0;i < n-1;i++ ){
        if ( str[i]=='R'&&str[i+1]=='L' ){
            flag = 1;
            break;
        }
    }
    if ( !flag ){
        cout<<-1<<endl;
    }
    else{
        for ( int i = 0;i < n-1;i++ ){
            if ( str[i]=='R'&&str[i+1]=='L' ){
                ans = min(ans,(a[i+1]-a[i])>>1 );
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
