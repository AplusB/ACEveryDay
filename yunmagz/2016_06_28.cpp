//lightoj	1076 - Get the Containers
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
#define N 1010  
using namespace std;  
int n,k;  
int a[N];  
int pd(int x)  
{  
    int cnt=0,tmp=0;  
    for(int i=1;i<=n;i++)  
    {  
        if(a[i]>x) return 0;  
        if(tmp+a[i]<=x)  
        {  
            tmp+=a[i];  
        }  
        else  
        {  
            tmp=a[i];  
            cnt++;  
        }  
    }  
    return cnt<k;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%d %d",&n,&k);  
        int l=0,r=0;  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            r+=a[i];  
            l=max(l,a[i]);  
        }  
        int ans;  
        while(l<=r)  
        {  
            int mid=(l+r)/2;  
            if(pd(mid))  
            {  
                r=mid-1;  
                ans=mid;  
            }  
            else  
                l=mid+1;  
        }  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
