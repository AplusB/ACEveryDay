#include <algorithm>
#include <complex>
#include <vector>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef complex<double> Comp;

const Comp I(0, 1);

const int MAX_N = 1 << 20;
Comp tmp[MAX_N];
void DFT(Comp*a, int n, int rev) {
	if (n == 1)
		return;
	for (int i = 0; i < n; ++i) {
		tmp[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (i & 1)
			a[n / 2 + i / 2] = tmp[i];
		else
			a[i / 2] = tmp[i];
	}
	Comp*a0 = a, *a1 = a + n / 2;
	DFT(a0, n / 2, rev);
	DFT(a1, n / 2, rev);
	Comp cur(1, 0);
	double alpha = 2 * M_PI / n * rev;
	Comp step = exp(I * alpha);
	for (int k = 0; k < n / 2; ++k) {
		tmp[k] = a0[k] + cur * a1[k];
		tmp[k + n / 2] = a0[k] - cur * a1[k];
		cur *= step;
	}
	for (int i = 0; i < n; ++i) {
		a[i] = tmp[i];
	}
}

int main() {
	static Comp a[1 << 20] = { }, b[1 << 20] = { };
	int n = 1 << 20;
	DFT(a, n, 1);
	DFT(b, n, 1);
	for (int i = 0; i < n; ++i) {
		a[i] *= b[i];
	}
	DFT(a, n, -1);
	for (int i = 0; i < n; ++i) {
		a[i] /= n;
	}
}
