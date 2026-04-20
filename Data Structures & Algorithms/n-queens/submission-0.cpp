class Solution {
private:
    vector<vector<string>> ans;
    bool isSafe(int row,int col,int n,vector<string>& curr) {
        int r = row , c = col;
        while(r >= 0 && c >= 0) {
            if(curr[r][c] == 'Q') return false;
            r-- , c--;
        }
        r = row , c = col;
        while(c >= 0) {
            if(curr[r][c] == 'Q') return false;
            c--;
        }
        r = row , c = col;
        while(r < n) {
            if(curr[r][c] == 'Q') return false;
            r++ , c--;
        }
        return true;
    }
    void solve(int col,int n,vector<string>& curr) {
        if(col == n) {
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++) {
            if(isSafe(row,col,n,curr)) {
                curr[row][col] = 'Q';
                solve(col+1,n,curr);
                curr[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n,string(n,'.'));
        solve(0,n,curr);
        return ans;
    }
};
