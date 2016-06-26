#include<bits/stdc++.h>
using namespace std;
char a[1024][20],b[1024][20];
int main()
{
    int n,f1=0,f2=0;
    int use[1024],cnt=0;
    memset(use,0,sizeof(use));
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s%s",a[i],b[i]);
        int len=strlen(b[i]);
        f2=0;
        for(int j=0; j<len; j++)
        {
            if(b[i][j]=='1')
            {
                f2=1;
                b[i][j]='@';
            }
            if(b[i][j]=='0')
            {
                f2=1;
                b[i][j]='%';
            }
            if(b[i][j]=='l')
            {
                f2=1;
                b[i][j]='L';
            }
            if(b[i][j]=='O')
            {
                f2=1;
                b[i][j]='o';
            }
        }
        if(f2)
        {
            cnt++;
            use[i]=1;
        }
    }
    if(cnt==0)
    {
        if(n<=1)
            printf("There is %d account and no account is modified\n",n);
        else
            printf("There are %d accounts and no account is modified\n",n);
    }
    else
    {
        printf("%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            if(use[i])
                printf("%s %s\n",a[i],b[i]);
        }
    }
    return 0;
}
