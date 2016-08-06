#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
ll n,m;

struct node
{
    ll mat[4][4];
} A,B;

node operator *(const node &n1,const node &n2)
{
    node c;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            c.mat[i][j]=0;
            for(int k=0; k<4; k++)
            {
                c.mat[i][j]=(c.mat[i][j]+n1.mat[i][k]*n2.mat[k][j]+m)%m;
            }
        }
    }
    return c;
}
node fst(node n1,ll x)
{
    node c;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            c.mat[i][j]=(i==j);
        }
    }
    while(x)
    {
        if(x&1) c=c*n1;
        n1=n1*n1;
        x>>=1;
    }
    return c;
}

int main()
{
    int _;
    while(~scanf("%lld%lld",&n,&m))
    {
        if(n==0&&m==0) break;
        if(n==1) printf("%lld\n",1%m);
        else if(n==2) printf("%lld\n",5%m);
        else if(n==3) printf("%lld\n",11%m);
        else if(n==4) printf("%lld\n",36%m);
        else
        {
            A.mat[0][0]=36%m;
            A.mat[1][0]=11%m;
            A.mat[2][0]=5%m;
            A.mat[3][0]=1%m;

            B.mat[0][0]=1%m;B.mat[0][1]=5%m;B.mat[0][2]=1%m;B.mat[0][3]=(-1)%m;
            B.mat[1][0]=1%m;B.mat[1][1]=0;B.mat[1][2]=0;B.mat[1][3]=0;
            B.mat[2][0]=0;B.mat[2][1]=1%m;B.mat[2][2]=0;B.mat[2][3]=0;
            B.mat[3][0]=0;B.mat[3][1]=0;B.mat[3][2]=1%m;B.mat[3][3]=0;
            B=fst(B,n-4);
            A=B*A;
            cout<<A.mat[0][0]%m<<endl;
        }
    }
    return 0;
}
