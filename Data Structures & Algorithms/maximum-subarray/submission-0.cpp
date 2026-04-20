class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1e9 , sum = 0;
        for(int it : arr) {
            if(sum < 0) sum = 0;
            sum+=it;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
