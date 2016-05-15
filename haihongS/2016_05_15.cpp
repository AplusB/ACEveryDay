#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=10+9;
const int inf=1e9+9;


int main()
{
    string aha;
    getline(cin,aha);
    int len=aha.length();
    int ans=1;
    for(int i=1;i<len-1;i++)
    {
        int lt=i-1,rt=i+1;
        int cnt=0;
        while(1)
        {
            if(aha[lt]==aha[rt])
            {
                cnt++;
                ans=max(ans,cnt*2+1);
            }
            else break;
            lt--,rt++;
        }
    }
    for(int i=0;i<len-1;i++)
    {
        int lt=i,rt=i+1;
        int cnt=0;
        while(1)
        {
            if(aha[lt]==aha[rt])
            {
                cnt+=2;
                ans=max(ans,cnt);
            }
            else break;
            lt--,rt++;
        }
    }
    printf("%d\n",ans);

    return 0;
}


