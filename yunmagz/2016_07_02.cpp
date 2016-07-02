/lightoj1105 - Fi Binary Number
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >q;
string s[100010];
int a[100010],f[100010];
int main(){
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=44;i++)
        f[i]=f[i-1]+f[i-2];
    int t,cas=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        printf("Case %d: ",cas++);
        int j=44;
        while(f[j]>n) j--;
        while(j>=0){
            if(n>=f[j]){
                n-=f[j];
                cout<<"1";
            }
            else cout<<"0";
            j--;
        }
        puts("");
    }
    return 0;
}
