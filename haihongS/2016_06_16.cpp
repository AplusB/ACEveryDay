#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;
const ll inf=1e8+2;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        string aha;
        cin>>aha;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+j-1>=n) break;
                int rt=i+j;
                int x=0,y=0;
                for(int k=i;k<rt;k++)
                {
                    if(aha[k]=='U'){x--;}
                    else if(aha[k]=='R'){y++;}
                    else if(aha[k]=='D'){x++;}
                    else if(aha[k]=='L'){y--;}
                }
                if(x==0 && y==0) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

