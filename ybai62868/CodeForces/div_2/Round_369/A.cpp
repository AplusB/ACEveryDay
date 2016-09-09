# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <cmath>
using namespace std;
# define MAX 1234
string str[MAX];
int main(void)
{
    int n; cin>>n;
    int flag = 0;
    for ( int i = 0;i < n;i++ ) cin>>str[i];
    for ( int i = 0;i < n;i++ ) {
        for ( int j = 0;j < 5;j++ ) {
            if ( str[i][j]=='O'&&str[i][j+1]=='O'&&j!=1 ) {
                str[i][j] = str[i][j+1] = '+';
                flag = 1;
                break;
            }
        }
        if ( flag ) break;
    }
    if ( flag==0 ) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for ( int i = 0;i < n;i++ ) {
            for ( int j = 0;j < 5;j++ ) {
                cout<<str[i][j];
            }
            cout<<endl;
        }
    }


    return 0;
}
