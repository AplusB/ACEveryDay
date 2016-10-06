/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MP make_pair

LL t,n,m,ans;
deque<pair<LL,LL> > q;
string s;

int main()
{
	//freopen("1.in.txt","r",stdin);
	//freopen("2.out.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie();
	LL i,j,k,l,ca=0;
	cin>>t;
	while(t--){
        cout<<"Case #"<<(++ca)<<":"<<endl;
        while(!q.empty())q.pop_front();
		cin>>n;l=0;LL dir=0;
		while(n--){
		    cin>>s;
			if(dir){
				if(s[0]=='R')dir^=1LL;
				else if(s[0]=='Q'){
					l=q.size();ans=0;
					if(!l){
						cout<<"Invalid."<<endl;
						continue;
					}
                    if(q[l-1].first==0){
                    	if(q[l-1].second==1&&q.size()==1)ans=0;
                    	else ans=1;
                        cout<<ans<<endl;
                        continue;
					}
					if(l>2||(l==2&&q[0].second>1LL))ans=1LL;
					ans+=q[l-1].second;
                    cout<<(ans&1LL?"1":"0")<<endl;
				}
				else if(s[1]=='U'){
					cin>>m;
					if(l=q.size()){
                        if(m==q[0].first){
                            q[0].second+=1LL;
                        }
                        else q.push_front(MP(m,1LL));
					}
					else {
                        q.push_front(MP(m,1LL));
					}
				}
				else {
					if(l=q.size()){
                        q[0].second-=1LL;
                        if(q[0].second==0LL)q.pop_front();
					}
				}
			}
			else {

				if(s[0]=='R')dir^=1LL;
				else if(s[0]=='Q'){
					l=q.size();ans=0;
					if(!l){
						cout<<"Invalid."<<endl;
						continue;
					}
					if(q[0].first==0){
						if(q[0].second==1&&q.size()==1)ans=0;
						else ans=1;
                        cout<<ans<<endl;
                        continue;
					}
					if(l>2||(l==2&&q[1].second>1LL))ans=1LL;
					ans+=q[0].second;
                    cout<<(ans&1?"1":"0")<<endl;
				}
				else if(s[1]=='U'){
					cin>>m;
					l=q.size();
					if(l){
                        if(m==q[l-1].first){
                            q[l-1].second+=1LL;
                        }
                        else q.push_back(MP(m,1LL));
					}
					else {
                        q.push_back(MP(m,1LL));
					}
				}
				else {
					if(l=q.size()){
                        q[l-1].second-=1LL;
                        if(q[l-1].second==0LL)q.pop_back();
                    }
				}
			}
		}
	}
	return 0;
}
