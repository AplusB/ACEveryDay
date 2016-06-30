//lightoj1328 - A Gift from the Setter
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
#define N 50100  
using namespace std;  
ll a[120000];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1; cas<=t; cas++)  
    {  
       int n,k,c;  
       scanf("%d %d %d %lld",&k,&c,&n,&a[0]);  
       for(int i=1;i<n;i++)  
       {  
           a[i]=(k*a[i-1]+c)%mod;  
       }  
       sort(a,a+n);  
       ll ans=0;  
       for(int i=0;i<n;i++)  
       {  
           ans+=-1*(ll)(n-1-2*i)*a[i];  
       }  
       printf("Case %d: %lld\n",cas,ans);  
    }  
    return 0;  
}  
