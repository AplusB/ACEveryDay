
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

bitset<5010000>b;
vector<int>v;
bitset<5010000>c;
int main()
{
   // freopen("in.txt","r",stdin);
    int t,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		b.reset();
		c.reset();
		int w=0;
		for(int i=1;i<=n*2-2;i++){
			scanf("%d",&x);
			w^=x;
			if(b[x]==1){
				b[x]=0;
				c[x]=1;
			}
			else{
				b[x]=1;
				c[x]=1;
			}
		}
		v.clear();
		if(w==0){
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					v.push_back(i);
					v.push_back(i);
					break;
				}
			}
		}
		else{
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				v.push_back(i);
			}
		}
		}
		cout<<v[0]<<" "<<v[1]<<endl;
	}
    return 0;
}
