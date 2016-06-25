public class Solution {
    /**
     * @param str: A string
     * @return An integer
     */
    public int atoi(String str) {
        if (str == null)
            return 0;

        int pos = 0, sign = 1;
        while (pos < str.length() && Character.isSpaceChar(str.charAt(pos)))
            ++pos;
        if (pos == str.length())    //全是空格
            return 0;

        //第一个数可能是'+'和'-'
        if (str.charAt(pos) == '-') {
            sign = -1;
            ++pos;
        }
        if (str.charAt(pos) == '+')
            ++pos;
        //可能只有正负号
        if (pos == str.length())
            return 0;

        long ans = 0;
        while (pos < str.length()) {
            char c = str.charAt(pos);
            //可以出现一次'.'
            if (c == '.') {
                return (int) ans*sign;
            }
            else if (Character.isSpaceChar(c)) {  //如果是空格
                return (int) ans*sign;
            }
            else if (!Character.isDigit(c)) {   //除了点和空格之外不允许出现其他非数字字符
                return (int) ans*sign;
            }
            else {
                ans = ans*10 + (c - '0');
                if (sign == 1 && ans >= Integer.MAX_VALUE)
                    return Integer.MAX_VALUE;
                if (sign == -1 && ans > Integer.MAX_VALUE)
                    return Integer.MAX_VALUE + 1;
            }
            ++pos;
        }
        return (int) ans*sign;
    }
}
