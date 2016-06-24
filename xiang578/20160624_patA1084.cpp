#include<bits/stdc++.h>
using namespace std;
int u[1024];
int has[1024];

int main()
{
    string a,b;
    cin>>b;
    cin>>a;
    memset(u,0,sizeof(u));
    memset(has,0,sizeof(has));
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='a'&&a[i]<='z') a[i]=a[i]-'a'+'A';
        has[a[i]]=1;
    }
    string ans;
    for(int i=0;i<b.length();i++)
    {
        if(b[i]>='a'&&b[i]<='z') b[i]=b[i]-'a'+'A';
        if(has[b[i]]==0&&u[b[i]]==0)
        {
            u[b[i]]=1;
            ans+=b[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
