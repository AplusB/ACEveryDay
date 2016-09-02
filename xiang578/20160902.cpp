#include<bits/stdc++.h>
using namespace std;
char a[10];
int main()
{
    double w,t,l,ans;
    ans=0.65;
    for(int i=0; i<3; i++)
    {
        cin>>w>>t>>l;
        if(w>max(t,l))
        {
            a[i]='W';
            ans*=w;
        }

        if(t>max(w,l))
        {
            a[i]='T';
            ans*=t;
        }

        if(l>max(w,t))
        {
            a[i]='L';
            ans*=l;
        }

    }
    ans-=1;
    for(int i=0; i<3; i++)
        cout<<a[i]<<" ";
    cout<<ans*2<<endl;
    return 0;
}
