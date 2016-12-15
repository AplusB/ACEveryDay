#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>


using namespace std;
typedef long long ll;

#define L(x) (1 << (x))  
const double PI = acos(-1.0);  
const int Maxn = (6e4+9)*4;  
double ax[Maxn], ay[Maxn], bx[Maxn], by[Maxn];  
int revv(int x, int bits)  
{  
    int ret = 0;  
    for (int i = 0; i < bits; i++)  
    {  
        ret <<= 1;  
        ret |= x & 1;  
        x >>= 1;  
    }  
    return ret;  
}  
void fft(double * a, double * b, int n, bool rev)  
{  
    int bits = 0;  
    while (1 << bits < n) ++bits;  
    for (int i = 0; i < n; i++)  
    {  
        int j = revv(i, bits);  
        if (i < j)  
            swap(a[i], a[j]), swap(b[i], b[j]);  
    }  
    for (int len = 2; len <= n; len <<= 1)  
    {  
        int half = len >> 1;  
        double wmx = cos(2 * PI / len), wmy = sin(2 * PI / len);  
        if (rev) wmy = -wmy;  
        for (int i = 0; i < n; i += len)  
        {  
            double wx = 1, wy = 0;  
            for (int j = 0; j < half; j++)  
            {  
                double cx = a[i + j], cy = b[i + j];  
                double dx = a[i + j + half], dy = b[i + j + half];  
                double ex = dx * wx - dy * wy, ey = dx * wy + dy * wx;  
                a[i + j] = cx + ex, b[i + j] = cy + ey;  
                a[i + j + half] = cx - ex, b[i + j + half] = cy - ey;  
                double wnx = wx * wmx - wy * wmy, wny = wx * wmy + wy * wmx;  
                wx = wnx, wy = wny;  
            }  
        }  
    }  
    if (rev)  
    {  
        for (int i = 0; i < n; i++)  
            a[i] /= n, b[i] /= n;  
    }  
}  
int solve(ll a[],int na,ll b[],int nb,ll ans[]) //两个数组求卷积,有时ans数组要开成long long  
{  
    int len = max(na, nb), ln;  
    for(ln=0; L(ln)<len; ++ln);  
    len=L(++ln);  
    for (int i = 0; i < len ; ++i)  
    {  
        if (i >= na) ax[i] = 0, ay[i] =0;  
        else ax[i] = a[i], ay[i] = 0;  
    }  
    fft(ax, ay, len, 0);  
    for (int i = 0; i < len; ++i)  
    {  
        if (i >= nb) bx[i] = 0, by[i] = 0;  
        else bx[i] = b[i], by[i] = 0;  
    }  
    fft(bx, by, len, 0);  
    for (int i = 0; i < len; ++i)  
    {  
        double cx = ax[i] * bx[i] - ay[i] * by[i];  
        double cy = ax[i] * by[i] + ay[i] * bx[i];  
        ax[i] = cx, ay[i] = cy;  
    }  
    fft(ax, ay, len, 1);  
    for (int i = 0; i < len; ++i)  
        ans[i] = (ll)(ax[i] + 0.5);  
    return len;  
}  
int solve(long long a[], int na, int ans[]) //自己跟自己求卷积,有时候ans数组要开成long long  
{  
    int len = na, ln;  
    for(ln = 0; L(ln) < na; ++ln);  
    len=L(++ln);  
    for(int i = 0; i < len; ++i)  
    {  
        if (i >= na) ax[i] = 0, ay[i] = 0;  
        else ax[i] = a[i], ay[i] = 0;  
    }  
    fft(ax, ay, len, 0);  
    for(int i=0; i<len; ++i)  
    {  
        double cx = ax[i] * ax[i] - ay[i] * ay[i];  
        double cy = 2 * ax[i] * ay[i];  
        ax[i] = cx, ay[i] = cy;  
    }  
    fft(ax, ay, len, 1);  
  
    for(int i=0; i<len; ++i)  
        ans[i] = ax[i] + 0.5;  
    return len;  
}

ll a[Maxn],b[Maxn],pp[Maxn],go[Maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&pp[i]);
		for(int i=0;i<n;i++)
			b[i]=pp[n-i-1];
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=a[i]*a[i]+b[i]*b[i];
		}
		solve(a,n,b,n,go);
		for(int i=0;i<n;i++)
		{
			go[i]+=go[i+n];
		}
		ll maxx=go[0];
		int loca=0;
		for(int i=1;i<n;i++)
		{
			if(go[i]>maxx)
			{
				maxx=go[i],loca=i;
			}
		}
		ll now=0;
		for(int i=0;i<n;i++)
		{
			now+=a[i]*pp[(i+n-1-loca)%n];
		}
		printf("%lld\n",ans-2*now);
	}
	return 0;
}
