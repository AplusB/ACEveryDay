# include <cstdio>
# include <iostream>
# include <cmath>
# include <string>
# include <cstring>
# include <map>
using namespace std;
map<string,int>mp;
char mon[16][26] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int main(void)
{
    int icase = 1;
    for ( int i = 0;i < 12;i++ ) {
        mp[mon[i]] = i+1;
    }
    int t; cin>>t;
    char a[23];
    int m;
    int y;
    while ( t-- ) {
        scanf("%s%d,%d",a,&m,&y);
        int t1 = 0, t2 = 0;
        if ( (y%400==0)||(y%100!=0&&y%4==0) ) {
            if ( mp[a] > 2 ) y++;
        }
        y--;
        t1+=(y/4-y/100+y/400);
        scanf("%s%d,%d",a,&m,&y);
        if ( (y%400==0)||(y%100!=0&&y%4==0) ) {
            if ( mp[a] > 2 ||(mp[a]==2&&m==29) ) {
                y++;
            }
        }
        y--;
        t2+=(y/4-y/100+y/400);
        printf("Case %d: ",icase++ );
        printf("%d\n",t2-t1);
    }
    return 0;
}
