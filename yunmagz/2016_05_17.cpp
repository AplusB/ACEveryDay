//CF 353 DIV2
//A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    b-=a;
    if(!c){
        if(!b) puts("YES");
        else puts("NO");
    }
    else if(b%c==0&&b/c>=0) puts("YES");
    else puts("NO");
    return 0;
}
//B
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL aa[5];
int main()
{
    LL a,b,c,d,n;
    cin>>n>>a>>b>>c>>d;
    aa[0]=1;
    aa[1]=aa[0]+b-c;
    aa[2]=aa[0]+a-d;
    aa[3]=aa[0]+a+b-c-d;
    sort(aa,aa+4);
    aa[3]+=(1-aa[0]);
    if(n<aa[3]) puts("0");
    else cout<<(n-aa[3]+1)*n<<endl;
    return 0;
}
//C
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
multiset<LL>s;
int main(){
	int n;
	cin>>n;
	LL sum=0,x;
	for(int i=0;i<n;i++){
		cin>>x;
		sum+=x;
		s.insert(sum);
	}
	int ans=0;
	while(!s.empty()){
		ans=max(ans,int(s.count(*s.begin())));
		LL e=*s.begin();
		while(s.find(e)!=s.end()){
			s.erase(s.begin());
		}
	}
	cout<<n-ans<<endl;
}
//D
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
multiset<LL>s;
int main(){
	int n;
	cin>>n;
	LL sum=0,x;
	for(int i=0;i<n;i++){
		cin>>x;
		sum+=x;
		s.insert(sum);
	}
	int ans=0;
	while(!s.empty()){
		ans=max(ans,int(s.count(*s.begin())));
		LL e=*s.begin();
		while(s.find(e)!=s.end()){
			s.erase(s.begin());
		}
	}
	cout<<n-ans<<endl;
}
