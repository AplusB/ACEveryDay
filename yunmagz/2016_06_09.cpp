//lightoj1110 - An Easy LCS
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
char dp[111][111][111];  
char a[111],b[111];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%s %s",a+1,b+1);  
        memset(dp,0,sizeof(dp));  
        int lena=strlen(a+1);  
        int lenb=strlen(b+1);  
        for(int i=1;i<=lena;i++)  
        {  
            for(int j=1;j<=lenb;j++)  
            {  
                if(a[i]==b[j])  
                {  
                    int len=strlen(dp[i-1][j-1]);  
                    strcpy(dp[i][j],dp[i-1][j-1]);  
                    dp[i][j][len]=a[i];  
                }  
                else  
                {  
                    int len1=strlen(dp[i-1][j]);  
                    int len2=strlen(dp[i][j-1]);  
                    if(len1>len2)  
                        strcpy(dp[i][j],dp[i-1][j]);  
                    else if(len1<len2)  
                        strcpy(dp[i][j],dp[i][j-1]);  
                    else  
                    {  
                        if(strcmp(dp[i-1][j],dp[i][j-1])>0)  
                            strcpy(dp[i][j],dp[i][j-1]);  
                        else  
                            strcpy(dp[i][j],dp[i-1][j]);  
                    }  
                }  
            }  
        }  
        printf("Case %d: ",cas);  
        int len=strlen(dp[lena][lenb]);  
        if(len==0)  
            puts(":(");  
        else  
            puts(dp[lena][lenb]);  
    }  
    return 0;  
}  
