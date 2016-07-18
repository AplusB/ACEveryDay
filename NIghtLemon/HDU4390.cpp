#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL MOD =1000000007;
LL c[507][507];
int a[507],tot,n,k;
LL b[507],ans;
void init()
{
    for(int i=0;i<=500;i++){
        c[i][0] = c[i][i] =1;
        for(int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;  
    }
}

void  resolve(int k)
{
    int i=2;
    while(k>1){
        while(k%i==0) a[tot++]=i,k/=i;
        i++;
    }
}

void solve()
{
    memset(b,0,sizeof(b));
    int cnt=0;
    b[0]=1;
    sort(a,a+tot);
    for(int i=1;i<tot;i++)
        if(a[i]!=a[i-1]) b[++cnt]=1;
        else b[cnt]++;
    ans =1;
    for(int i=0;i<=cnt;i++) ans=(ans*c[n+b[i]-1][n-1])%MOD;
    for(int i=1;i<n;i++){
        LL tmp=c[n][i];
        for(int j=0;j<=cnt;j++)
            tmp=(tmp*c[n-i+b[j]-1][n-i-1])%MOD;
        if(i&1) ans=((ans-tmp)%MOD+MOD)%MOD;
        else ans=(ans+tmp)%MOD;
    }
}

int main()
{
    init();
    while(scanf("%d",&n)!=EOF){
        tot = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            resolve(k);
        }
        solve();
        printf("%I64d\n",ans);
    }
    return 0;
}
