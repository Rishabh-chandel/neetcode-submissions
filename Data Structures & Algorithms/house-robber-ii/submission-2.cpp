class Solution {
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
        for(int i=0;i<n-1;i++) {
            int take = arr1[i];
            if(i-2 >= 0) take += dp1[i-2];
            int nottake = 0;
            if(i-1 >= 0) nottake += dp1[i-1];
            dp1[i] = max(take,nottake);
        }
        for(int i=0;i<n-1;i++) {
            int take = arr2[i];
            if(i-2 >= 0) take += dp2[i-2];
            int nottake = 0;
            if(i-1 >= 0) nottake += dp2[i-1];
            dp2[i] = max(take,nottake);
        }
        return max(dp1[n-2],dp2[n-2]);
    }
};
