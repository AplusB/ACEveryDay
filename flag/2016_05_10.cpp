#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mkp make_pair
const int md = 1000000007;
const LL up = 1e14 + 5;
const int maxn = 1e7 + 5;
bool isp[maxn];
vector < int > p;
vector < pair < LL, int > > mi;
vector < int > ans;

void init(){
    memset(isp, true, sizeof isp);
    mi.push_back(mkp(1, 1));
    for(int i = 2; i < maxn; i++){
        if(isp[i]){
            p.push_back(i);
            for(double j = (double)i * i; j < up; j *= i){
                mi.push_back(mkp((LL)j, i));
            }
        }
        for(int j = 0; j < p.size() && (LL)i * p[j] < maxn; j++){
            isp[i * p[j]] = false;
            if(i % p[j] == 0) break;
        }
    }
    sort(mi.begin(), mi.end());
    ans.push_back(1);
    for(int i = 1; i < mi.size(); i++){
        ans.push_back((LL)ans[i - 1] * mi[i].second % md);
    }
}

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        LL n;
        scanf("%lld", &n);
        int l = 0, r = mi.size() - 1, mid;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(mi[mid].first <= n)
                l = mid;
            else
                r = mid - 1;
        }
        printf("Case %d: %d\n", cas, ans[r]);
    }
	return 0;
}
