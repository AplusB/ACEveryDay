//GCJ2016 1C A-Senate Evacuation
#include <bits/stdc++.h>
using namespace std;
int a[30];
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,n,cas=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        printf("Case #%d:",cas++);
        while(1){
            vector<int>v;
            int mx=0;
            for(int i=0;i<n;i++) mx=max(mx,a[i]);
            if(!mx) break;
            for(int i=0;i<n;i++) if(a[i]==mx) v.push_back(i);
            if(v.size()==2) printf(" %c%c",v[0]+'A',v[1]+'A'),a[v[0]]--,a[v[1]]--;
            else printf(" %c",v[0]+'A'),a[v[0]]--;
        }
        puts("");
    }
    return 0;
}

//GCJ2016 1C B-Slides!
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long er[55];
int mp[55][55],cas=1;
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t;
    cin>>t;
    er[0]=1;
    er[1]=1;
    for(int i=2;i<=50;i++) er[i]=er[i-1]*2;
    while(t--){
        cin>>n>>m;
        printf("Case #%d:",cas++);
        memset(mp,0,sizeof mp);
        for(int i=0;i<n-1;i++) for(int j=i+1;j<n-1;j++) mp[i][j]=1;
        for(int i=n-2;i>=0;i--){
			if(m>=er[i]){
				m-=er[i];
				mp[i][n-1]=1;
			}
		}
        if(m)puts(" IMPOSSIBLE");
        else {
            puts(" POSSIBLE");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) cout<<mp[i][j];
                puts("");
            }
        }
    }
    return 0;
}

//GCJ2016 1C C-Fashion Police
#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,cas=1,j,p,s,k;
    cin>>t;
    while(t--){
        cin>>j>>p>>s>>k;
        printf("Case #%d: ",cas++);
		if(k>s){
            printf("%d\n",j*p*s);
            for(int i=0;i<j;i++)
                for(int g=0;g<p;g++)
                    for(int h=0;h<s;h++)
                        printf("%d %d %d\n",i+1,g+1,h+1);
		}
		else {
            printf("%d\n",j*p*k);
            for(int i=0;i<j;i++)
                for(int g=0;g<p;g++)
                    for(int h=0;h<k;h++)
                        printf("%d %d %d\n",i+1,g+1,(i+g+h)%s+1);
		}
    }
    return 0;
}
