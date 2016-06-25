#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int a[100000+10];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]]==1) {printf("%d\n",a[i]);return 0;}
    }
    puts("None");
    return 0;
}
