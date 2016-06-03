#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int arr[60];
int main()
{
    int T;
    int _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        mp.clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            ++mp[arr[i] + 1];
        }
        long long ans = 0;
        for(map<int,int>::iterator it = mp.begin();it != mp.end(); ++it)
            ans += it->first * ceil( 1.0 * it->second / it->first );
        printf("Case %d: %lld\n", _case++, ans);
    }
    return 0;
}
