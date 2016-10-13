#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct mat
{
    ll m[2][2];
};

mat I=
{
    1,0,
    0,1
};

mat mul(mat a,mat b,ll mm);
mat quick_pow(mat a,ll b,ll mm);
ll qq_pow(ll a,ll b,ll mm);
ll euler(ll n);
ll ff[120];
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("b2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    ff[0]=1;
    ff[1]=1;
    for(int i=2;i<=35;i++)
    {
        ff[i]=ff[i-1]+ff[i-2];
        //if(i<=5) {printf("%d %lld\n",i,ff[i]);}
    }
    int cas=1;
    while(t--)
    {
        ll a,b,P,n;
        scanf("%lld%lld%lld%lld",&a,&b,&P,&n);
        printf("Case #%d: ",cas++);

        //printf("%lld %lld %lld %lld ",a,b,P,n);

        if(n==1)
        {
            printf("%lld\n",a%P);
            continue;
        }
        if(n==2)
        {
            printf("%lld\n",b%P);
            continue;
        }
        if(n==3)
        {
            printf("%lld\n",(a%P)*(b%P)%P);
            continue;
        }

        ll phi=euler(P);
        //printf("%lld\n",phi);
        mat ji;
        ji.m[0][0]=1,ji.m[0][1]=1;
        ji.m[1][0]=1,ji.m[1][1]=0;
        ll z1,z2;
        if(n<=35&&ff[n-3]<phi)
        {
            z1=ff[n-3];
        }
        else
        {
            mat x1=quick_pow(ji,n-3,phi);
            z1=x1.m[0][0];
            z1+=phi;
        }
        if(n<=35&&ff[n-2]<phi)
        {
            z2=ff[n-2];
        }
        else
        {
            mat x2=quick_pow(ji,n-2,phi);
            z2=x2.m[0][0];
            z2+=phi;
        }
        //printf("%lld %lld\n",z1,z2);

        ll ans=1;
        ans=ans*qq_pow(a,z1,P);
        ans%=P;
        ans=ans*(qq_pow(b,z2,P))%P;
        printf("%lld\n",ans%P);
    }
    return 0;
}

ll euler(ll n)//返回euler(n)
{
     ll i;
     ll res = n,a = n;
     for(i = 2;i*i <= a; ++i)
     {
         if(a%i == 0)
         {
             res -= res/i; //p(n) = (p - p/p1)(1 - 1/p2)......
             while(a%i == 0) a/=i;
         }
     }
     if(a > 1) res -= res/a;//存在大于sqrt(a)的质因子
     return res;
}

ll qq_pow(ll a,ll b,ll mm)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a;
        ans%=mm;
        a=a*a;
        a%=mm;
        b>>=1;
    }
    return ans;
}

mat quick_pow(mat a,ll b,ll mm)
{
    mat ans=I;
    while(b)
    {
        if(b&1)
            ans=mul(ans,a,mm);
        a=mul(a,a,mm);
        b>>=1;
    }
    return ans;
}

mat mul(mat a,mat b,ll mm)
{
    mat c;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c.m[i][j]+=(a.m[i][k]*b.m[k][j])%mm;
                c.m[i][j]%=mm;
            }
        }
    }
    return c;
}
