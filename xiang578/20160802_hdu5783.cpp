#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],ans;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        long long tmp;
        ans=0;
        for(int i=n-1;i>=0;i--)
        {
            tmp+=a[i];
            if(tmp>=0) {tmp=0;ans++;}

        }
        printf("%d\n",ans);
    }
    return 0;
}
