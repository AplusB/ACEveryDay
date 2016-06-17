#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
vector < int > a, b;
int num1[maxn], num2[maxn];
LL cnt[maxn];

int main(){
    int n, m, x;
    while(scanf("%d%d", &n, &m) != EOF){
        a.clear();
        b.clear();
        memset(num1, 0, sizeof num1);
        memset(num2, 0, sizeof num2);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            a.push_back(x);
            num1[x]++;
        }
        for(int i = 1; i <= m; i++){
            scanf("%d", &x);
            b.push_back(x);
            num2[x]++;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                cnt[abs(a[i] - b[j])] += (LL)num1[a[i]] * num2[b[j]];
            }
        }
        LL ans = 0;
        for(int i = 0; i < maxn; i++){
            ans += cnt[i] * (int)sqrt(i);
        }
        cout << ans << '\n';
    }
    return 0;
}

