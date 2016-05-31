#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n)
{
    if(n == 0)return 0;
    return (n/m)+solve(m,n/m);
}

int odd(int x,int n)
{
    if(n == 0) return 0;
    if(n % 10 >= x)
        return (n/10) + 1 + odd(x,n/5);
    else
        return (n/10) + odd(x,n/5);
}
int oddcnt(int x,int n)
{
    if(n == 0)return 0;
    return oddcnt(x,n/2)+odd(x,n);
}

int turn[4][4] =
{
    {6,2,4,8},{1,3,9,7},{1,7,9,3},{1,9,1,9}
};
int main(void)
{
    int n,m;
    while(cin>>n>>m)
    {
        int num2 = solve(2,n) - solve(2,n-m) - solve(2,m);
        int num3 = oddcnt(3,n) - oddcnt(3,n-m) - oddcnt(3,m)+2*oddcnt(9,n) - 2*oddcnt(9,n-m) -2*oddcnt(9,m);
        int num5 = solve(5,n) - solve(5,n-m) - solve(5,m);
        int num7 = oddcnt(7,n) - oddcnt(7,n-m) - oddcnt(7,m);
        //int num9 = oddcnt(9,n) - oddcnt(9,n-m) - oddcnt(9,m);
        int ans = 1;
        if(num2 > num5)
        {
            ans *= turn[0][(num2 - num5)%4];
            ans %= 10;
        }
        else if(num2 < num5)
            ans *= 5;
        ans %= 10;
        ans *= turn[1][num3%4];
        ans %= 10;
        ans *= turn[2][num7%4];
        ans %= 10;
//        ans *= turn[3][num9%4];
//        ans %= 10;
        printf("%d\n",ans);
    }


    return 0;
}
