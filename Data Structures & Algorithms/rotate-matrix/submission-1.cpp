class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans[j][n-1-i] = arr[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j] = ans[i][j];
            }
        }
    }
};
