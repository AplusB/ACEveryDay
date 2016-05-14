#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int tt=0,m,n,T,ans=0;
    cin>>s;
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]==s[i])
        {
            for(char j='a';j<='z';j++)
            {
                if(j!=s[i]&&j!=s[i+1])
                {
                    s[i]=j;
                    break;
                }
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
