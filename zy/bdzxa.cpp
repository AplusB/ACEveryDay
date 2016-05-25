#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

typedef long long ll;
map<int,int> mp;
vector<int> vec;

int main()
{
    int ca;
    int cnt = 0;
    int ans;
    ll x,m,k,c,temp;
    scanf("%d",&ca);
    for(int cc=1;cc<=ca;cc++)
    {
        temp=0;
        ans=-1;
        mp.clear();
        vec.clear();
        scanf("%lld%lld%lld%lld",&x,&m,&k,&c);

        for(int i = 1; i <= m; ++i)
        {
            temp=temp*10+x;
            temp%=k;
            if(mp[temp]!=0)
            {
                int len=i-mp[temp];
                m-=mp[temp]-1;
                m%=len;
                if(m==0) ans=vec[vec.size()-1];
                else ans=vec[mp[temp]+m-1];
                break;
            }
            vec.push_back(temp);
            mp[temp]=i;
        }
        
        if(ans==-1) ans=vec[m-1];
        printf("Case #%d:\n",cc);
        
        if(ans==c)
            puts("Yes");
        else puts("No");
    }
    return 0;
}

