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
int b[20000],a[20000],len,c[20000];
int ef(int x)
{
    int l=1,r=len;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(x==b[mid]) return mid;
        else if(x>b[mid]) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x),a[n-i+1]=x;
    b[1]=a[1];len=1;c[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<b[len]) len++,b[len]=a[i],c[i]=len;
        else
        {
            int xx=ef(a[i]);
            b[xx]=a[i],c[i]=xx;
        }
    }
    int m;
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&x);
       if(x>len) cout<<"Impossible"<<endl;
       else
       {
           int xx=x,mark=0;
           for(int i=n;i>=1;i--)
           {
               if(c[i]>=xx&&(xx==x||a[i]>mark))
               {
                   if(xx==1) cout<<a[i]<<endl;
                   else cout<<a[i]<<" ";
                   xx--;mark=a[i];
               }
               if(xx==0) break;
           }
       }
    }
    return 0;
}
