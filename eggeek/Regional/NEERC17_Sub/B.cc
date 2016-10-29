#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

bool check(ll l, ll r, ll w) {
    ll lft = l - w;
    ll rht = r;
    if ( rht <= lft ) return true;
    ll k = gcd(w, r);
    ll tmp = (lft + k) / k * k;
    if (tmp > lft && tmp < rht) return false;
    return true;
}

int main() {
    ll l, r, w;
    cin >> l >> r >> w;
    printf(check(l, r, w)?"OK\n": "DEADLOCK\n");
	return 0;
}
