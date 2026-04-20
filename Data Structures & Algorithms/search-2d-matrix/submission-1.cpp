class Solution {
private:
    bool s_row(vector<int>& arr,int k) {
        int n = arr.size();
        int st = 0 , ed = n-1;
        while(st <= ed) {
            int mid = (st+ed)/2;
            if(arr[mid] == k) return 1;
            else if(arr[mid] >= k) ed = mid-1;
            else st = mid+1;
        }
        return 0;
    }
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int m = arr.size();
        int top = 0 , bottom = m-1;
        while(top <= bottom) {
            int mid = (top+bottom)/2;
            if(s_row(arr[mid],k)) return 1;
            else if(arr[mid][0] >= k) bottom = mid-1;
            else top = mid+1;
        }
        return 0;
    }
};
