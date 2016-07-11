//CodeForces 617B 

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int MAXN=1100;

const int N=1e2+10;


int main()
{
    int a[N];
	int n,m,i,flag,s,t,flat;
    LL ans=1;
    flat=flag=0;
    cin>>n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        if(a[i]==1){
            flat=1;
            if(flag){
                ans*=(i-s);
                s=i;
            }
            else{
                s=i;
                flag=1;
            }
        }
    }
    if(!flat){
        puts("0");
        return 0;
    }
    cout<<ans<<endl;
}



