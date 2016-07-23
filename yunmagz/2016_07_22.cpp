//hdu5312 Sequence
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const LL mod=1e9+7;
const double eps=1e-9;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}\
int biao[500000];

map<int, int> q;

int main()
{
    for (int i = 1; i <= 20000; i++)
    {
        biao[i] = 3 * i*(i - 1) + 1;
        q[biao[i]] = 1;
    }
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = (n - 1) % 6 + 1;
        if (m>2)
            cout << m << endl;
        else
        {
            if (m == 1)
                if (q.count(n))
                    cout << 1 << endl;
                else
                    cout << 7 << endl;
            else
            {
                int flag = 0;
                for (int i = 1; biao[i] + biao[i] <= n; ++i)
                    if (q.count(n - biao[i]))
                    {
                        flag = 1;
                        break;
                    }
                if (flag)
                    cout << 2 << endl;
                else
                    cout << 8 << endl;
            }
        }
    }
    return 0;
}
