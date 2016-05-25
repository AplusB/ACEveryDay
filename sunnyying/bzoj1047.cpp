#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define mod 1000000007
#define ll long long
using namespace std;
int n,m,k;
ll a[1010][1010],mmax[1010][1010],mmin[1010][1010];
ll ans;
struct node
{
   ll x;
   int i;
}q[1010*1010],qq[1010*1010];
int t[1010][1010],tt[1010][1010];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
    for(int j=1;j<=m;j++)
    {
        int l=0,r=-1,l1=0,r1=-1,res=0,rres=0;
        for(int i=1;i<=n;i++)
        {
            while(r>=l&&a[i][j]>=q[r].x) r--;
            while(i>k&&l<=r&&q[l].i<=t[i-k][j]) l++;
            t[i][j]=res++;
            q[++r].x=a[i][j];
            q[r].i=t[i][j];
            mmax[i][j]=q[l].x;
        }
        for(int i=1;i<=n;i++)
        {
            while(r1>=l1&&a[i][j]<=qq[r1].x) r1--;
            while(i>k&&l1<=r1&&qq[l1].i<=tt[i-k][j]) l1++;
            tt[i][j]=rres++;
            qq[++r1].x=a[i][j];
            qq[r1].i=tt[i][j];
            mmin[i][j]=qq[l1].x;
        }
    }
    for(int i=k;i<=n;i++)
    {
        int l=0,r=-1,l1=0,r1=-1,res=0,rres=0;
        for(int j=1;j<=m;j++)
        {
            while(r>=l&&mmax[i][j]>=q[r].x) r--;
            while(j>k&&l<=r&&q[l].i<=t[i][j-k]) l++;
            t[i][j]=res++;
            q[++r].x=mmax[i][j];
            q[r].i=t[i][j];
            while(r1>=l1&&mmin[i][j]<=qq[r1].x) r1--;
            while(j>k&&l1<=r1&&qq[l1].i<=tt[i][j-k]) l1++;
            tt[i][j]=rres++;
            qq[++r1].x=mmin[i][j];
            qq[r1].i=tt[i][j];
            if(j>=k)
            {
                if(j==k&&i==k) ans=q[l].x-qq[l1].x;
                else ans=min(ans,q[l].x-qq[l1].x);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
