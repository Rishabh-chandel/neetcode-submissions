class Solution {
private:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n , m;
    int cnt ;
    void dfs(int u,int v,vector<vector<int>>& arr,vector<vector<int>>& vis) {
        vis[u][v] = 1;
        cnt++;
        for(auto [dr,dc] : dir) {
            int nr = u+dr , nc = v+dc;
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && arr[nr][nc] == 1) 
                dfs(nr,nc,arr,vis);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && arr[i][j] == 1) {
                    cnt = 0;
                    dfs(i,j,arr,vis);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
