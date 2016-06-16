class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while ((a & b) != 0) {
            int v1 = (a & b); v1 <<= 1;
            int v2 = (a ^ b);
            
            a = v1; b = v2;
        }
        
        return (a ^ b);
    }
};
