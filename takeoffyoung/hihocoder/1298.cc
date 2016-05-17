#include <bits/stdc++.h>

const int MAXN = 5000000+10;

int tag[MAXN];
std::vector<int> prime;
int low, hign;

void solve(int m)
{
    if (tag[m] == 0) {
        tag[m] = m - 1;
        prime.push_back(m);
    }
    for (auto it = prime.begin(); it != prime.end(); ++it) {
        int t = *it;
        if (t * m > hign) {
            break;
        }else{
            if (m % t == 0) {
                tag[m * t] = tag[m] * t;
                break;
            }else{
                tag[m * t] = tag[m] * (t - 1);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    scanf("%d %d", &low, &hign);
    for (int i = 2; i <= hign; ++i) {
        solve(i);
    }
    int val = hign;
    int rst = 0;
    for (int i = low; i <= hign; ++i) {
        if (tag[i] < val) {
            val = tag[i];
            rst = i;
        }
    }
    printf("%d", rst);
    return 0;
}
