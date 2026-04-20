class Solution {
private:
    int f(int idx,vector<int>& arr,vector<int>& dp) {
        if(idx >= arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int one = arr[idx] + f(idx+1,arr,dp);
        int two = arr[idx] + f(idx+2,arr,dp);
        return dp[idx] = min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return min(f(0,arr,dp),f(1,arr,dp));
    }
};
