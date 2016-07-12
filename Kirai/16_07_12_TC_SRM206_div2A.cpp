class Bits {
public:
	int quickmul(int x, int n) {
		int ret = 1;
		while(n) {
			if(n & 1) ret *= x;
			n >>= 1;
			x *= x;
		}
		return ret;
	}
	int minBits(int n) {
		int p = 0;
		while(1) {
			if(quickmul(2, p) > n) {
				return p;
			}
			p++;
		}
	}
};
