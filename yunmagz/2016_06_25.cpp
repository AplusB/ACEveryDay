//lightoj1425 - The Monkey and the Oiled Bamboo
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
#define N 50100  
using namespace std;  
int a[123450],n;  
int pd(int x)  
{  
    for(int i=1; i<=n; i++)  
    {  
        int tmp=a[i]-a[i-1];  
        if(x==tmp)  
            x--;  
        else if(x<tmp)  
            return 0;  
    }  
    return 1;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1; cas<=t; cas++)  
    {  
        scanf("%d",&n);  
        a[0]=0;  
        for(int i=1; i<=n; i++)  
            scanf("%d",&a[i]);  
        int ans=0;  
        int l=1,r=100000000;  
        while(l<=r)  
        {  
            int mid=(l+r)/2;  
            int tmp=pd(mid);  
            if(tmp)  
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
