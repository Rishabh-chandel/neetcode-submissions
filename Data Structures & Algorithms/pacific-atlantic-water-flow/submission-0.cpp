class Solution {
private:
    int n , m;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>& arr,vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for(auto [dr,dc] : dir) {
            int nr = r+dr , nc = c+dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && arr[nr][nc] >= arr[r][c]) {
                dfs(nr,nc,arr,vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>> visP(n,vector<int>(m,0));
        vector<vector<int>> visA(n,vector<int>(m,0));
        for(int i=0;i<m;i++) {
            dfs(0,i,arr,visP);
            dfs(n-1,i,arr,visA);
        }
        for(int i=0;i<n;i++) {
            dfs(i,0,arr,visP);
            dfs(i,m-1,arr,visA);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(visA[i][j] && visP[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
