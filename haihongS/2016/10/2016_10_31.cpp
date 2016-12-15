#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char a[20];

int main()
{
    int n,v;
    while(~scanf("%d%d",&n,&v))
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            int len=strlen(a);
            int f[30]={0};
            for(int j=0;j<len;j++)
            {
                f[a[j]-'0']=1;
            }
            int flag=1;
            if(flag)
            {
                for(int j=0;j<=v;j++)
                {
                    if(f[j]==0)
                    {
                        flag=0;break;
                    }
                }
            }
            if(flag) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
