//L1-1
#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
    int t;
    while(cin>>t)
    {
        for(int i=0; i<t; i++)
            scanf("%d/%d",&a[i],&b[i]);
        int aa=a[0];
        int bb=b[0];
        for(int i=1; i<t; i++)
        {
            b[0]=bb*b[i];
            a[0]=aa*b[i]+a[i]*bb;
            bb=b[0]/__gcd(b[0],a[0]);
            aa=a[0]/__gcd(b[0],a[0]);
        }
        int n=aa/bb;
        aa%=bb;
        if(n&&aa) cout<<n<<" "<<aa<<"/"<<bb<<endl;
        else if(n) cout<<n<<endl;
        else if(aa) cout<<aa<<"/"<<bb<<endl;
        else puts("0");
    }
    return 0;
}
//L1-2
#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    for(int i=0;i<3;i++)
        cin>>a[i];
    sort(a,a+3);
    cout<<a[0]<<"->"<<a[1]<<"->"<<a[2]<<endl;
    return 0;
}
//L1-3
#include <bits/stdc++.h>
using namespace std;
map<int ,int >mp;
char a[10010];
char b[10010];
int main()
{
    gets(a);
    gets(b);
    int la=strlen(a);
    int lb=strlen(b);
    for(int i=0;i<lb;i++)
        mp[b[i]]=1;
    for(int i=0;i<la;i++){
        if(!mp[a[i]])
            printf("%c",a[i]);
    }
    puts("");
    return 0;
}
//L1-4
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)
        ans*=2;
    cout<<"2^"<<n<<" = "<<ans<<endl;
    return 0;
}
//L1-5
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a=1,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        a*=i;
        ans+=a;
    }
    cout<<ans<<endl;
    return 0;
}
//L1-6
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"This is a simple problem."<<endl;
    return 0;
}
//L1-7
#include <bits/stdc++.h>
using namespace std;
map<int ,int >mp;
char a[5];
int main()
{
    int n;
    cin>>n>>a;
    for(int i=0;i<(n+1)/2;i++){
        for(int j=0;j<n;j++)
            printf("%c",a[0]);
        puts("");
    }
    return 0;
}
//L1-8
#include <bits/stdc++.h>
using namespace std;
char s[110][25];
int a[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
bool v[110];
char b[]={'1','0','X','9','8','7','6','5','4','3','2'};
int main()
{
    int n;
    bool all=true;
    cin>>n;
    memset(v,false,sizeof v);
    for(int i=0;i<n;i++){
        cin>>s[i];
        int sum=0;
        int flag=1;
        for(int j=0;j<17&&flag;j++){
            if(s[i][j]>='0'&&s[i][j]<='9') sum+=a[j]*(int)(s[i][j]-'0');
            else flag=0;
        }
        if(flag){
            sum%=11;
            if(b[sum]==s[i][17]) v[i]=true;
            else all=false;
        }
        else all=false;
    }
    if(!all){
        for(int i=0;i<n;i++)
            if(!v[i]) cout<<s[i]<<endl;
    }
    else puts("All passed");
    return 0;
}
//L2-4
#include <bits/stdc++.h>
using namespace std;
char s[1010];
int n;
int solve1(int x){
    int l=x-1,r=x+1;
    while(l>=0&&r<n&&s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}
int solve2(int x){
    int l=x,r=x+1;
    while(l>=0&&r<n&&s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}
int main(){
    gets(s);
    n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,solve1(i));
        ans=max(ans,solve2(i));
    }
    cout<<ans<<endl;
    return 0;
}
