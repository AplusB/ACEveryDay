class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=0,k=2147483648;
        while (n > 0)
        {
            m|=(n&1)*k;
            n>>=1;
            k>>=1;
        }
        return m;
    }
};
