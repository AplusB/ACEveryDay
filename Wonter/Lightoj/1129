#include <bits/stdc++.h>
using namespace std;
set<string> st;
string str[10050];
int main()
{
    int T;
    int _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        st.clear();
        int n;
        scanf("%d", &n);
        bool flag = false;
        for(int i = 1; i <= n; ++i)
        {
            cin >> str[i];
            st.insert(str[i]);
        }
        for(int i = 1; i <= n; ++i)
        {
            for(string::size_type j = 0; j < str[i].length(); ++j)
            {
                if(st.find(str[i].substr(0, j)) != st.end())
                    flag = true;
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("Case %d: NO\n", _case++);
        else
            printf("Case %d: YES\n", _case++);
    }
    return 0;
}
