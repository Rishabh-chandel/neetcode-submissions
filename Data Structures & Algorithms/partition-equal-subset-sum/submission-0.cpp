class Solution {
private:    
    bool f(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp) {
        if(sum == 0) return 1;
        if(idx < 0 || sum < 0) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int nottake = f(idx-1,sum,arr,dp);
        int take = f(idx-1,sum-arr[idx],arr,dp);
        return dp[idx][sum] = take || nottake;
    }
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sumi = accumulate(arr.begin(), arr.end(), 0);
        if(sumi%2) return 0;
        int k = sumi/2;
        vector<vector<int>> dp(n+1, vector<int>(k + 1, -1));
        return f(n-1,k,arr,dp);
    }
};
