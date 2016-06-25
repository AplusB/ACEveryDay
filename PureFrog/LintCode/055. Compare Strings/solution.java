public class Solution {
    /**
     * @param A : A string includes Upper Case letters
     * @param B : A string includes Upper Case letter
     * @return :  if string A contains all of the characters in B return true else return false
     */
    public boolean compareStrings(String A, String B) {
        if (A.length() < B.length())
            return false;

        int[] cnt = new int[30];

        for (int i = 0; i < A.length(); ++i) {
            ++cnt[A.charAt(i) - 'A'];
        }

        for (int i = 0; i < B.length(); ++i) {
            --cnt[B.charAt(i) - 'A'];
        }

        for (int i = 0; i < 26; ++i) if (cnt[i] < 0)
            return false;

        return true;
    }
}
