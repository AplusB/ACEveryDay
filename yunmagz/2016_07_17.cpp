//1374 - Confusion in the Problemset
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
#define N 50100  
using namespace std;  
int a[12345];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1; cas<=t; cas++)  
    {  
       int n,x;  
       memset(a,0,sizeof(a));  
       scanf("%d",&n);  
       for(int i=0;i<n;i++)  
       {  
           scanf("%d",&x);  
           if(x>n) continue;  
           a[x]++;  
       }  
       int f=1;  
       for(int i=1;i<=n;i++)  
       {  
           if(a[i-1])  
            a[i-1]--;  
           else if(a[n-i])  
            a[n-i]--;  
           else  
           {  
               f=0;  
               break;  
           }  
       }  
       printf("Case %d: %s\n",cas,f?"yes":"no");  
    }  
    return 0;  
}  
