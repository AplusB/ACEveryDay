#include<bits/stdc++.h>
using namespace std;

int t,n,m,ans,pa[55],cnt[55];
vector<int> e[55],v[55];

int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}

int main()
{
	int i,j,k,l;
	cin>>n>>m;
	for(i=1;i<=n;i++)pa[i]=i,cnt[i]=1;
	while(m--){
		cin>>i>>j;
		int fa=find(i),fb=find(j);
		if(fa!=fb){
			pa[fa]=fb;
			cnt[fb]+=cnt[fa];
		}
		if(cnt[fb]>3)return cout<<"-1\n",0;
	}
	for(i=1;i<=n;i++){
		e[find(i)].push_back(i);
		cnt[i]=0;
	}
	for(m=0,i=1;i<=n;i++){
		if(e[i].size()==3)v[m++]=e[i];
	}
	for(k=0,i=1;i<=n;i++){
		if(e[i].size()==2)v[m++]=e[i],k++;
		if(e[i].size()==1)cnt[++cnt[0]]=e[i][0];
	}
	if(cnt[0]<k)return cout<<"-1\n",0;
	for(i=1;i<=k;i++){
		v[m-k+i-1].push_back(cnt[i]);
	}
	for(i=1,j=k+1;j<=cnt[0];j++,i++){
		cout<<cnt[j]<<" ";
		if(i%3==0)cout<<endl;
	}
	for(i=0;i<m;i++){
		for(auto x:v[i])cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
