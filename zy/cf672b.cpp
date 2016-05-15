#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int vis[30];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        int ans=0;
        string s;
        cin>>s;
        //cout<<s[0]<<endl;
        if(n>26) cout<<-1<<endl;
        else
            {
                for(int j=0;j<s.size();j++)
                    vis[s[j]-'a']=1;
                ans=n;
                for(int j=0;j<=25;j++)
                    if(vis[j]) ans--;
                cout<<ans<<endl;
            }
    }
    return 0;
}
