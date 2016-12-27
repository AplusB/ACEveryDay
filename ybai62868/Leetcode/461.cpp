class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int res = 0;
        while ( z ) {
            if ( z%2==1 ) res++;
            z/=2;
        }
        return res;
    }
};
