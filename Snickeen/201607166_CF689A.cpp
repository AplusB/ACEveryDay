#include<bits/stdc++.h>
using namespace std;
int t,n,m,i,a[22];
int main()
{
    char x[22];
    scanf("%d%s",&n,x);
    for(i=0;i<n;i++)a[x[i]-'0']++;
    if(a[0]){
        if(a[1]+a[2]+a[3])puts("YES");
        else puts("NO");
    }
    else if((a[1]||a[2]||a[3])&&(a[7]||a[9])&&(a[1]||a[4]||a[7])&&(a[3]||a[6]||a[9]))puts("YES");
    else puts("NO");
    return 0;
}
