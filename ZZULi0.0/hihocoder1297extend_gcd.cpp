#include <bits/stdc++.h>
#define VEXNUM 105
#define EDGENUM 505
#define LL long long
using namespace std;


void extend_gcd(LL A, LL B, LL &a, LL &b)
{
    if(A % B == 0)
    {
        a = 0;
        b = 1;
        return;
    }
    LL tx,ty;
    extend_gcd(B,A%B,tx,ty);
    LL x = ty,y = tx - (A/B)*ty;
    a = x;
    b = y;
}
LL gcd(LL A, LL B)
{
    if(A % B == 0) return B;
    else
        return gcd(B,A%B);
}

LL solve(LL s1, LL s2, LL v1, LL v2, LL m)
{
    LL A = v1 - v2;
    LL B = m;
    LL C = s2 - s1;

    if(A < 0)
        A += m;
    LL D = gcd(A,B);

    if(C % D) return -1;

    A = A/D;
    B = B/D;
    C = C/D;

    LL x,y;
    extend_gcd(A,B,x,y);
    x = (x*C)%B;
    while(x < 0) x += B;

    return x;

}

int main(void)
{
    LL s1,s2,v1,v2,m;
    cin>>s1>>s2>>v1>>v2>>m;
    cout<<solve(s1,s2,v1,v2,m)<<endl;
    return 0;
}
