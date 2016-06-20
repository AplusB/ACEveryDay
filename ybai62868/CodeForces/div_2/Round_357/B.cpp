# include <cstdio>
# include <iostream>
using namespace std;
int main(void)
{
    int n; cin>>n;
    int flag = 0;
    for ( int i = 0;i <= n;i+=1234567 ){
        for ( int j = i;j <= n;j+=123456 ){
            if ( (n-j)%1234==0 ) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
