class Solution {
private:
    int n;
    int f(int idx,int buy,vector<int>& arr,vector<vector<int>>& dp) {
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int take = 0 , nottake = 0;
        if(buy == 1) {
            take = -arr[idx] + f(idx+1,0,arr,dp);
            nottake = f(idx+1,1,arr,dp);
        }
        else {
            take = arr[idx] + f(idx+2,1,arr,dp);
            nottake = f(idx+1,0,arr,dp);
        }
        return dp[idx][buy] = max(take,nottake);
    }
public:
    int maxProfit(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        return f(0,1,arr,dp);
    }
};
