#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;

int n,m;
bool Judge(int h)
{
    if((h/2+h/3-h/6)<(n+m))
        return 0;
    if(h/2<n)
        return 0;
    if(h/3<m)
        return 0;
    return 1;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int s,t;
        s=max(n*2,m*3);
        t=3000000;
        while(s<t)
        {
            int mid=s+(t-s)/2;
            if(Judge(mid))
                t=mid;
            else
                s=mid+1;
        }
        printf("%d\n",s);
    }
    return 0;
}
