#include <iostream>
#include <stdio.h>
#include <cstdlib>
using  namespace std;

int a[500005];
int ans[500005];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t;
    for (int i=0;i<n;i++)
    {
        int j;
        ans[i]=a[i];
        for(j=i;j<n-1;j++)
            if(a[j]==a[j+1]) break;

        t=j-i-1;
        for(int k=i;k<=j;k++)
        {
            if(k-i<j-k)
                ans[k]=a[i];
            else
                ans[k]=a[j];
        }
        if(cnt<t) cnt=t;
        i=j;
    }
    if (cnt<t) cnt=t;
    printf("%d\n",cnt/2+cnt%2);

    for (int i=0;i<n;i++)
    {
        if (i!=0) cout<<" ";
        printf("%d",ans[i]);
    }
    cout<<endl;
    return 0;
}
