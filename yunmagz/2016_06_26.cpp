//lightoj1389 - Scarecrow
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
#define N 100100  
using namespace std;  
char s[200];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n;  
        scanf("%d",&n);  
        scanf("%s",s);  
        int ans=0,cnt=0;  
        for(int i=0;i<n;i++)  
        {  
            if(s[i]=='.')  
                cnt++;  
            else  
            {  
                ans+=cnt/3;  
                cnt=cnt%3;  
                if(cnt==2)  
                    ans++;  
                else if(cnt==1)  
                {  
                    i++;  
                    ans++;  
                }  
                cnt=0;  
            }  
        }  
        if(cnt)  
            ans+=cnt/3+(cnt%3?1:0);//剩余有cnt点没考虑  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
