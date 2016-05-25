//* n变形内角和 = 180 * (n - 2)
#include<iostream>
#include<string>
using namespace std;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--){
		int n, m;
		scanf("%d%d",&n,&m);
		int a = 180 * (n - 2) / n, b = 180 * (m - 2) / m;
		int flag = 0;
		for(int i = 1;; ++i){
			if(i * a > 360) break;
			if(i * a == 360) flag = 1;
			for(int j = 1;; ++j){
				if(j * b > 360 || i * a > 360 || i * a + j * b > 360) break;
				if(i * a + j * b == 360 || j * b == 360)
					flag = 1;
			}
		}
		puts(flag ? "Yes" : "No");
	}

	return 0;
}
