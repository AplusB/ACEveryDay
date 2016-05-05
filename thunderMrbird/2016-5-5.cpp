#include <bits/stdc++.h>
using namespace std;
int n;
set<string>st;
set<string>v[100010];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=n-1;i>4;i--){
        string t=s.substr(i,1);
        for(int j=i-1;j>=i-2&&j>4;j--){
            t=s[j]+t;
            if(v[i+1].size() == 1 && !v[i+1].count(t) || v[i+1].size()>1 ||i + 1 >= n){
                v[j].insert(t);
                st.insert(t);
            }
        }
    }
    cout<<st.size()<<endl;
    for(auto i : st){
        cout<<i<<endl;
    }
    return 0;
}
