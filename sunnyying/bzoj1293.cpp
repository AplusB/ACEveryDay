#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
#define INF 0x7fffffffff
#define ll long long
vector<ll>v[1000010];
ll b[110];
struct node
{
    int x,i;
}c[1000010];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
	ll n,k,x,y,m=0;
	scanf("%lld%lld",&n,&k);
	memset(b,0,sizeof(b));
	for(int i=1;i<=k;i++)
    {
        scanf("%lld",&x);
        while(x--)
        {
            scanf("%lld",&y),v[m].push_back(i),c[m].x=y,c[m].i=m++;
        }
    }
    sort(c,c+m,cmp);
    ll ans=INF;
    int r=-1,sum=0;
    for(int l=0;l<m;l++)
    {
        while(sum<k&&r<m-1)
        {
            int xx=c[r+1].i;
            for(int i=0;i<v[xx].size();i++)
            {
                int xxx=v[xx][i];
                b[xxx]++;
                if(b[xxx]==1) sum++;
            }
            r++;
        }
        if(sum==k) ans=min(ans,(ll)c[r].x-c[l].x);
        int xx=c[l].i;
        for(int i=0;i<v[xx].size();i++)
        {
            int xxx=v[xx][i];
            b[xxx]--;
            if(b[xxx]==0) sum--;
        }
    }
    cout<<ans<<endl;
	return 0;
}
