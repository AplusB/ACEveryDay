# include <cstdio>
# include <iostream>
using namespace std;
int main(void)
{
    int n; cin>>n;
    int ans1 = (n/7)*2+max(n%7-5,0);
    int ans2 = (n/7)*2+min(n%7,2);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
