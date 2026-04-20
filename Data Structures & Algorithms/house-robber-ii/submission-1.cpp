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
        if(n == 1) return arr[0];
        vector<int> arr1 , arr2;
        vector<int> dp1(n-1,-1) , dp2(n-1,-1);
        for(int i=0;i<n;i++) {
            if(i != 0) arr1.push_back(arr[i]);
            if(i != n-1) arr2.push_back(arr[i]);
        }
        return max(f(n-2,arr1,dp1),f(n-2,arr2,dp2));
    }
};
