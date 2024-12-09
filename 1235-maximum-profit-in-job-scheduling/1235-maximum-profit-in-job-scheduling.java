class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        Activity[] activities = new Activity[n];
        for (int i = 0; i < n; i++) {
            activities[i] = new Activity(startTime[i], endTime[i], profit[i]);
        }
        Arrays.sort(activities, Activity::compare);
        return weightedActivitySelection(activities);
    }
    public static int weightedActivitySelection(Activity[] activities) {
        int n = activities.length;
        int[] dp = new int[n];
        dp[0] = activities[0].weight;
        for (int i = 1; i < n; i++) {
            dp[i] = activities[i].weight;
            int last = getLast(activities, i);
            if (last != -1)
                dp[i] += dp[last];
            dp[i] = Math.max(dp[i], dp[i - 1]);
        }
        return dp[n - 1];
    }

    public static int getLast(Activity[] activities, int i) {
        int l = 0, r = i - 1, mid, last = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (activities[mid].finish <= activities[i].start) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return last;
    }
    class Activity {
    public int start;
    public int finish;
    public int weight;

    public Activity() {
        this.start = 0;
        this.finish = 0;
        this.weight = 0;
    }
    public Activity(int start, int finish, int weight) {
        this.start = start;
        this.finish = finish;
        this.weight = weight;
    }

    // compare two activities based on their finish time
    public static int compare(Activity a1, Activity a2) {
        return a1.finish - a2.finish;
    }
}
}