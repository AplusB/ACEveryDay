#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
const int MOD=365*24*60*60;
struct Q
{
    int a,b;
    void init(){
        scanf("%d%d",&a,&b);
    }
}a[MAXN];

bool cmp(Q a,Q b)
{
    return (long long)a.a*b.b<(long long)b.a*a.b;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
            a[i].init();
        sort(a,a+n,cmp);
        long long ans=0;
        for(int i=0;i<n;i++)
            ans = (ans + a[i].a+ans*a[i].b)%MOD;
          
        printf("%I64d\n",ans);
    }
    return 0;
}
