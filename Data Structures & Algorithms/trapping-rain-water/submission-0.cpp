class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n,0) , suf(n,0);
        pse[0] = arr[0] , suf[n-1] = arr[n-1];
        for(int i=1;i<n;i++) {
            pse[i] = max(pse[i-1],arr[i]);
            suf[n-i-1] = max(suf[n-i],arr[n-i-1]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            ans += (min(pse[i],suf[i])-arr[i]);
        }
        return ans;
    }
};
