#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int m,n;
int main()
{
        int x=0,y=0,ans=0,l=0;
        scanf("%d %d",&m,&n);
        cin>>s;
        for(int r=0;r<m;r++)
        {
                if(s[r]=='a') x++;
                else y++;
                while(min(x,y)>n)
                {
                        if(s[l]=='a') x--;
                        else y--;
                       l++;
                }
                ans=max(ans,r-l+1);
        }
        printf("%d",ans);
        return 0;
}
