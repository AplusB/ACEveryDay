#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;

typedef pair<double,double> P;
double x[10],y[10];
set<P> ans;

int main()
{
	while(~scanf("%lf%lf",&x[0],&y[0]))
	{
		for(int i=1;i<3;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		ans.clear();
		double tx,ty,nx,ny;
		tx=(x[0]+x[1])/2,ty=(y[0]+y[1])/2;
		nx=2*tx-x[2],ny=2*ty-y[2];
		ans.insert(make_pair(nx,ny));

		tx=(x[0]+x[2])/2,ty=(y[0]+y[2])/2;
		nx=2*tx-x[1],ny=2*ty-y[1];
		ans.insert(make_pair(nx,ny));

		tx=(x[1]+x[2])/2,ty=(y[1]+y[2])/2;
		nx=2*tx-x[0],ny=2*ty-y[0];
		ans.insert(make_pair(nx,ny));

		int len=ans.size();
		printf("%d\n",len);
		set<P>::iterator it;
		for(it=ans.begin();it!=ans.end();++it)
		{
			printf("%.0lf %.0lf\n",it->first,it->second);
		}

		

	}
	return 0;
}
