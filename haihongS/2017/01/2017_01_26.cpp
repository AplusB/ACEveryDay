#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const ll inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<ll,ll> P;

ll ans,X,H;
set<P> aha;

ll com(P x,P y);
ll S(P x);
void add(P x);
void del(P x);

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		aha.clear();
		int n;
		scanf("%d",&n);
		ll x1,ax,bx,cx;
		ll h1,ah,bh,ch;
		scanf("%lld%lld%lld%lld",&x1,&ax,&bx,&cx);
		scanf("%lld%lld%lld%lld",&h1,&ah,&bh,&ch);
		printf("Case #%d: ",cas++);
		ans=0;
		X=x1,H=h1;
		ll sum=0;

		aha.insert(make_pair(-inf,0LL));
		aha.insert(make_pair(inf,0LL));

		while(n--)
		{
			P now;
			now=make_pair(X,H);

			set<P>::iterator I,J;
			I=J=aha.lower_bound(now);
			I--;

			if(I->second>=now.first-I->first+now.second)
			{}
			else if(J->second>=J->first-now.first+now.second)
			{}
			else
			{
				while(I!=aha.begin())
				{
					if(now.second>=now.first-I->first+I->second)
					{
						P tmp=*I;
						I--;
						del(tmp);
					}
					else break;
				}
				while(J!=aha.end())
				{
					if(now.second>=J->first-now.first+J->second)
					{
						P tmp=*J;
						J++;
						del(tmp);
					}
					else break;
				}
				add(now);
			}
			//printf("*%d %lld %lld %lld\n",n,X,H,ans);
			sum+=ans;
			X=(ax*X+bx)%cx+1;
			H=(ah*H+bh)%ch+1;
			/*
			if(X==2647 && H==13010)
			{
				set<P>::iterator it;
				for(it=aha.begin();it!=aha.end();it++)
				{
					printf("%lld %lld\n",it->first,it->second);
				}
			}
			*/
		}
		printf("%.6lf\n",1.0*sum/4);
	}
	return 0;
}

ll com(P x,P y)
{
	if(x.second==0 || y.second==0) return 0LL;
	ll x1,x2,y1,y2;
	x1=x.first-x.second,x2=x.first+x.second;
	y1=y.first-y.second,y2=y.first+y.second;
	if(y1<=x2) return (x2-y1)*(x2-y1);
	else return 0LL;
}

void del(P x)
{
	set<P>::iterator a,b;
	a=b=aha.find(x);
	a--,b++;
	ans-=S(x)-com(*a,x)-com(x,*b)+com(*a,*b);
	aha.erase(x);
}

void add(P x)
{
	set<P>::iterator a,b;
	aha.insert(x);
	a=b=aha.find(x);
	a--,b++;
	ans+=S(x)-com(*a,x)-com(x,*b)+com(*a,*b);
}

ll S(P x)
{
	ll tmp=2LL*x.second;
	return tmp*tmp;
}

