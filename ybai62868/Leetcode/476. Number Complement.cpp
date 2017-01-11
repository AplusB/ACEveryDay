class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        int i = 0;

        while(copy != 0) {
            copy >>= 1;
            num ^= (1<<i);
            i += 1;
        }
        return num;
    }
};
