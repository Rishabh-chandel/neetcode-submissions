class Solution {
private:
    int n;
    int f(int idx,int prev,vector<int>& arr,vector<vector<int>>& dp) {
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int nottake = f(idx+1,prev,arr,dp);
        int take = 0;
        if(prev == -1 || arr[idx] > arr[prev]) 
            take = 1 + f(idx+1,idx,arr,dp);
        return dp[idx][prev+1] = max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //return f(0,-1,arr,dp);
        for(int idx=n-1;idx>=0;idx--) {
            for(int prev=idx-1;prev>=-1;prev--) {
                int nottake = dp[idx+1][prev+1];
                int take = 0;
                if(prev == -1 || arr[idx] > arr[prev]) 
                    take = 1 + dp[idx+1][idx+1];
                dp[idx][prev+1] = max(take,nottake);
            }
        }
        return dp[0][0];
    }
};
