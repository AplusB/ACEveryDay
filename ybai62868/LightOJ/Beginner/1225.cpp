# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
using namespace std;
# define MAX 12345
char number[MAX];
int pd( )
{
    int cnt = strlen(number);
    for ( int i = 0;i < cnt/2;i++ ) {
        if ( number[i]!=number[cnt-i-1] ) {
            return 0;
        }
    }
    return 1;
}
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        scanf("%s",number);
        printf("Case %d: ",icase++);
        if ( pd() ) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }


    return 0;
}
