class Solution {
private:
    int f(int idx,vector<int>& arr,vector<int>& dp) {
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = arr[idx] + f(idx-2,arr,dp);
        int nottake = f(idx-1,arr,dp);
        return dp[idx] = max(take,nottake);
    }
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(n-1,arr,dp);
    }
};
