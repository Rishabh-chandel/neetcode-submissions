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
        vector<vector<int>> dp(n,vector<int>(amt+1,0));
        for(int i=0;i<=amt;i++) {
            if(i%arr[0] == 0) dp[0][i] = i/arr[0];
            else dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<=amt;j++) {
                int take = 1e9;
                if(j >= arr[i]) take = 1 + dp[i][j-arr[i]];
                int nottake = dp[i-1][j];
                dp[i][j] = min(take,nottake);
            }
        }
        if(dp[n-1][amt] >= 1e9) return -1;
        return dp[n-1][amt];
    }
};
