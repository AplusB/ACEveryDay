class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        
        while (num != 0) {
            int mask = ~(num ^ (num - 1));
            num &= mask;
            cnt++;
        }
        
        return cnt;
    }
};
