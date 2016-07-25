# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 1123
char a[MAX][MAX];
int x[MAX],y[MAX];
int main(void)
{
    int n,m; cin>>n>>m;
    int num = 0;
    for ( int i = 1;i <= n;i++ ) {
        scanf("%s",a[i]);
        for ( int j = 1;j <= m;j++ ) {
            if ( a[i][j-1]=='*' ) {
                num++;
                x[i]++;
                y[j]++;
            }
        }
    }
    for ( int i = 1;i <= n;i++ ) {
        for ( int j = 1;j <= m;j++ ) {
            if ( x[i]+y[j]-(a[i][j-1]=='*')==num ) {
                puts("YES");
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
