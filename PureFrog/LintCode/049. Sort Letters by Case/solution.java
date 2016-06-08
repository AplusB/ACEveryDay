public class Solution {
    /** 
     *@param chars: The letter array you should sort by Case
     *@return: void
     */
    public void sortLetters(char[] chars) {
        int pos = chars.length - 1;
        for (int i = 0; i < chars.length && i < pos; ++i) if (Character.isUpperCase(chars[i])) {
            while (pos >= i && Character.isUpperCase(chars[pos]))
                --pos;
            if (pos < i)
                break;
            char temp = chars[i];
            chars[i] = chars[pos];
            chars[pos] = temp;
        }
    }
}

`
