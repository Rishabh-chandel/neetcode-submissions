class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0 , j = n-1;
        while(i <= j) {
            int mid = (i+j)/2;
            if(arr[mid] >= k) j = mid-1;
            else i = mid+1;
        }
        if(i < n && arr[i] == k) return i;
        return -1;
    }
};
