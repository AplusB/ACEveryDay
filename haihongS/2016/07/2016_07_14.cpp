#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
  
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
  
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
ll pre[2*maxn];
  
void Mobius();
ll deal(int n,int m,int k);
  
int main()
{
    Mobius();
    pre[0]=0;
    for(int i=1;i<maxn;i++)
        pre[i]=pre[i-1]+mu[i];
  
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        ll ans=0;
        ans=deal(b/k,d/k,1)-deal((a-1)/k,d/k,1)-deal(b/k,(c-1)/k,1)+deal((a-1)/k,(c-1)/k,1);
        printf("%lld\n",ans);
    }
  
    return 0;
}
  
ll deal(int n,int m,int k)
{
    int len=min(n,m);
    int last=k;
    ll ans=0;
    for(int i=1;i<=len;i=last+1)
    {
        int tmp=min(n/(n/i),m/(m/i));
        ans+=(ll)(n/i)*(m/i)*(pre[tmp]-pre[i-1]);
        last=tmp;
    }
    return ans;
}
  
void Mobius()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
