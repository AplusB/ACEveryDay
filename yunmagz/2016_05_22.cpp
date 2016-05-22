//百毒之星
//03
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100010
#define mod 1000000007
LL inv[N];
int main()
{
    inv[1] = 1;
    for(int i=2;i<100010;i++)
    {
        if(i >= mod) break;
        inv[i] = (mod -mod/ i) * inv[mod % i] % mod;
    }

    int t,n,m,cas=1;
    while(~scanf("%d%d",&n,&m)){
        LL ans=0;
        LL t1=1,t2=1;
        for(int i=1;i<min(n,m)-1;i++){
            t1=t1*(n-i-1)%mod*inv[i]%mod;
            t2=t2*(m-i-1)%mod*inv[i]%mod;
            ans=(ans+t1*t2%mod)%mod;
        }
        cout<<(ans+1)%mod<<endl;
    }
    return 0;
}
//06
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100010
#define mod 1000000007
int b[25000];
int a[25000];
int n,s,x;
void solve(){
    for(int i=1;i<=n;i++) {
        b[12500]=1;
        x=12500;
        for(int j=i-1;j>0;j--)
        {
            if(a[j]<a[i]) x--;
            else x++;
            b[x]++;
        }
        x=12500;
        s=b[12500];
        for (int j=i+1; j<=n; j++)
        {
            if(a[j]>a[i]) x--;
            else x++;
            s+=b[x];
        }
        printf("%d%c",s,i==n?'\n':' ');
        b[12500]=0;
        x=12500;
        for(int j=i-1;j>0;j--)
        {
            if(a[j]<a[i]) x--;
            else x++;
            b[x]--;
        }
    }
}
int main()
{
    while (~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
