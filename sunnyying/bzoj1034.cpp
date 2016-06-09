#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define N 100100
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define mod 9875321
int a[1000010],b[1000010],c[1000010],d[1000010],vis[1000010],n;
int main()
{
  //  freopen("in.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    int ans1=0,ans2=0;
    int l1=0,r1=n-1,l2=0,r2=n-1;
    while(l1<=r1)
    {
        if(a[l1]>b[l2]) ans1+=2,l1++,l2++;
        else if(a[r1]>b[r2]) ans1+=2,r1--,r2--;
        else if(a[l1]==b[r2]) ans1++,r2--,l1++;
        else r2--,l1++;
    }
    l1=0,r1=n-1,l2=0,r2=n-1;
    while(l1<=r1)
    {
        if(b[l1]>a[l2]) l1++,l2++;
        else if(b[r1]>a[r2]) r1--,r2--;
        else if(b[l1]==a[r2]) ans2++,r2--,l1++;
        else ans2+=2,r2--,l1++;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
