#include <bits/stdc++.h>
using namespace std;

int a[55];
int main()
{
        int n, k;
        cin >> n >> k;
        int ret = 0;
        for(int i = 1; i <= n; i++) {
                cin >> a[i];
        }
        for(int i = 1; i <= k; i++) 
        {
                if(!a[i]) break;
                ret++;
        }
        if(a[k]>0)
        for(int i = k + 1;  i <= n; i++) 
        {
                if(a[i] == a[k]) ret++;
        }
        cout << ret << endl;
        return 0;
}
