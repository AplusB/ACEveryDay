# include <cstdio>
# include <iostream>
using namespace std;
bool is_prime ( int x )
{
    for ( int i = 2;i*i<=x;i++ ) {
        if ( x%i==0 ) return false;
    }
    return true;
}
int solve ( int x ) 
{
    //opt1
    if ( is_prime(x) ) return x;

    //opt2
    int temp = x;
    int sum = 0;
    for ( int i = 2;i*i <= temp;i++ ) {
        while ( temp%i==0 ) {
            sum+=i;
            temp/=i;
        }
        if ( temp==1 ) break;
    } 
    if ( temp > 1 ) sum+=temp;
    if ( sum==x ) return -1;
    else return solve(sum);
}
int main(void)
{
    int n;
    while ( scanf("%d",&n)!=EOF ) {
        printf("%d\n",solve(n));
    } 
    
    return 0;
} 
