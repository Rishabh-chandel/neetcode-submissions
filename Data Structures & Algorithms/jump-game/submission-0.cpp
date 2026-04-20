class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        for(int i=0;i<n;i++) {
            if(i > maxi) return 0;
            maxi = max(maxi,i+arr[i]);
        }
        return 1;
        
    }
};
