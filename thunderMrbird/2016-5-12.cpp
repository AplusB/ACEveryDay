#include <bits/stdc++.h>
using namespace std;
char a[100005];
map<char,int>mp;
int main()
{
    int tt=0,m,n,T,ans=0;
    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]>1) ans++;
    }
    printf("%d\n",ans>26-mp.size()?-1:ans);
    return 0;
}
