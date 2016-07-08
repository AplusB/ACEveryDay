public class Solution {
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    public boolean isMatch(String s, String p) {
        if (s == null || p == null)
            return false;

        boolean occur = false;
        int pos1 = 0, pos2 = 0;
        int sStartPos = 0, pStartPos = 0;

        while (pos1 != s.length()) {
            if (pos2 < p.length() && p.charAt(pos2) == '?') {
                ++pos1; ++pos2;
            }
            else if (pos2 < p.length() && p.charAt(pos2) == '*') {
                while (pos2 < p.length() && p.charAt(pos2) == '*') 
                    ++pos2;
                pStartPos = pos2;
                sStartPos = pos1;
                occur = true;
            }
            else {
                if (pos2 < p.length() && p.charAt(pos2) == s.charAt(pos1)) {
                    ++pos1; ++pos2;
                }
                else {
                    if (occur) {
                        pos1 = ++sStartPos;
                        pos2 = pStartPos;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        while (pos2 < p.length() && p.charAt(pos2) == '*')
            ++pos2;
        return pos1 == s.length() && pos2 == p.length();
     }
}
