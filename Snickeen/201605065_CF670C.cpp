/*
    //1.排序+二分 
    //2.用STL中的map
*/

//v1.0 排序+二分 186 ms  5300 KB

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
struct TT{
	int a,b;
};TT tt[200011],ss[200011];
int ff,n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;

int cmp3(TT a,TT b){return a.a<b.a;}

int bs( int e,int begin, int end)  
{  
    int mid,left=begin,right=end;  
    while(left<=right){  
        mid=(left+right)>>1;  
        if(ss[mid].a==e) return mid;
        if(e<ss[mid].a) right=mid-1;
        if(e>ss[mid].a) left=mid+1;  
    }  
    return 0;  
}  

int main(){
	scanf("%d",&n);
	repu(i,1,n)scanf("%d",&ss[i].a);
	scanf("%d",&m);
	rep(i,0,m)scanf("%d",&tt[i].a);
	rep(i,0,m)scanf("%d",&tt[i].b);
	
	sort(ss+1,ss+n+1,cmp3);
	ss[0].a=ss[0].b=0;
	j=1;ss[j].b=1;
	repu(i,2,n){
		if(ss[i].a==ss[i-1].a)ss[j].b++;
		else {
			ss[++j].a=ss[i].a;
			ss[j].b=1;
		}
	}
	r=bs(tt[0].a,1,j);
	s=bs(tt[0].b,1,j);
	mmax=ss[r].b;
	num=mmax+ss[s].b;
	ans=0;
	
	rep(i,1,m){
		r=bs(tt[i].a,1,j);
		s=bs(tt[i].b,1,j);
		if(ss[r].b>mmax||(ss[r].b==mmax&&ss[s].b+mmax>num)){
			mmax=ss[r].b;
			num=mmax+ss[s].b;
			ans=i;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}


/*
//v2.0 STL  436 ms  21600 KB

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<=b;i++)
map<int,int> num;
int n,m,a[200005],r,s,i,ans,maxa=-1,sum=-1;
int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&m),num[m]++;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		scanf("%d",&m);
		r=num[a[i]];s=num[m];
		if(r>maxa||(r==maxa&&s+r>sum))maxa=r,sum=r+s,ans=i;
	}
	printf("%d\n",ans);
	return 0;
}

*/
