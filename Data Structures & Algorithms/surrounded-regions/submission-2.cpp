class Solution {
private:    
    int n , m;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,vector<vector<char>>& arr,vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for(auto [dr,dc] : dir) {
            int nr = r+dr ;
            int nc = c+dc;
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && arr[nr][nc] == 'O') {
                dfs(nr,nc,arr,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& arr) {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++) {
            if(arr[0][i] == 'O') dfs(0,i,arr,vis);
            if(arr[n-1][i] == 'O') dfs(n-1,i,arr,vis);
        }
        for(int i=0;i<n;i++) {
            if(arr[i][0] == 'O') dfs(i,0,arr,vis);
            if(arr[i][m-1] == 'O') dfs(i,m-1,arr,vis);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && arr[i][j] == 'O') arr[i][j] = 'X';
            }
        }
    }
};
