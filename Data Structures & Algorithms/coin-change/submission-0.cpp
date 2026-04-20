class Solution {
private:    
    int f(int idx,int amt,vector<int>& arr,vector<vector<int>>& dp) {
        if(idx == 0) {
            if(amt%arr[0] == 0) return amt/arr[0];
            return 1e9;
        }
        if(dp[idx][amt] != -1) return dp[idx][amt];
        int take = 1e9;
        if(amt >= arr[idx]) take = 1 + f(idx,amt-arr[idx],arr,dp);
        int nottake = f(idx-1,amt,arr,dp);
        return dp[idx][amt] = min(take,nottake);
    }
public:
    int coinChange(vector<int>& arr, int amt) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        int ans = f(n-1,amt,arr,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
