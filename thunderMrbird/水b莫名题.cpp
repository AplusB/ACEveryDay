#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        int temp;
        int m=n;
        while(n--)
        {
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        cout<<v[(m-1)/2]<<endl;
    }
    return 0;
}
