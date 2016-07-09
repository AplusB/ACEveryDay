#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

const int N=1e3+7;

int a[N];
int dp[N];

int kill(int len,int x)
{
    int be,ed;
    be=1;ed=len;
    while(be<=ed)
    {
        int mid=(be+ed)/2;
        if(dp[mid]>=x){
            ed=mid-1;
        }
        else
            be=mid+1;
    }
    return be;
}


int main()
{
    int i,j,n,len;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[1]=a[1];
    len=1;
    for(i=2;i<=n;i++)
    {
        if(dp[1]>=a[i])
            j=1;
        else if(dp[len]<a[i])
            j=++len;
        else
            j=kill(len,a[i]);
        dp[j]=a[i];
    }
    cout<<len<<endl;
    return 0;
}

