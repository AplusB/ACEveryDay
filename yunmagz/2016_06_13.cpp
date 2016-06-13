//CF#356 (Div. 2)
//A - Bear and Five Cards
#include <bits/stdc++.h>
using namespace std;
int a[10],v[110];
int main(){
    int sum=0;
    for(int i=0;i<5;i++){
        cin>>a[i];
        sum+=a[i];
        v[a[i]]++;
    }
    sort(a,a+5);
    int ans=sum;
    for(int i=4;i>=0;i--)
        if(v[a[i]]>=2)
            ans=min(ans,sum-a[i]*min(3,v[a[i]]));
    cout<<ans<<endl;
	return 0;
}
//B - Bear and Finding Criminals
#include <bits/stdc++.h>
using namespace std;
int a[10],v[110];
int main(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int d=min(m-1,n-m);
    for(int i=m-d;i<m;i++){
        if(a[i]&&a[m+m-i])
            ans+=2;
    }
    for(int i=1;i<m-d;i++)
        if(a[i]) ans++;
    for(int i=m+d+1;i<=n;i++)
        if(a[i]) ans++;
    if(a[m]) ans++;
    cout<<ans<<endl;
	return 0;
}
//	C - Bear and Prime 100
#include <bits/stdc++.h>
using namespace std;
bool pri(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}
int num[100]={2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,4,9,25,49};
int main()
{
    string s;
    int tmp=0;
    for(int i=0;i<20;i++)
    {
        cout<<num[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s[0]=='y')
            tmp++;
    }
    if(tmp>1)
        puts("composite");
    else
        puts("prime");
    return 0;
}
