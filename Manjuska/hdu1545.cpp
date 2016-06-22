#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
#define LL __int64  
using namespace std;  
LL dp[100][10][10];  
void dfs(int n,int m){  
    dp[1][0][1]=1;  
    dp[1][1][0]=1;  
    int i,j,k;  
    for(i=2;i<=n;i++){  
        for(j=1;j<=m;j++){  
            dp[i][0][j]=dp[i-1][0][j-1]+dp[i-1][1][j-1];  
            dp[i][j][0]=dp[i-1][j-1][0]+dp[i-1][j-1][1];  
        }  
        for(j=1;j<m;j++){  
            for(k=1;k<m;k++){  
                dp[i][j][k]=dp[i-1][j-1][k+1]+dp[i-1][j+1][k-1];  
            }  
        }  
        for(j=1;j<m;j++){  
            dp[i][j][m]=dp[i-1][j+1][m-1];  
            dp[i][m][j]=dp[i-1][m-1][j+1];  
        }  
    }  
}  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF){  
        dfs(n,m);  
        LL p=0;  
        for(int i=0;i<=m;i++){  
            for(int j=0;j<=m;j++){  
                p+=dp[n][i][j];  
            }  
        }  
        printf("%I64d\n",p);  
    }  
}  
