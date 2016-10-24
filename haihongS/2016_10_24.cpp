#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+9;

int a[maxn],ans[maxn];

int gcd(int x,int y);

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==1)
        {
            printf("0\n");
            printf("%d\n",a[1]);
            continue;
        }
        int cnt=0;
        int last,pos=0;
        last=a[1];
        ans[pos++]=last;
        for(int i=2;i<=n;i++)
        {
            int gg=gcd(last,a[i]);
            if(gg!=1)
            {
                ans[pos++]=1;
                ans[pos++]=a[i];
                last=a[i];
            }
            else
            {
                ans[pos++]=a[i];
                last=a[i];
            }
        }
        printf("%d\n",pos-n);
        for(int i=0;i<pos;i++)
        {
            if(i!=0) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
