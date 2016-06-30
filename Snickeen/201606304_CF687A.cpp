/*
    现学二分图，一点儿都不熟练:(
*/

#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct NODE{
	int v;
	NODE *next;
};
struct G{
	NODE *next=NULL;
};G gra[100005];
struct TT {
	int v,num;
};TT tt,ss,rr;
int co[100005],t,s,r,n,m,ans,fanum[2];
bool vis[100005],vis2[100005];
queue<TT> q;
queue<int> fans[2];

void addedge(int a,int b){
	NODE *p = new NODE;
	p->v=b;
	p->next=gra[a].next;
	gra[a].next=p;
}

int bfs()
{
	while(q.size()){
		ss=q.front();
		q.pop();vis[ss.v]=1;
		NODE *p=gra[ss.v].next;
		while(p!=NULL){
			tt.v=p->v;
			tt.num=ss.num^1;
			if(vis[tt.v]){
				p=p->next;
				continue;
			}
			if(co[tt.v]==ss.num)return 1;
			co[tt.v]=tt.num;
			q.push(tt);
			if(!vis2[tt.v])fans[tt.num].push(tt.v),fanum[tt.num]++;
			vis2[tt.v]=1;
			p=p->next;
		}
    }
    return 0;
}

int main()
{
	int i,j,k,l,res,tmp;
	memset(co,-1,sizeof(co));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&r,&s);
		addedge(r,s);
		addedge(s,r);
	}
	for(i=1;i<=n;i++){
		NODE *p=gra[i].next;
		if(p!=NULL&&(!vis[i])){
			fans[0].push(i);fanum[0]++;co[i]=0;vis[i]=1;vis2[i]=1;
			tt.v=p->v;tt.num=1;co[tt.v]=1;
			q.push(tt);fans[1].push(tt.v);fanum[1]++;
			for(p=p->next;p!=NULL;p=p->next){
				tt.v=p->v;tt.num=1;
				q.push(tt);co[tt.v]=1;vis2[tt.v]=1;
				fans[1].push(tt.v);fanum[1]++;
			}
			if(bfs())return 0*puts("-1");
		}
	}
//	if(bfs())puts("-1");
//	else {
		for(i=0;i<2;i++){
			printf("%d\n",fanum[i]);
			while(fans[i].size())printf("%d ",fans[i].front()),fans[i].pop();
			puts("");
		}
//	}
	
	return 0;
}
