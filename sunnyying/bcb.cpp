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
#define ll long long
using namespace std;
int a[100010],ml[100010],mr[100010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ml[0]=mr[n+1]=0;
        for(int i=2;i<=n;i++) ml[i]=max(ml[i-1],abs(a[i]-a[i-1]));
        for(int i=n;i>=2;i--) mr[i]=max(mr[i+1],abs(a[i]-a[i-1]));
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int xx=ml[i-1];
            if(i+2<=n) xx=max(xx,mr[i+2]);
            if(i+1<=n&&i-1>=1) xx=max(xx,abs(a[i+1]-a[i-1]));
            ans=ans+xx;
        }
        cout<<ans<<endl;
    }
    return 0;
}
