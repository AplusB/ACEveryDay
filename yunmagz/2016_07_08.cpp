//CCCC练习
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define fi first
#define se second
#define PSI pair<string,int>
map<string,int>m;
PSI a[100010];
bool cmp(PSI a,PSI b){
	return a.fi<b.fi;
}
int main()
{
	string s;
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,s);
		m[s]++;
	}
	int cnt=0;
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
		a[cnt++]=mp(it->fi,it->se);
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i].fi;
		printf(" %.4lf%%\n",a[i].se*100.0/n);
	}
    return 0;
}
