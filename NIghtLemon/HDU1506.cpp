#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
typedef long long ll;
int n,t;
ll a[MAXN],b[MAXN],c[MAXN];
ll ans;

int main()
{
	while(scanf("%d",&n) && n!=0){
		b[0] = 0; a[n+1] = 0;
		ans = 0;
		for(int i=1; i<=n; i++){
			scanf("%d",&t); a[i] = t;
		}
		b[1] = 1; c[n] = n; 
		for(int i=2; i<=n ;i++){
			t = i;
			while(t>1 && a[i] <= a[t-1])
				t = b[t-1];
			b[i] = t;
		}
		ans = (n - b[n] +1) * a[n];
		for(int i=n-1; i; i--){
			t = i;
			while(t<n && a[i]<=a[t+1])
				t = c[t+1];
			c[i] = t;
			if( (c[i] - b[i] + 1)*a[i] > ans )
				ans = (c[i] - b[i] + 1)*a[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
