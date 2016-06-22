#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class BadNeighbors{
public: 
	int maxDonations(vector<int> don){
		int n = don.size();
		int dp[45];
		bool use0[45];
		memset(dp, 0, sizeof(dp));
		memset(use0, 0, sizeof(use0));
		int ans = 0;
		dp[0] = don[0];
		use0[0] = 1;
		for(int i=1; i<=n-2; i++){
			dp[i] = don[i];
			for(int j=0; j<=i-2; j++){
				if(dp[j] + don[i] > dp[i]){
					dp[i] = dp[j] + don[i];
					if(use0[j])
						use0[i] = 1;
				}
			}
			ans = max(ans, dp[i]);
		}
		dp[n-1] = don[n-1];
		for(int j=0; j<n-2; j++){
			if(use0[j]){
				if(dp[j]-don[0]+don[n-1] > dp[n-1])
					dp[n-1] = dp[j]-don[0]+don[n-1];
			}else if(dp[j] + don[n-1] > dp[n-1]){
				dp[n-1] = dp[j] + don[n-1];
				use0[n-1] = 1;
			}
		}
		ans = max(ans, dp[n-1]);
		// for(int i=0; i<n; i++)
		// 	printf("%d ", dp[i]);
		// printf("\n");
		return ans;
	}
};

int main()
{
	BadNeighbors b;
	int a[]={1,2,3,4,5,1,2,3,4,5};
	printf("%d\n", b.maxDonations(vector<int>(a, a+sizeof(a)/sizeof(int))));
	return 0;
}
