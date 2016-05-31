public class Solution {
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    public String minWindow(String source, String target) {
        int[] cnt = new int[300];
        int[] need = new int[300];

        if (source == null || target == null ||  target.equals(""))
            return "";

        int all = 0;
        for (int i = 0; i < target.length(); ++i) {
            ++need[(int) target.charAt(i)];
            if (need[(int) target.charAt(i)] == 1)
                ++all;
        }

        String ret = "";
        int start = 0, minLen = Integer.MAX_VALUE;
        int rem = 0;
        for (int i = 0; i < source.length(); ++i) {
            char u = source.charAt(i);
            ++cnt[(int) u];
            if (cnt[(int) u] == need[(int) u]) {
                ++rem;
            }
            if (rem == all) {
                while (rem == all) {
                    int k = (int) source.charAt(start);
                    if (--cnt[k] < need[k])
                        --rem;
                    ++start;
                }
                if (i - start < minLen) {
                    minLen = i - start;
                    ret = source.substring(start - 1, i + 1);
                }
            }

        }
        return ret;
    }
}
