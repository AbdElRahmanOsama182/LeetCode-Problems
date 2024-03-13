
    class Solution {
        public int[][] merge(int[][] intervals) {
            int n = intervals.length;
            Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
            ArrayList<int[]> ans = new ArrayList<>();
            ans.add(intervals[0]);
            for (int i = 1; i < n; i++) {
                if (ans.get(ans.size() - 1)[1] >= intervals[i][0]) {
                    ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], intervals[i][1]);
                } else {
                    ans.add(intervals[i]);
                }
            }
            return ans.toArray(new int[ans.size()][2]);
        }
    }
    