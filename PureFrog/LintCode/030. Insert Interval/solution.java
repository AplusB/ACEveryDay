/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */

class Solution {
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: A new interval.
     * @return: A new sorted interval list.
     */
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> result = new ArrayList<Interval>();
        if (newInterval == null)
            return intervals;
        int l = newInterval.start, r = newInterval.end;

        for (Interval i: intervals) {
            //先排除不在区间内的
            if (i.end < l)
                result.add(i);
            else if (i.start > r) {
                if (l <= r) {
                    result.add(new Interval(l, r));
                    l = r + 1;
                }
                result.add(i);
            }
            else {
                l = Math.min(l, i.start);
                r = Math.max(r, i.end);
            }
        }
        if (l <= r)
            result.add(new Interval(l, r));
        return result;
    }
}
