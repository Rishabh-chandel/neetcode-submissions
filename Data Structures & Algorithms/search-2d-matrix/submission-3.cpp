class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int m = arr.size() , n = arr[0].size();
        int low = 0 , high = n-1;
        while(low < m && high >= 0) {
            if(arr[low][high] == k) return 1;
            else if(arr[low][high] > k) high--;
            else low++;
        }
        return 0;
    }
};
