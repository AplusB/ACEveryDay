//hdoj1042

#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=50000;
int f[maxn+1];


int main()
{
    int n,c,k;
    while(~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            c=0;        //代表进位
            for(int j=0;j<=maxn;j++)
            {
                int s=f[j]*i+c;
                f[j]=s%10;
                c=s/10;
            }
        }
        for(k=maxn;k>=0;k--)
            if(f[k]) break;
        for(int j=k;j>=0;j--)
            cout<<f[j];
        cout<<endl;
    }    
    return 0;
}
