# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
using namespace std;
# define MAX 123
vector<int>v;
int main(void)
{
    int n,k; scanf("%d%d",&n,&k);
    for ( int i = 1;i <= n;i++ ) {
        v.push_back(i);
    }
    int t = 0;
    for ( int i = 0;i < k;i++ ) {
        int x; cin>>x;
        t = ( t+x )%n;
        cout<<v[t]<<" ";
        n--;
        v.erase(v.begin()+t);
    }


    return 0;
}
