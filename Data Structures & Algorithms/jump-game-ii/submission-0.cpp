class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        int jumps = 0;
        int l = 0 , r = 0;
        while(r < n-1) {
            int maxi = 0;
            for(int idx=l;idx<=r;idx++) 
                maxi = max(maxi,idx+arr[idx]);
            jumps += 1;
            l = r+1;
            r = maxi;
        }
        return jumps;
    }
};
