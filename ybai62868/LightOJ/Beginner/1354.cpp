# include <cstdio>
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;
# define MAX 123456
char str[MAX];
int ip[4];
int a,b,c,d;
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    while ( t-- ) {
        int cnt = 0;
        int flag = 0;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%s",str);
        for ( int i = 0;str[i];i++ ) {
            if ( str[i]=='.' ) {
                cnt++;
            }
            else {
                ip[cnt] = ip[cnt]*2+(str[i]-'0');
            }
        }
        printf("Case %d: ",icase++);
        if ( ip[0]==a&&ip[1]==b&&ip[2]==c&&ip[3]==d ) {
            puts("Yes");
        }
        else {
            puts("No");
        }
        memset(str,0,sizeof(str));
        memset(ip,0,sizeof(ip));
    }

}
