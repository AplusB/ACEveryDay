#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,maxn,maxsav;
int a[5005];
int b[5005];
int sav[5005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++)
    {
        memset(sav,0,sizeof(sav));
        maxsav=a[i];
        maxn=1;
        b[a[i]]++;
        sav[a[i]]++;
        for(int j=i+1;j<=n;j++)
        {
            sav[a[j]]++;
            if(sav[a[j]]>=maxn)
            {
                if(sav[a[j]]==maxn)
                maxsav=min(a[j],maxsav);
                else
                maxsav=a[j];
                maxn=sav[a[j]];
            }
            b[maxsav]++;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
}
