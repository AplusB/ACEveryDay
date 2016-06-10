
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 70
#define MOD 1000000007
#define mem(a , b) memset(a , b , sizeof(a))
#define ll long long
#define INF 100000000
ll a[20] , b[20];
ll l , r;

ll solve(ll n , ll m , ll c[])
{
    ll x = n /10 , y = n % 10 , tmp = x;
    for(int i = 0 ; i <= y ; i ++) c[i] += m;
    for(int i = 0 ; i <= 9 ; i ++) c[i] += m * x;
    c[0] -= m;
    while(tmp)
    {
        c[tmp%10] += m*(y+1);
        tmp /=10;
    }
    if(x) solve(x-1 , m*10 , c);
}

int main()
{
    while(scanf("%lld %lld" , &l , &r) != EOF)
    {
        solve(l-1 , 1 , a);
        solve(r , 1 , b);
        for(int i = 0 ; i <= 9 ; i ++)
            printf("%lld\n" , b[i] - a[i]) ;
    }
    return 0;
}

