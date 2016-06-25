//lightoj1166 - Old Sorting
#include<bits/stdc++.h>  
using namespace std;  
int a[120],b[120];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n;  
        scanf("%d",&n);  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            b[a[i]]=i;  
        }  
        int ans=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(a[i]==i) continue;  
            int tmp=b[i];  
            b[a[i]]=tmp;  
            swap(a[i],a[tmp]);  
            ans++;  
        }  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
