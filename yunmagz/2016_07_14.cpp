//Educational Codeforces Round 14
//A - Fashion in Berland
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
int main()
{
	int n,m,a;
	cin>>n;
	int cnt=0;
	int flag=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a) cnt++;
	}
	if(n==1&&cnt) flag=1;
	else if(n>1&&cnt==n-1) flag=1;
	if(flag) puts("YES");
	else puts("NO");
	
    return 0;
}
//B - s-palindrome
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
int a[1005];
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int flag=1;
	for(int i=0;i<=n/2&&flag;i++){
		if((s[i]=='b'&&s[n-i-1]=='d')||
		   (s[i]=='d'&&s[n-i-1]=='b')||
		   (s[i]=='q'&&s[n-i-1]=='p')||
		   (s[i]=='p'&&s[n-i-1]=='q')||
		   (s[i]=='o'&&s[n-i-1]=='o')||
		   (s[i]=='O'&&s[n-i-1]=='O')||
		   (s[i]=='X'&&s[n-i-1]=='X')||
		   (s[i]=='x'&&s[n-i-1]=='x')||
		   (s[i]=='A'&&s[n-i-1]=='A')||
		   (s[i]=='M'&&s[n-i-1]=='M')||
		   (s[i]=='v'&&s[n-i-1]=='v')||
		   (s[i]=='V'&&s[n-i-1]=='V')||
		   (s[i]=='U'&&s[n-i-1]=='U')||
		   (s[i]=='T'&&s[n-i-1]=='T')||
		   (s[i]=='Y'&&s[n-i-1]=='Y')||
		   (s[i]=='I'&&s[n-i-1]=='I')||
		   (s[i]=='w'&&s[n-i-1]=='w')||
		   (s[i]=='W'&&s[n-i-1]=='W')||
		   (s[i]=='H'&&s[n-i-1]=='H'))
			continue;
		flag=0;
	}
	if(flag) puts("TAK");
	else puts("NIE");
    return 0;
}
//D - Swaps in Permutation
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
#define MAX_SIZE 1000005    
int pa[MAX_SIZE];
vector<int>g[MAX_SIZE];
void init()
{    
    for(int i = 0; i < MAX_SIZE; i++)    
    {    
        pa[i] = i;    
    }   
}
int findset(int v)
{    
    int t1,t2=v;    
    while(v!=pa[v])    
        v=pa[v];    
    while(t2!=pa[t2])
    {    
        t1=pa[t2];    
        pa[t2]=v;    
        t2=t1;    
    }    
    return v;    
}
void union_nodes(int a, int b)
{    
    int a1 = findset(a);    
    int b1 = findset(b);  
    if(a1 != b1)
    {  
        pa[a1] = b1;
    }  
}
bool cmp(int a,int b){
	return a>b;
}
int b[MAX_SIZE],a[MAX_SIZE];
int main()
{
	init();
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		union_nodes(u,v);
	}
	for(int i=1;i<=n;i++){
		int l=findset(i);
		g[l].pb(i);
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;j<g[i].size();j++)
			b[cnt++]=a[g[i][j]];
		sort(b,b+cnt,cmp);
		for(int j=0;j<g[i].size();j++)
			a[g[i][j]]=b[j];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
