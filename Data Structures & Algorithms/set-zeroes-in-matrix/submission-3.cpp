class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size() , n = arr[0].size();
        vector<int> row(n,0) , col(m,0); 
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j] == 0) {
                    row[j] = 1;
                    col[i] = 1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(row[i]) {
                for(int j=0;j<m;j++) {
                    arr[j][i] = 0;
                }
            }
        }
        for(int i=0;i<m;i++) {
            if(col[i]) {
                for(int j=0;j<n;j++) {
                    arr[i][j] = 0;
                }
            }
        }
    }
};
