/*
    并查集入门
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int ff[1011],t,s,r,n,m,i,j,k,l,ans;

int find(int x){
	if(ff[x]!=x)ff[x]=find(ff[x]);
	return ff[x];
}

void make(int a,int b){
	int f1=find(a);
	int f2=find(b);
	if(f1!=f2){
		ff[f2]=f1;
		ans--;
	}
}

int main()
{
    scanf("%d",&t);
    while(t--){
    	for(i=1;i<1011;i++)ff[i]=i;
    	scanf("%d%d",&n,&m);ans=n;
    	for(i=1;i<=m;i++){
    		scanf("%d%d",&r,&s);
    		make(r,s);
		}
		printf("%d\n",ans);
	}
	
	return 0;
 } 
