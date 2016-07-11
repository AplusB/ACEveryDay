#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,c,p,q;

int main()
{
    cin>>n>>a>>b>>p>>q;
    ll s1,s2,s3;
    c=a/__gcd(a,b)*b;
    s1=n/a;
    s2=n/b;
    s3=n/c;
    ll sum=s1*p+s2*q-s3*min(p,q);
    cout<<sum<<endl;
    return 0;
}
