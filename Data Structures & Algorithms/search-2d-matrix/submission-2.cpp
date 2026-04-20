class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int m = arr.size() , n = arr[0].size();
        int low = 0 , high = (n*m)-1;
        while(low <= high) {
            int mid = (low+high)/2;
            int r = mid/n , c = mid%n;
            if(arr[r][c] == k) return 1;
            else if(arr[r][c] >= k) high = mid-1;
            else low = mid+1;
        }
        return 0;
    }
};
