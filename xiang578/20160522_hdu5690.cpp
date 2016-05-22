#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
int x,mod;
ll m;

struct Matrix
{
    ll mp[10][10];
    Matrix()
    {
        memset(mp,0,sizeof(mp));
    }
};

Matrix mul(Matrix a,Matrix b)
{
    int i,j,k;
    Matrix c;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            c.mp[i][j]=0;
            for(k=0; k<2; k++)
            {
                c.mp[i][j]=(c.mp[i][j]+a.mp[i][k]*b.mp[k][j])%mod;
            }
        }
    }
    return c;
}

Matrix mypow(Matrix t,ll x)
{
    Matrix c;
    for(int i=0; i<2; i++)
        c.mp[i][i]=1;
    while(x)
    {
        if(x&1)
            c=mul(c,t);
        t=mul(t,t);
        x>>=1;
    }
    return c;
}

int main()
{
    int _,c,cas=0;
    Matrix a,b;
    scanf("%d",&_);
    while(_--)
    {
        cin>>x>>m>>mod>>c;
        //scanf("%d%lld%d%d",&x,&m,&mod,&c);
        a.mp[0][0]=10;
        a.mp[0][1]=1;
        a.mp[1][0]=0;
        a.mp[1][1]=1;
        a=mypow(a,m-1);
        b.mp[0][0]=x;
        b.mp[0][1]=0;
        b.mp[1][0]=x;
        b.mp[1][1]=0;
        b=mul(a,b);
        printf("Case #%d:\n",++cas);
        if(b.mp[0][0]%mod==c) puts("Yes");
        else puts("No");

    }
    return 0;
}
