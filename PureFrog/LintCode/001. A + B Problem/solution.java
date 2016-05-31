/*
 * 我们在二进制位模拟一下即可。
 */
class Solution {
    /*
     * param a: The first integer
     * param b: The second integer
     * return: The sum of a and b
     */
    public int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        boolean carry = false;
        int ans = 0;

        for (int i = 0; i < 32; ++i) {
            int x = (a & 1), y = (b & 1);
            if (x == 1 && y == 1) {
                if (carry) {
                    ans |= (1 << i);
                }
                else 
                    carry = true;

            }
            else if (x == 1) {
                if (!carry)
                    ans |= (1 << i);
            }
            else if (y == 1) {
                if (!carry)
                    ans |= (1 << i);
            }
            else {
                if (carry) {
                    ans |= (1 << i);
                    carry = false;
                }
            }
            a >>= 1;
            b >>= 1;
        }
        
        return ans;
    }
};
