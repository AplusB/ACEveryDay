#include<stdio.h>
#include<string.h>

const int maxn=210;

char str1[maxn],str2[maxn];
int dp[maxn][maxn],len;

struct node{
    int i,j;   
    char ch;       
}ans[maxn];

int max(int a,int b){
    return a>b?a:b;
}

void LCS(int m,int n){
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    if(dp[m][n]==0){   
        printf("%s%s",str1,str2);
    }else{
        i=m;j=n;
        len=0;
        while(i!=0 && j!=0){    
            if((dp[i][j]==dp[i-1][j-1]+1) && str1[i]==str2[j]){
                ans[len].i=i;
                ans[len].j=j;
                ans[len++].ch=str1[i];     
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    int len1,len2,i,j,k;
    while(scanf("%s%s",str1+1,str2+1)!=EOF){
        len1=strlen(str1+1);
        len2=strlen(str2+1);
        LCS(len1,len2);
        i=j=1;
        for(k=len-1;k>=0;k--){
            while(i!=ans[k].i){
                printf("%c",str1[i]);
                i++;
            }
            while(j!=ans[k].j){
                printf("%c",str2[j]);
                j++;
            }
            printf("%c",ans[k].ch);
            i++;j++;
        }
        printf("%s%s\n",str1+1+ans[0].i,str2+1+ans[0].j);
    }
    return 0;
}
