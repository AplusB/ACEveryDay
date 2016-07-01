//lightoj1301 - Monitoring Processes
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
#define N 50100  
using namespace std;  
struct node  
{  
    int num,tmp;  
}a[N*2];  
int cmp(node a,node b)  
{  
    if(a.num==b.num)  
        return a.tmp>b.tmp;  
    return a.num<b.num;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1; cas<=t; cas++)  
    {  
        int n,s,t;  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
        {  
            scanf("%d %d",&s,&t);  
            a[i*2].num=s;  
            a[i*2].tmp=1;  
            a[i*2+1].num=t;  
            a[i*2+1].tmp=-1;  
        }  
        sort(a,a+n*2,cmp);  
        int ans=0,tmp=0;  
        for(int i=0;i<n*2;i++)  
        {  
            tmp+=a[i].tmp;  
            ans=max(ans,tmp);  
        }  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
