class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int i = 0 , j = n-1;
        int lmax = 0 , rmax = 0;
        int ans = 0;
        while(i <= j) {
            if(arr[i] <= arr[j]) {
                if(lmax > arr[i]) ans += (lmax-arr[i]);
                lmax = max(lmax,arr[i]);
                i++;
            }
            else {
                if(rmax > arr[j]) ans += (rmax-arr[j]);
                rmax = max(rmax,arr[j]);
                j--;
            }
        }
        return ans;
    }
};
