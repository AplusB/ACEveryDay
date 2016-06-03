#include<bits/stdc++.h>
using namespace std;
string t;
char s[110000+5];
int p[410000+5];

int main()
{
    while(~scanf("%s",s))
    {
        int len=strlen(s);
        t="*#";
        for(int i=0;i<len;i++)
        {
            t+=s[i];
            t+='#';
        }
        int ans=1,l=t.size(),id=0,mx=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<l;i++)
        {
            if(mx<i)
                p[i]=1;
            else
                p[i]=min(p[2*id-i],mx-i);
            while(t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(p[i]+i>mx)
            {
                id=i;
                mx=p[i]+i;
            }
            ans=max(ans,p[i]-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
