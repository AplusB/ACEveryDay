#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0,n,t=0,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d);
        ans+=5;
        if(d>t)
        {
            ans+=(d-t)*6;
        }
        else if(d<t)
        {
            ans+=(t-d)*4;
        }
        t=d;
    }
    cout<<ans<<endl;
    return 0;
}
