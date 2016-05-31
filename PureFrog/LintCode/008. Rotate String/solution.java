public class Solution {
    /**
     * @param str: an array of char
     * @param offset: an integer
     * @return: nothing
     */

    char[] str;
    public void rotateString(char[] str, int offset) {
        // write your code here
        if (offset == 0 || str.length == 0)
            return;
        offset %= str.length;
        int len = str.length;
        if (offset < 0)
            offset = len + offset;

        this.str = str;
        reverse(len - offset, len - 1);
        reverse(0, len - offset - 1);
        reverse(0, len - 1);
    }

    private void reverse(int l, int r) {
        int left = l, right = r;
        while (left < right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            ++left; --right;
        }
    }
}
