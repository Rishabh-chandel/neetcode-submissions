class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1e9; 
        int pre = 1 , suf = 1;
        for(int i=0;i<n;i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= arr[i];
            suf *= arr[n-i-1];
            maxi = max(maxi,max(pre,suf));
        }
        return maxi;
    }
};
