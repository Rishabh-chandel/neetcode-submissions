class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int tot = 0;
        int maxi = arr[0], currmax = 0;
        int mini = arr[0], currmin = 0;

        for(int num : arr) {
            tot += num;

            currmax = max(num, currmax + num);
            maxi = max(maxi, currmax);

            currmin = min(num, currmin + num);
            mini = min(mini, currmin);
        }

        if(maxi < 0) return maxi;

        return max(maxi, tot - mini);
    }
};